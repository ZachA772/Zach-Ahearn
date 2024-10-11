import java.awt.*;
import java.awt.Dimension;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.awt.Image;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;

public class CompetitionFrame extends JFrame
{
	
	public static void main(String[] args)
	{
		JFrame frame = new CompetitionFrame();
		frame.setTitle("CHASE THE ACE COMPETITON");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		
	}
	
	private JLabel lblTitle;
	private JLabel lblRules;
	private JButton btnRules;
	private JButton btnSchoolEnter;
	private JButton btnGroupEnter;
	private JButton btnSchoolWithdraw;
	private JLabel lblVoucher;
	private JButton btnVoucher;
	private JTextField TFVoucher;
	private JLabel lblSchoolTotalPrice;
	private JLabel lblLocation;
	private JLabel lblEntries;
	private JLabel lblYourGroupEntries;
	private JLabel lblGroupEntries;
	private JLabel entryTotal;
	private JLabel imageLabel;
	
	private double balance;
	private int schoolCount = 10;
	private int groupCount = 35;
	private int count;
	private int countRules = 0;
	
	private JButton btnExit;
	
	private JPanel panel;
	private static final int FRAME_WIDTH = 1000;
	private static final int FRAME_HEIGHT = 900;
	
		
	public CompetitionFrame() //------------------------------------------------------------------------
	{
		lblSchoolTotalPrice = new JLabel("Total Price owed by your school: 0");
		lblEntries = new JLabel("Number of schools entered: 10");
		lblYourGroupEntries = new JLabel("Number of groups entered from your school: 0");
		lblGroupEntries = new JLabel("Number of groups entered overall: 35");
		lblRules = new JLabel("Please Click to see Rules");
		lblRules.setVisible(false);
		imageLabel = new JLabel();
		
		ImageIcon icon = new ImageIcon("logo.jpg");
		Image img = icon.getImage().getScaledInstance(400, 176, Image.SCALE_SMOOTH);
		imageLabel.setIcon(new ImageIcon(img));
		imageLabel.setPreferredSize(new Dimension(200, 200));
		imageLabel.setBounds(100, 100, 200, 200);
    
		createComponents();
		createTextField();
		createEnterSchoolButton();
		createEnterGroupButton();
		createWithdrawButton();
		createRulesButton();
		createVoucherButton();
		createPanel();
		Color bgColor = Color.decode("#D4F5FF");
		panel.setBackground(bgColor);
		setSize(FRAME_WIDTH, FRAME_HEIGHT);
		
		
       
        
        // Add the image label to the panel
       
    
		
		
		
	}//------------------------------------------------------------------------------------------------VOUCHER
	
	private void createTextField()
	{
		lblVoucher = new JLabel("Have a voucher code? Enter it here!:");
		
		
		TFVoucher = new JTextField();
		TFVoucher.setText("");
		TFVoucher.setEditable(true);
	}
	class AddVoucherListener implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			if (!TFVoucher.getText().isEmpty())
			{
			double voucherCode = balance * 0.1;
			balance = balance - voucherCode;
			TFVoucher.setText("Code Enter Successfully! 10% Discount Applied");
			lblSchoolTotalPrice.setText("Total Price owed by your school: " + balance);
			btnVoucher.setEnabled(false);
			}
		}	
	}

	private void createVoucherButton()
	{
		btnVoucher = new JButton("Apply Voucher");
		
		ActionListener listener = new AddVoucherListener();
		btnVoucher.addActionListener(listener);
	}//------------------------------------------------------------------------------------------------VOUCHER
	
	class AddSchoolListener implements ActionListener //------------------------------------------------ENTER SCHOOL
	{
		public void actionPerformed(ActionEvent event)
		{
			
			schoolCount = schoolCount + 1;
			balance = balance + 20;
			lblSchoolTotalPrice.setText("Total Price owed by your school: " + balance);
			lblEntries.setText("Number of schools entered: " + schoolCount);
			btnSchoolEnter.setEnabled(false);
			btnGroupEnter.setEnabled(true);
			btnSchoolWithdraw.setEnabled(true);
			
		}
	}
	
	private void createEnterSchoolButton()
	{
		btnSchoolEnter = new JButton("Click here to Register your school");
		btnSchoolEnter.setBackground(Color.ORANGE);
		
		ActionListener listener = new AddSchoolListener();
		btnSchoolEnter.addActionListener(listener);
		
	}//--------------------------------------------------------------------------------------------------ENTER SCHOOL
	
	class AddGroupListener implements ActionListener //------------------------------------------------ENTER GROUP
	{
		public void actionPerformed(ActionEvent event)
		{
			count++;
			
			if(count == 1){
				groupCount = groupCount + 1;
				lblYourGroupEntries.setText("Number of groups entered from your school: " + count);
				lblGroupEntries.setText("Number of groups entered overall: " + groupCount);
			}
			else if(count >= 2){
				groupCount = groupCount + 1;
				balance = balance + 5;
				lblSchoolTotalPrice.setText("Total Price owed by your school: " + balance);
				lblYourGroupEntries.setText("Number of groups entered from your school: " + count);
				lblGroupEntries.setText("Number of groups entered overall: " + groupCount);
			}
		}
	}
	
	private void createEnterGroupButton()
	{
		btnGroupEnter = new JButton("Click here to enter a group");
		btnGroupEnter.setBackground(Color.ORANGE);
		btnGroupEnter.setEnabled(false);
		
		ActionListener listener = new AddGroupListener();
		btnGroupEnter.addActionListener(listener);
		
	}//--------------------------------------------------------------------------------------------------ENTER GROUP
	
	class AddWithdrawListener implements ActionListener //------------------------------------------------WITHDRAW SCHOOL
	{
		public void actionPerformed(ActionEvent event)
		{
			
			schoolCount = schoolCount - 1;
			balance = 0;
			groupCount = groupCount - count;
			count = 0;
			lblSchoolTotalPrice.setText("Total Price owed by your school: " + balance);
			lblEntries.setText("Number of schools entered: " + schoolCount);
			lblYourGroupEntries.setText("Number of groups entered from your school: " + count);
			lblGroupEntries.setText("Number of groups entered overall: " + groupCount);
			TFVoucher.setText("");
			btnSchoolEnter.setEnabled(true);
			btnGroupEnter.setEnabled(false);
			btnSchoolWithdraw.setEnabled(false);
			btnVoucher.setEnabled(true);
			
		}
	}
	
	private void createWithdrawButton()
	{
		btnSchoolWithdraw = new JButton("Click here to withdraw a competition entry");
		btnSchoolWithdraw.setBackground(Color.ORANGE);
		btnSchoolWithdraw.setEnabled(false);
		
		
		ActionListener listener = new AddWithdrawListener();
		btnSchoolWithdraw.addActionListener(listener);
		
	}//--------------------------------------------------------------------------------------------------WITHDRAW SCHOOL
	
	class AddRulesListener implements ActionListener //------------------------------------------------RULES
	{
		public void actionPerformed(ActionEvent event)
		{
			countRules++;
			if(countRules % 2 != 0)
			{
				lblRules.setVisible(true);
				lblRules.setText("<html>RULES OF THE GAME<br>The goal is to have the highest value card, the person with the lowest value loses.<br>2. Each Player has 3 lives, lives are lost upon round loss, game ends once all lives are depleted.<br>3. Each player is dealt 1 card and can look at their own card.<br>4. The first player to start is whoever comes after the dealer.<br>5. The player's turn has a choice to stay with their own card, or blindly swap with the next person.<br>6. This continues with every player until it is the dealer's turn, where the dealers can stick with their card, or blindly swaps with the deck.<br>7. All players card are revealed at the end of the round, the lowest card loses a life.<br>8. The Ace is the main card wanted as it has the highest value and trumps all other cards.<br>9. If 2 players have the same card value, 'red' cards like Diamonds and Hearts take priority and beat 'black' cards.<br>RULES OF THE COMPETITION<br>The price of entry per school is €20.00. There is an additional charge of €5.00 per group per school. The first group is free.<br>School may also choose to withdraw from the competition at any time.");
			}
			else{
				lblRules.setVisible(false);
				}
			
			
		}
	}
	
	private void createRulesButton()
	{
		btnRules = new JButton("Rules");
		btnRules.setBackground(Color.GREEN);
		
		
		
		ActionListener listener = new AddRulesListener();
		btnRules.addActionListener(listener);
		
	}//----------------------------------------------------------------------------------------------RULES
	
	
	
    
	
	private void createComponents()
{
    panel = new JPanel();
    panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
	
    
    lblTitle = new JLabel("!!Welcome To 'CHASE THE ACE COMPETITION 2023!!");
    lblTitle.setFont(new Font("Arial", Font.BOLD, 24));
    lblTitle.setForeground(Color.BLUE);
    
    
	    
    lblLocation = new JLabel("The competition will take place at Thurles Institution Of Technology in the Sports Hall");
    
    lblLocation.setFont(new Font("Arial", Font.PLAIN, 14));
    
    
    btnExit = new JButton("Exit");
    btnExit.setBackground(Color.RED);
    
    
    
    ActionListener listenerExit = new ClickListenerExit();
    btnExit.addActionListener(listenerExit);
}
private void createPanel(){
	
	panel.add(imageLabel);
	panel.add(lblTitle);
	panel.add(btnRules);
	panel.add(lblRules);
	panel.add(lblLocation);
	panel.add(btnSchoolEnter);
	panel.add(btnGroupEnter);
	panel.add(btnSchoolWithdraw);
	panel.add(lblVoucher);
	panel.add(btnVoucher);
	panel.add(TFVoucher);
	panel.add(lblSchoolTotalPrice);
	panel.add(lblEntries);
	panel.add(lblYourGroupEntries);
	panel.add(lblGroupEntries);
	panel.add(btnExit);
	add(panel);
	}

}