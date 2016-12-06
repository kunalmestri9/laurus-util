<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of TUtilValidation
 *
 * @author Shreeniwas
 */
class TUtilValidation {
    
    /**
     * This method wil check strins are valid or not
     * @param <string> $str
     * @return <Boolean>
     */
    public static function isValidName($str) {
        if ((!preg_match("/^[a-zA-Z ]*$/", $str))) {
            return false;
        }
        return TRUE;
    }

    public static function isValidEmail($str) {
        if ((!preg_match("/^(([^<>()[\]\\.,;:\s@\"]+(\.[^<>()[\]\\.,;:\s@\"]+)*)|(\".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/", $str))) {
            return false;
        }
        return TRUE;
    }

    public static function isValidPAN($str) {
        if ((!preg_match("/^([a-zA-Z]){5}([0-9]){4}([a-zA-Z]){1}?$/", $str))) {
            return false;
        }
        return TRUE;
    }

    public static function isValidNumber($str) {
        if ((!preg_match("/^[0-9]+$/", $str))) {
            return false;
        }
        return TRUE;
    }

    public static function isValidPincode($str) {
        if ((!preg_match("/^([1-9])([0-9]){5}$/", $str))) {
            return false;
        }
        return TRUE;
    }

    public static function isValidMobileNo($str) {
        if ((!preg_match("/^\d{10}$/", $str))) {
            return false;
        }
        return TRUE;
    }

    public static function isBlankObject($obj, $mandatoryparams) {
        foreach ($mandatoryparams as $key => $value) {
            $methodName = "get" . ucfirst($key);
            if (method_exists($obj, $methodName) && !TUtilString::isValidString($obj->$methodName()))
                throw new ValidationException($value . "  is mandatory");
        }
    }

    public static function isValidDateFormatForDDMMYY($date) {
        if (strlen($date) > 10) {
            return FALSE;
        } else {
            $newdate = str_replace(array('/', '.'), '-', $date);
            if (preg_match("/^(0[1-9]|[1-2][0-9]|3[0-1])-(0[1-9]|1[0-2])-([0-9]{4})$/", $newdate, $matches)) {
                 if (!checkdate($matches[2], $matches[1], $matches[3])) {
                    return FALSE;
                }
                return true;
            }
            return False;
        }
        return true;
    }
    
    public static function isValiDateFormatForMonthYear($date){
        $newDate=str_replace(array('/', '.'), '-', $date);
        $m=  explode("-", $newDate);
        $mo=  strtoupper($m[0]);
        $finalDate=str_replace($m[0],$mo, $newDate);
        if(preg_match("/^(JAN|FEB|MAR|APR|MAY|JUN|JUL|AUG|SEP|OCT|NOV|DEC)-([0-9]{4})$/", $finalDate, $matches)) 
	{
		$month = array('JAN'=>'01'
				   		,'FEB'=>'02'
				   		,'MAR'=>'03'
				   		,'APR'=>'04'
				   		,'MAY'=>'05'
				   		,'JUN'=>'06'
				   		,'JUL'=>'07'
				   		,'AUG'=>'08'
				   		,'SEP'=>'09'
				   		,'OCT'=>'10'
				   		,'NOV'=>'11'
				   		,'DEC'=>'12'
					   );
             	if(!checkdate($month[$matches[1]],'01',$matches[2])){
                    return False;
		}
              return true;  
          }
          return false;
    }
    public static function isValidDateFormatForYYMMDD($date) {
        if (strlen($date) > 10) {
            return FALSE;
        } else {
            $newdate = str_replace(array('/', '.'), '-', $date);
            if (preg_match("/^([0-9]{4})-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$/", $newdate, $matches)) {
                 if (!checkdate($matches[2], $matches[3], $matches[1])) {
                    return FALSE;
                }
                return true;
            }
            return False;
        }
        return true;
    }
    
    public function isValidChequeNO($str){
         if ((!preg_match("/^\d{6,}$/", $str))) {
            return false;
        }
        return TRUE;
         
    }
    
    public function isValidChequeReturn($str){
         if ((!preg_match("/^\d{1,3}$/", $str))) {
            return false;
        }
        return TRUE;
         
    }
    public function isValidTINNumber($str){
         if ((!preg_match("/^((0[1-9])|(1[0-9])|(2[0-9])|(3[0-5]))([a-zA-Z0-9]{9})$/", $str))) {
            return false;
        }
        return TRUE;
         
    }
    
    public function isStartMonthGreaterEndMonth($startMonthDate,$endMonthDate){
       $startDate=date("Y-m-d",strtotime($startMonthDate)); 
       $endDate=date("Y-m-d",strtotime($endMonthDate));
       $diff=date_diff(date_create($startDate),date_create($endDate));
       $dayDiff=$diff->format("%R%m");
       $dayDiffYear=$diff->format("%R%y");
       if($dayDiffYear >= 1){
           return true;
       }else{
       if($dayDiff < 0 ){
            return false;
       }
       return true;}
 }    
    
}

?>
