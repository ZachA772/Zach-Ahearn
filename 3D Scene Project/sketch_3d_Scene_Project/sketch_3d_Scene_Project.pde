//ZACH AHEARN
//K00282339

import peasy.*;

PeasyCam cam;


//points
//STATIC PLAYER 1
float[] p1 = {-95.0,10.0,0.0,1.0}; //top left head
float[] p2 = {-75.0,10.0,0.0,1.0}; // top right head
float[] p3 = {-75.0,30.0,0.0,1.0};//bottom right head
float[] p4 = {-95.0,30.0,0.0,1.0}; // bottom left head
float[] p5 = {-115.0,30.0,0.0,1.0}; //top left-left arm
float[] p6 = {-115.0,40.0,0.0,1.0};//bottom left-left arm
float[] p7 = {-95.0,40.0,0.0,1.0};//bottom right-left arm
float[] p8 = {-95.0,50.0,0.0,1.0};//left waist
float[] p9 = {-95.0,80.0,0.0,1.0};//bottom left foot
float[] p10 = {-85.0,80.0,0.0,1.0};//bottom middle feet
float[] p11 = {-75.0,80.0,0.0,1.0};//bottom right foot
float[] p12 = {-75.0,50.0,0.0,1.0};//right waist
float[] p13 = {-75.0,40.0,0.0,1.0};//bottom left-right arm
float[] p14 = {-55.0,40.0,0.0,1.0};//bottom right-right arm
float[] p15 = {-55.0,30.0,0.0,1.0};//top right-right arm
float[] p16 = {-85.0,50.0,0.0,1.0};//middle waist

//STATIC PLAYER 2
float[] p17 = {-95.0,10.0,20.0,1.0}; //top left head
float[] p18 = {-75.0,10.0,20.0,1.0}; // top right head
float[] p19 = {-75.0,30.0,20.0,1.0};//bottom right head
float[] p20 = {-95.0,30.0,20.0,1.0}; // bottom left head
float[] p21 = {-115.0,30.0,20.0,1.0}; //top left-left arm
float[] p22 = {-115.0,40.0,20.0,1.0};//bottom left-left arm
float[] p23 = {-95.0,40.0,20.0,1.0};//bottom right-left arm
float[] p24 = {-95.0,50.0,20.0,1.0};//left waist
float[] p25 = {-95.0,80.0,20.0,1.0};//bottom left foot
float[] p26 = {-85.0,80.0,20.0,1.0};//bottom middle feet
float[] p27 = {-75.0,80.0,20.0,1.0};//bottom right foot
float[] p28 = {-75.0,50.0,20.0,1.0};//right waist
float[] p29 = {-75.0,40.0,20.0,1.0};//bottom left-right arm
float[] p30 = {-55.0,40.0,20.0,1.0};//bottom right-right arm
float[] p31 = {-55.0,30.0,20.0,1.0};//top right-right arm
float[] p32 = {-85.0,50.0,20.0,1.0};//middle waist

//==============================================================================================

//GUN 1
float[] p33 = {-15.0,60.0,0.0,1.0};//Top left
float[] p34 = {0.0,60.0,0.0,1.0};//Top right
float[] p35 = {0.0,65.0,0.0,1.0};//Barrel-bottom right
float[] p36 = {-10.0,65.0,0.0,1.0};//trigger
float[] p37 = {-10.0,75.0,0.0,1.0};//handle-bottom right
float[] p38 = {-15.0,75.0,0.0,1.0};//handle-bottom left

//GUN 2
float[] p39 = {-15.0,60.0,10.0,1.0};//Top left
float[] p40 = {0.0,60.0,10.0,1.0};//Top right
float[] p41 = {0.0,65.0,10.0,1.0};//Barrel-bottom right
float[] p42 = {-10.0,65.0,10.0,1.0};//trigger
float[] p43 = {-10.0,75.0,10.0,1.0};//handle-bottom right
float[] p44 = {-15.0,75.0,10.0,1.0};//handle-bottom left

//==================================================================================

//SIGN 1
float[] p45 = {45.0,30.0,0.0,1.0};//post-top left
float[] p46 = {55.0,30.0,0.0,1.0};//post-top right
float[] p47 = {55.0,80.0,0.0,1.0};//post-bottom right
float[] p48 = {45.0,80.0,0.0,1.0};//post-bottom left
float[] p49 = {30.0,40.0,0.0,1.0};//sign-top left
float[] p50 = {65.0,40.0,0.0,1.0};//sign-top right
float[] p51 = {75.0,45.0,0.0,1.0};//sign-point
float[] p52 = {65.0,50.0,0.0,1.0};//sign-bottom right
float[] p53 = {30.0,50.0,0.0,1.0};//sign-bottom left

//SIGN 2
float[] p54 = {45.0,30.0,10.0,1.0};//post-top left
float[] p55 = {55.0,30.0,10.0,1.0};//post-top right
float[] p56 = {55.0,80.0,10.0,1.0};//post-bottom right
float[] p57 = {45.0,80.0,10.0,1.0};//post-bottom left
float[] p58 = {30.0,40.0,10.0,1.0};//sign-top left
float[] p59 = {65.0,40.0,10.0,1.0};//sign-top right
float[] p60 = {75.0,45.0,10.0,1.0};//sign-point
float[] p61 = {65.0,50.0,10.0,1.0};//sign-bottom right
float[] p62 = {30.0,50.0,10.0,1.0};//sign-bottom left

//======================================================================

//ENEMY
float[] p63 = {95.0,60.0,0.0,1.0};//top left
float[] p64 = {115.0,60.0,0.0,1.0};//top right
float[] p65 = {115.0,80.0,0.0,1.0};//bottom right
float[] p66 = {95.0,80.0,0.0,1.0};//bottom left

//Left Eye
float[] p67 = {98.0,63.0,20.0,1.0};//top left
float[] p68 = {102.0,63.0,20.0,1.0};//top right
float[] p69 = {102.0,67.0,20.0,1.0};//bottom right
float[] p70 = {98.0,67.0,20.0,1.0};//bottom left
//Right Eye
float[] p71 = {108.0,63.0,20.0,1.0};//top left
float[] p72 = {112.0,63.0,20.0,1.0};//top right
float[] p73 = {112.0,67.0,20.0,1.0};//bottom right
float[] p74 = {108.0,67.0,20.0,1.0};//bottom left

//ENEMY 2 (JUST BODY)
float[] p75 = {95.0,60.0,20.0,1.0};//top left
float[] p76 = {115.0,60.0,20.0,1.0};//top right
float[] p77 = {115.0,80.0,20.0,1.0};//bottom right
float[] p78 = {95.0,80.0,20.0,1.0};//bottom left

//=======================================================================

// Transform Matrixes
 
//SCALING ENEMY------------------------------------------------------------------------------------------------------------------
float scaleX = 0.99;
float scaleY = 0.99;
float scaleZ = 0.99;
float[][] scalingMatrix = {{scaleX,0.0,0.0,0.0},{0.0,scaleY,0.0,0.0},{0.0,0.0,scaleZ,0.0},{0.0,0.0,0.0,1.0}}; // scale by 0.99

//TRANSLATING GUN----------------------------------------------------------------------------------------------------------------------------
int translateY = -2;

float[][] translateMatrix = {{1.0,0.0,0.0,0.0},{0.0,1.0,0.0,0.0},{0.0,0.0,1.0,0.0},{0,translateY,0,1.0}}; // translate by distance of -2
//---------------------------------------------------------------------------------------------------------------------------------------------

//ROTATING SIGN
float[][] translateToOrigin = {{1.0,0.0,0.0,0.0},{0.0,1.0,0.0,0.0},{0.0,0.0,1.0,0.0},{-50,-55,-5,1.0}}; // translate by certain distance
float[][] translateBackFromOrigin = {{1.0,0.0,0.0,0.0},{0.0,1.0,0.0,0.0},{0.0,0.0,1.0,0.0},{50,55,5,1.0}}; // translate by certain distance
 float theta = radians(10); // convert degrees to radians


float[][] rotYMatrix = {{cos(theta),0.0,-sin(theta),0.0,0.0},{0.0,1.0,0.0,0.0},{sin(theta),0.0,cos(theta),0.0},{0.0,0.0,0.0,1.0}}; // roatate around y axis
/*
float[][] rotXMatrix = {{1.0,0.0,0.0,0.0},{0.0,cos(theta),sin(theta),0.0},{0.0,-sin(theta),cos(theta),0.0},{0.0,0.0,0.0,1.0}}; // roatate around x axis
float[][] rotZmatrix= {{cos(theta),sin(theta),0.0,0.0},{-sin(theta),cos(theta),0.0,0.0},{0.0,0.0,1.0,0.0},{0.0,0.0,0.0,1.0}}; // roatate around z axis
*/

//Scaling Variables
float[][] m;
//-----------------
//Translate Variables
float[][] n;
//---------------
//Rotate Variables
float[][] z;
//-------------

void setup() 
{
  size(1920, 1055, P3D);
  
  cam = new PeasyCam(this, 300);
  cam.setMinimumDistance(200);
  cam.setMaximumDistance(500);
  

  smooth();



  
  loop();
  
  frameRate(20);
}

void draw() 
{
  // by commenting the background() call out, the background is not refreshed, so each transformation can be seen.
  //background(102);
    //TRANSLATING LOOP---------------------------
    if(p38[1] < 40)
    {
      translateY = 2;
    }
    else if(p38[1] > 80)
    {
      translateY = -2;
    }
    
    translateMatrix[3][1] = translateY;
  //-------------------------------------------
  if(p63[1] < 50)
    {
      scaleX += 0.0099;
      scaleY += 0.0099;
      scaleZ += 0.0099;
    }
    else if(p63[1] >= 80)
    {
      scaleX -= 0.0099;
      scaleY -= 0.0099;
      scaleZ -= 0.0099;
    }
    scalingMatrix[0][0] = scaleX;
    scalingMatrix[1][1] = scaleY;
    scalingMatrix[2][2] = scaleZ;
  
  
    m = scalingMatrix;
    n = translateMatrix;
    
    z = translateToOrigin;
    applyTransform();
    
    z = rotYMatrix;
    applyTransform();
    
    z =translateBackFromOrigin;
//    applyTransform();

//----------------------------
    applyTransform();
  //--------------------------
 


  
   fill(255);
   background(0);
  
  strokeWeight(5);
  //drawAxes();
   
  
  drawBox();


}



float[] transform_pointScale(float[][] m, float[] p)
{

   float[] p_new = {0.0,0.0,0.0,0.0}; // handle 4 elements as its 3D calc
   
   p_new[0] = m[0][0] * p[0] + m[1][0] * p[1] + m[2][0] * p[2] + m[3][0]*p[3];
   p_new[1] = m[0][1] * p[0] + m[1][1] * p[1] + m[2][1] * p[2] + m[3][1]*p[3];
   p_new[2] = m[0][2] * p[0] + m[1][2] * p[1] + m[2][2] * p[2] + m[3][2]*p[3]; 
   p_new[3] = m[0][3] * p[0] + m[1][3] * p[1] + m[2][3] * p[2] + m[3][3]*p[3]; 
   
  
   return p_new;
}

float[] transform_pointTranslate(float[][] n, float[] p)
{

   float[] p_new = {0.0,0.0,0.0,0.0}; // handle 4 elements as its 3D calc
   
   p_new[0] = n[0][0] * p[0] + n[1][0] * p[1] + n[2][0] * p[2] + n[3][0]*p[3];
   p_new[1] = n[0][1] * p[0] + n[1][1] * p[1] + n[2][1] * p[2] + n[3][1]*p[3];
   p_new[2] = n[0][2] * p[0] + n[1][2] * p[1] + n[2][2] * p[2] + n[3][2]*p[3]; 
   p_new[3] = n[0][3] * p[0] + n[1][3] * p[1] + n[2][3] * p[2] + n[3][3]*p[3]; 
   
   return p_new;
}


float[] transform_pointRotate(float[][] z, float[] p){

   float[] p_new = {0.0,0.0,0.0,0.0}; // handle 4 elements as its 3D calc
   
   p_new[0] = z[0][0] * p[0] + z[1][0] * p[1] + z[2][0] * p[2] + z[3][0]*p[3];
   p_new[1] = z[0][1] * p[0] + z[1][1] * p[1] + z[2][1] * p[2] + z[3][1]*p[3];
   p_new[2] = z[0][2] * p[0] + z[1][2] * p[1] + z[2][2] * p[2] + z[3][2]*p[3]; 
   p_new[3] = z[0][3] * p[0] + z[1][3] * p[1] + z[2][3] * p[2] + z[3][3]*p[3]; 
  
   return p_new;
}





/* 
setting a low framerate() and noLoop() in setup() 
and turning looping on and off with mousePress and mouseRelease
allows us to see each itteration of 'draw()'
*/

//SCALING THE ENEMY==================================
void applyTransform(){
  
  p33 = transform_pointScale(n, p33);
  p34 = transform_pointScale(n, p34);
  p35 = transform_pointScale(n, p35);
  p36 = transform_pointScale(n, p36);
  p37 = transform_pointScale(n, p37);
  p38 = transform_pointScale(n, p38);
  p39 = transform_pointScale(n, p39);
  p40 = transform_pointScale(n, p40);
  p41 = transform_pointScale(n, p41);
  p42 = transform_pointScale(n, p42);
  p43 = transform_pointScale(n, p43);
  p44 = transform_pointScale(n, p44);
  
  p45 = transform_pointRotate(z, p45);
  p46 = transform_pointRotate(z, p46);
  p47 = transform_pointRotate(z, p47);
  p48 = transform_pointRotate(z, p48);
  p49 = transform_pointRotate(z, p49);
  p50 = transform_pointRotate(z, p50);
  p51 = transform_pointRotate(z, p51);
  p52 = transform_pointRotate(z, p52);
  p53 = transform_pointRotate(z, p53);
  p54 = transform_pointRotate(z, p54);
  p55 = transform_pointRotate(z, p55);
  p56 = transform_pointRotate(z, p56);
  p57 = transform_pointRotate(z, p57);
  p58 = transform_pointRotate(z, p58);
  p59 = transform_pointRotate(z, p59);
  p60 = transform_pointRotate(z, p60);
  p61 = transform_pointRotate(z, p61);
  p62 = transform_pointRotate(z, p62);
   
  
  
  p63 = transform_pointScale(m, p63);
  p64 = transform_pointScale(m, p64);
  p65 = transform_pointScale(m, p65);
  p66 = transform_pointScale(m, p66);
  p67 = transform_pointScale(m, p67);
  p68 = transform_pointScale(m, p68);
  p69 = transform_pointScale(m, p69);
  p70 = transform_pointScale(m, p70);
  p71 = transform_pointScale(m, p71);
  p72 = transform_pointScale(m, p72);
  p73 = transform_pointScale(m, p73);
  p74 = transform_pointScale(m, p74);
  p75 = transform_pointScale(m, p75);
  p76 = transform_pointScale(m, p76);
  p77 = transform_pointScale(m, p77);
  p78 = transform_pointScale(m, p78);  
}
//===========================================================

void mousePressed() 
{ 
  loop(); 
} 


 
void mouseReleased() 
{ 
  noLoop(); 
} 

void drawBox () {
  //STATIC PLAYER DRAW 1====================================================================
  strokeWeight(1);
  stroke(255, 174,201);
  //HEAD
  line(p1[0],p1[1],p1[2], p2[0],p2[1],p2[2]);
  line(p2[0],p2[1],p2[2], p3[0],p3[1],p3[2]);
  line(p3[0],p3[1],p3[2], p4[0],p4[1],p4[2]);
  line(p4[0],p4[1],p4[2], p1[0],p1[1],p1[2]); 
  
  //LEFT ARM
  stroke(0, 162,232);
  line(p4[0],p4[1],p4[2], p5[0],p5[1],p5[2]);//p5 to p6
  line(p5[0],p5[1],p5[2], p6[0],p6[1],p6[2]); //p6 to p7
  line(p6[0],p6[1],p6[2], p7[0],p7[1],p7[2]);//p7 to p8

  //WAIST & FEET
  stroke(63, 72,204);
  line(p7[0],p7[1],p7[2], p8[0],p8[1],p8[2]);
  line(p8[0],p8[1],p8[2], p9[0],p9[1],p9[2]);
  line(p9[0],p9[1],p9[2], p10[0],p10[1],p10[2]);
  line(p10[0],p10[1],p10[2], p11[0],p11[1],p11[2]);
  line(p11[0],p11[1],p11[2], p12[0],p12[1],p12[2]);
  
  //RIGHT ARM
  stroke(0, 162,232);
  line(p12[0],p12[1],p12[2], p13[0],p13[1],p13[2]);
  line(p13[0],p13[1],p13[2], p14[0],p14[1],p14[2]);
  line(p14[0],p14[1],p14[2], p15[0],p15[1],p15[2]);
  line(p15[0],p15[1],p15[2], p3[0],p3[1],p3[2]);
  
 //EXTRA
 stroke(63, 72,204);
  line(p10[0],p10[1],p10[2], p16[0],p16[1],p16[2]);//Legs
  line(p12[0],p12[1],p12[2], p8[0],p8[1],p8[2]);//Waist
  
   //STATIC PLAYER DRAW 2==============================================================================================================
  strokeWeight(1);
  stroke(255, 174,201);
  //HEAD
  line(p17[0],p17[1],p17[2], p18[0],p18[1],p18[2]);
  line(p18[0],p18[1],p18[2], p19[0],p19[1],p19[2]);
  line(p19[0],p19[1],p19[2], p20[0],p20[1],p20[2]);
  line(p20[0],p20[1],p20[2], p17[0],p17[1],p17[2]); 
  
  //LEFT ARM
  stroke(0, 162,232);
  line(p20[0],p20[1],p20[2], p21[0],p21[1],p21[2]);//p5 to p6
  line(p21[0],p21[1],p21[2], p22[0],p22[1],p22[2]); //p6 to p7
  line(p22[0],p22[1],p22[2], p23[0],p23[1],p23[2]);//p7 to p8

  //WAIST & FEET
  stroke(63, 72,204);
  line(p23[0],p23[1],p23[2], p24[0],p24[1],p24[2]);
  line(p24[0],p24[1],p24[2], p25[0],p25[1],p25[2]);
  line(p25[0],p25[1],p25[2], p26[0],p26[1],p26[2]);
  line(p26[0],p26[1],p26[2], p27[0],p27[1],p27[2]);
  line(p27[0],p27[1],p27[2], p28[0],p28[1],p28[2]);
  
  //RIGHT ARM
  stroke(0, 162,232);
  line(p28[0],p28[1],p28[2], p29[0],p29[1],p29[2]);
  line(p29[0],p29[1],p29[2], p30[0],p30[1],p30[2]);
  line(p30[0],p30[1],p30[2], p31[0],p31[1],p31[2]);
  line(p31[0],p31[1],p31[2], p19[0],p19[1],p19[2]);
  
 //EXTRA
 stroke(63, 72,204);
  line(p26[0],p26[1],p26[2], p32[0],p32[1],p32[2]);//Legs
  line(p28[0],p28[1],p28[2], p24[0],p24[1],p24[2]);//Waist
  
  //CONNECTING STATIC PLAYER 1 TO 2
  stroke(255, 174,201);
  line(p1[0],p1[1],p1[2], p17[0],p17[1],p17[2]);
  line(p2[0],p2[1],p2[2], p18[0],p18[1],p18[2]);
  line(p3[0],p3[1],p3[2], p19[0],p19[1],p19[2]);
  line(p4[0],p4[1],p4[2], p20[0],p20[1],p20[2]);
  
  line(p5[0],p5[1],p5[2], p21[0],p21[1],p21[2]);
  line(p6[0],p6[1],p6[2], p22[0],p22[1],p22[2]);
  line(p7[0],p7[1],p7[2], p23[0],p23[1],p23[2]);
  line(p8[0],p8[1],p8[2], p24[0],p24[1],p24[2]);
  line(p9[0],p9[1],p9[2], p25[0],p25[1],p25[2]);
  line(p10[0],p10[1],p10[2], p26[0],p26[1],p26[2]);
  line(p11[0],p11[1],p11[2], p27[0],p27[1],p27[2]);
  line(p12[0],p12[1],p12[2], p28[0],p28[1],p28[2]);
  line(p13[0],p13[1],p13[2], p29[0],p29[1],p29[2]);
  line(p14[0],p14[1],p14[2], p30[0],p30[1],p30[2]);
  line(p15[0],p15[1],p15[2], p31[0],p31[1],p31[2]);
  //========================================================================================================================
  
  //GUN 1
  stroke(255, 255, 255);
  line(p33[0],p33[1],p33[2], p34[0],p34[1],p34[2]);
  line(p34[0],p34[1],p34[2], p35[0],p35[1],p36[2]);
  line(p35[0],p35[1],p35[2], p36[0],p36[1],p36[2]);
  line(p36[0],p36[1],p36[2], p37[0],p37[1],p37[2]);
  line(p37[0],p37[1],p37[2], p38[0],p38[1],p38[2]);
  line(p38[0],p38[1],p38[2], p33[0],p33[1],p3[2]);
  
  //GUN 2
  line(p39[0],p39[1],p39[2], p40[0],p40[1],p40[2]);
  line(p40[0],p40[1],p40[2], p41[0],p41[1],p41[2]);
  line(p41[0],p41[1],p41[2], p42[0],p42[1],p42[2]);
  line(p42[0],p42[1],p42[2], p43[0],p43[1],p43[2]);
  line(p43[0],p43[1],p43[2], p44[0],p44[1],p44[2]);
  line(p44[0],p44[1],p44[2], p39[0],p39[1],p39[2]);
  
  //CONNECTING GUNS
  line(p33[0],p33[1],p33[2], p39[0],p39[1],p39[2]);
  line(p34[0],p34[1],p34[2], p40[0],p40[1],p40[2]);
  line(p35[0],p35[1],p35[2], p41[0],p41[1],p41[2]);
  line(p36[0],p36[1],p36[2], p42[0],p42[1],p42[2]);
  line(p37[0],p37[1],p37[2], p43[0],p43[1],p43[2]);
  line(p38[0],p38[1],p38[2], p44[0],p44[1],p44[2]);
//============================================================================================================================

//SIGN 1
stroke(255, 127,39);
line(p45[0],p45[1],p45[2], p46[0],p46[1],p46[2]);
line(p46[0],p46[1],p46[2], p47[0],p47[1],p47[2]);
line(p47[0],p47[1],p47[2], p48[0],p48[1],p48[2]);
line(p48[0],p48[1],p48[2], p45[0],p45[1],p45[2]);

line(p49[0],p49[1],p49[2], p50[0],p50[1],p50[2]);
line(p50[0],p50[1],p50[2], p51[0],p51[1],p51[2]);
line(p51[0],p51[1],p51[2], p52[0],p52[1],p52[2]);
line(p52[0],p52[1],p52[2], p53[0],p53[1],p53[2]);
line(p53[0],p53[1],p53[2], p49[0],p49[1],p49[2]);

//SIGN 2
line(p54[0],p54[1],p54[2], p55[0],p55[1],p55[2]);
line(p55[0],p55[1],p55[2], p56[0],p56[1],p56[2]);
line(p56[0],p56[1],p56[2], p57[0],p57[1],p57[2]);
line(p57[0],p57[1],p57[2], p54[0],p54[1],p54[2]);

line(p58[0],p58[1],p58[2], p59[0],p59[1],p59[2]);
line(p59[0],p59[1],p59[2], p60[0],p60[1],p60[2]);
line(p60[0],p60[1],p60[2], p61[0],p61[1],p61[2]);
line(p61[0],p61[1],p61[2], p62[0],p62[1],p62[2]);
line(p62[0],p62[1],p62[2], p58[0],p58[1],p58[2]);


//CONNECTING SIGNS
line(p45[0],p45[1],p45[2], p54[0],p54[1],p54[2]);
line(p46[0],p46[1],p46[2], p55[0],p55[1],p55[2]);
line(p47[0],p47[1],p47[2], p56[0],p56[1],p56[2]);
line(p48[0],p48[1],p48[2], p57[0],p57[1],p57[2]);

line(p49[0],p49[1],p49[2], p58[0],p58[1],p58[2]);
line(p50[0],p50[1],p50[2], p59[0],p59[1],p59[2]);
line(p51[0],p51[1],p51[2], p60[0],p60[1],p60[2]);
line(p52[0],p52[1],p52[2], p61[0],p61[1],p61[2]);
line(p53[0],p53[1],p53[2], p62[0],p62[1],p62[2]);
//============================================================
//ENEMY
stroke(181, 230, 29);
line(p63[0],p63[1],p63[2], p64[0],p64[1],p64[2]);
line(p64[0],p64[1],p64[2], p65[0],p65[1],p65[2]);
line(p65[0],p65[1],p65[2], p66[0],p66[1],p66[2]);
line(p66[0],p66[1],p66[2], p63[0],p63[1],p63[2]);

line(p67[0],p67[1],p67[2], p68[0],p68[1],p68[2]);
line(p68[0],p68[1],p68[2], p69[0],p69[1],p69[2]);
line(p69[0],p69[1],p69[2], p70[0],p70[1],p70[2]);
line(p70[0],p70[1],p70[2], p67[0],p67[1],p67[2]);

line(p71[0],p71[1],p71[2], p72[0],p72[1],p72[2]);
line(p72[0],p72[1],p72[2], p73[0],p73[1],p73[2]);
line(p73[0],p73[1],p73[2], p74[0],p74[1],p74[2]);
line(p74[0],p74[1],p74[2], p71[0],p71[1],p71[2]);

//ENEMY 2
line(p75[0],p75[1],p75[2], p76[0],p76[1],p76[2]);
line(p76[0],p76[1],p76[2], p77[0],p77[1],p77[2]);
line(p77[0],p77[1],p77[2], p78[0],p78[1],p78[2]);
line(p78[0],p78[1],p78[2], p75[0],p75[1],p75[2]);

//CONNECTING ENEMY BODY
line(p63[0],p63[1],p63[2], p75[0],p75[1],p75[2]);
line(p64[0],p64[1],p64[2], p76[0],p76[1],p76[2]);
line(p65[0],p65[1],p65[2], p77[0],p77[1],p77[2]);
line(p66[0],p66[1],p66[2], p78[0],p78[1],p78[2]);

}

/*void drawAxes() {
 stroke(255, 0, 0);
  line(-50, 0, 0, 50, 0, 0);
  
  stroke(0, 255, 0);
  line(0, -50, 0, 0, 50, 0);
  
  stroke(0, 0, 255);
  line(0, 0, -50, 0, 0, 50);
  
 // text("Hello" + p63[1], 50, 50);
  
}*/
