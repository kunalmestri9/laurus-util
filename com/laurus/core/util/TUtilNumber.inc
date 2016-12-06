<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of TUtilNumber
 *
 * @author Shreeniwas
 */
class TUtilNumber {
    /**
     *This method wil check Number is empty or not
     * @param <Integer> $num
     * @return <Boolean>
     */
   
     public static function isValidNumber($num) {
             if((!preg_match("/^[0-9]+$/", $num))){
               return false; 
             }
             return TRUE;
    }
    
    public static function isValidPincode($num) {
             if((!preg_match("/^([1-9])([0-9]){5}$/", $num))){
               return false; 
             }
             return TRUE;
    }
   public static function isValidMobileNo($num) {
             if((!preg_match("/^\d{10}$/", $num))){
               return false; 
             }
             return TRUE;
    }
}

?>
