<?php

// eng: Generate OTP can be use for login verification via email and SMS 
// id : Generate OTP bisa digunakan untuk verifikasi login via email atau SMS 
class GenerateOtp
{
    // generate with length default 4 digit
    public function generateNumberOTP($n=4) {
        $iDigits = '135792468';
        $iOtp = '';
        for ($i=1; $i <= $n ; $i++) { 
            $iOtp .= substr($iDigits, (rand()%(strlen($iDigits))), 1);
        }
        $iOtp;
        return $iOtp;
    }
}

// show result
$getOTP = new GenerateOtp();
echo 'Result generate otp: </br>';
echo $getOTP->generateNumberOTP() . '</br>';
echo 'refresh for re-generate';