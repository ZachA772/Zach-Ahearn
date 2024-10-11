let currentImg=1;
function swap(){
    let picNum = this.id
    picNum = picNum.charAt(3);

    document.querySelector('#mainImg').src='gallery/pic'+picNum+'.png';
    currentImg=picNum;

}


document.querySelector('#pic1').addEventListener('mouseover', swap);
document.querySelector('#pic2').addEventListener('mouseover', swap);
document.querySelector('#pic3').addEventListener('mouseover', swap);
document.querySelector('#pic4').addEventListener('mouseover', swap);
document.querySelector('#pic5').addEventListener('mouseover', swap);
document.querySelector('#pic6').addEventListener('mouseover', swap);
document.querySelector('#pic7').addEventListener('mouseover', swap);
document.querySelector('#pic8').addEventListener('mouseover', swap);

document.querySelector('#prevLink').addEventListener('click', previous);
document.querySelector('#nextLink').addEventListener('click', next);


//Contact JS
function processForm(event)
{
    if(validateForm()==false){
        event.preventDefault();
    }
}

function validateForm(){
    let nameVal = document.querySelector('#name').value;
    if(nameVal =='' || nameVal == null){
       document.querySelector('#nameErr').innerHTML=" Name cannot be blank";
       return false; 
    }
    if(nameVal.length > 20){
        document.querySelector('#nameErr').innerHTML=" Name must be less than 20 characters";
        return false; 
     }
//----------------------------------------------------------------------------------------------------------------
    let mobileVal = document.querySelector('#mobile').value;
    if(mobileVal.length > 10 || mobileVal.length < 10){
        document.querySelector('#mobileErr').innerHTML=" Phone number must be 10 digits long";
        return false; 
     }

     if(validateMobile(mobileVal) == false)
    {
        document.querySelector("#mobileErr").innerHTML=" Mobile is invalid";

    }
//-------------------------------------------------------------------------------------------------------------
    let email1Val = document.querySelector('#email1').value;
    if(email1Val =='' || email1Val == null){
       document.querySelector('#email1Err').innerHTML=" Email cannot be blank";
       return false; 
    }
    if(validateEmail(email1Val) == false)
    {
        document.querySelector("#email1Err").innerHTML=" Email is invalid";

    }
//---------------------------------------------------------------------------------------------------------
    let email2Val = document.querySelector('#email2').value;
    if(email2Val =='' || email2Val == null){
       document.querySelector('#email2Err').innerHTML=" Email cannot be blank";
       return false;
    }
    if(email2Val != email1Val){
        document.querySelector('#email2Err').innerHTML=" Emails do no match";
        return false;
     }
     if(validateEmail(email2Val) == false)
    {
        document.querySelector("#email2Err").innerHTML=" Email is invalid";

    }
//---------------------------------------------------------------------------------------------------------------
    let queryVal = document.querySelector('#query').value;
    if(queryVal =='' || queryVal == null){
       document.querySelector('#queryErr').innerHTML=" Comment cannot be blank";
       return false;
    }
    //-----------------------------------------------------------------------------------------------------
function validateEmail(elementValue){
    const emailPattern = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/;
    return emailPattern.test(elementValue);
}

function validateMobile(numberValue) {
    const mobilePattern = /^(087|086|085)\d{7}$/;
    return mobilePattern.test(numberValue);
  }

}