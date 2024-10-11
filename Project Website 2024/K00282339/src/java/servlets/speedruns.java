/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package servlets;

import java.sql.*;
import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.Statement;

/**
 *
 * @author zacht
 */
public class speedruns extends HttpServlet {
    
    //Global Variables
    Connection conn;
    PreparedStatement prepStat;
    Statement stat;


    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    
    @Override
          public void init() throws ServletException {
        String url = "jdbc:mysql://localhost:3306/";
        String dbName = "appdev";
        String userName = "root";
        String password = "";
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = (Connection) DriverManager.getConnection(url + dbName, userName, password);
            stat = (Statement) conn.createStatement();
            System.out.println("Connected");
            
            //Creating the table
            String sqlCreate = "CREATE TABLE IF NOT EXISTS speedrunsData (" +
                   "`formNumber` INT AUTO_INCREMENT PRIMARY KEY, " +
                   "`map` CHAR(40), `gamertag` CHAR(40), `time` CHAR(40), " +
                   "`date` CHAR(40), `platform` CHAR(40));";

            stat.executeUpdate(sqlCreate);
            System.out.println("After table create");
        } catch (Exception e) {
            System.err.println(e);
        }
    } // end of init() method

    
    
    
            protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");

        //Requesting values for each variable in the form
        String map = request.getParameter("map");
        String gamertag = request.getParameter("gamertag");
        String time = request.getParameter("time");
        String date = request.getParameter("date");
        String platform = request.getParameter("platform");
        

        
        try {
            //String query = "INSERT INTO speedrunsData VALUES (?,?,?,?,?,?,?,?,?)";
            //A String variable that will hold the sql code to insert values
            String query = "INSERT INTO speedrunsData (map, gamertag, time, date, platform) VALUES (?, ?, ?, ?, ?)";
            prepStat = (PreparedStatement) conn.prepareStatement(query);
            
            prepStat.setString(1, map);
            prepStat.setString(2, gamertag);
            prepStat.setString(3, time);
            prepStat.setString(4, date);
            prepStat.setString(5, platform);
            
            prepStat.executeUpdate();
            System.out.println("After insert");
            try ( PrintWriter out = response.getWriter()) {
                out.println("<!DOCTYPE html>");
                out.println("<html>");
                out.println("<head>");
                out.println("<title>Servlet speedruns</title>");
                out.println("</head>");
                out.println("<body>");
                out.println("<br><br><br><h1>Data inserted successfully</h1>");
			out.println("<br> <br> <br> <a href=\"index.html\">Home</a>");
                out.println("</body>");
                out.println("</html>");
            }

        } catch (Exception e) {
            System.err.println(e);
            try ( PrintWriter out = response.getWriter()) {
                out.println("<!DOCTYPE html>");
                out.println("<html>");
                out.println("<head>");
                out.println("<title>Servlet speedruns</title>");
                out.println("</head>");
                out.println("<body>");
                out.println("<br><br><br><h1>Error on insert</h1>");
 			out.println("<br> <br> <br> <a href=\"index.html\">Home</a>");
                out.println("</body>");
                out.println("</html>");
            }
        }

    }
        //This function will update the form from newly inputted values using
            //form number that is given upon submission of a form
        private void updateForm(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int formNumber = Integer.parseInt(request.getParameter("formNumber"));
        String map = request.getParameter("map");
        String gamertag = request.getParameter("gamertag");
        String time = request.getParameter("time");
        String date = request.getParameter("date");
        String platform = request.getParameter("platform");
        
        
        //Setting the values of the previous inputted data
        String sql = "UPDATE speedrunsData SET map=?, gamertag=?, time=?, date=?, platform=? WHERE formNumber=?";
        try (PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setString(1, map);
            pstmt.setString(2, gamertag);
            pstmt.setString(3, time);
            pstmt.setString(4, date);
            pstmt.setString(5, platform);
            pstmt.setInt(6, formNumber);
            int result = pstmt.executeUpdate();
            //Sending the user to either a success or a fail page
            if (result > 0) {
                response.sendRedirect("formSuccess.html"); // Form made Successfully
            } else {
                response.sendRedirect("formError.html"); // There was an error mkaing the Form
            }
        } catch (SQLException e) {
            e.printStackTrace();
            response.sendRedirect("formError.html"); // Error page
        }
    }
            //This function will send the user to a page which will show
        //a submitted form based on their form's number
            private void viewForm(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        
        PrintWriter out = response.getWriter();
        try {
            String sql = "SELECT * FROM speedrunsData WHERE formNumber = ?";
            PreparedStatement pstmt = conn.prepareStatement(sql);
            //Request for the form's number
            pstmt.setInt(1, Integer.parseInt(request.getParameter("formNumber")));
            ResultSet rs = pstmt.executeQuery();
            String title = "Form Details";
            out.println("<html>\n<head><title>" + title + "</title></head>\n<body>\n<h1 align=\"center\">" + title + "</h1>\n");
            if (rs.next()) {
                out.println("<p>Map: " + rs.getString("map") + "</p>");
                out.println("<p>GamerTag: " + rs.getString("gamertag") + "</p>");
                out.println("<p>Time: " + rs.getString("time") + "</p>");
                out.println("<p>Date: " + rs.getString("date") + "</p>");
                out.println("<p>Platform: " + rs.getString("platform") + "</p>");
                out.println("<p>Form Number: " + rs.getString("formNumber") + "</p>");
            } else {
                out.println("<p>No Form found with Number: " + request.getParameter("formNumber") + "</p>");
            }
            out.println("</body></html>");
        } catch (SQLException e) {
            out.println("<p>Error: " + e.getMessage() + "</p>");
            e.printStackTrace();
        }
    }
            //Function to delete a form using its related form number
    private void deleteForm(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //Retrieve a forms ascociated number
        int formNumber = Integer.parseInt(request.getParameter("formNumber"));
        String sql = "DELETE FROM speedrunsData WHERE formNumber = ?";
        try (PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setInt(1, formNumber);
            int result = pstmt.executeUpdate();
            if (result > 0) {
                response.sendRedirect("formSuccess.html");
            } else {
                response.sendRedirect("formError.html");
            }
        } catch (SQLException e) {
            e.printStackTrace();
            response.sendRedirect("formError.html");
        }
    }


    
            
            



    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
     @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String action = request.getParameter("action");
        if (action == null) {
            action = "list";  // default action
        }
        //Calls a method according to which button was pressed
        switch (action) {
            case "submit":
                processRequest(request, response);
                break;
            case "update":
                updateForm(request, response);
                break;
            case "delete":
                deleteForm(request, response);
                break;
            case "view":
                viewForm(request, response);
                break;
            default:
                response.sendRedirect("index.html");
                break;
        }
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
