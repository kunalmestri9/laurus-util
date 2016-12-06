<?php
/* 
* To change this template, choose Tools | Templates
* and open the template in the editor.
*/

/**
 * Description of TUtilString
 *
 * @author bb
 */
class TUtilString {
    /**
     *This method wil check String is empty or not
     * @param <String> $str
     * @return <Boolean>
     */
    public static function isValidString($str) {
            return !(trim($str)=="");
    }
    
    public  static function contains($search,$val){
        return (strpos($search, $val) !== false );
    }
    
    public  static function equals($str1,$str2){
        return (strcmp($str1, $str2) == 0);
    }
    
    public  static function equalsIgnoreCase($str1,$str2){
        return (strcasecmp($str1, $str2) == 0);
    }
    
    public static function chequeStringLength($str,$size){
        return (strlen($str) <= $size);
    }
    
    public static function returnNullIfInvalid($str){
        return (self::isValidString($str))?$str:NULL;
    }
    
}
?>
