<?php
/* 
* To change this template, choose Tools | Templates
* and open the template in the editor.
*/

/**
 * Description of TUtilDate
 *
 * @author bb
 */
class TUtilDate {
    /**
     * This method will check the date is proper or not in the format of mm/dd/yyyy
     *@param <String> $date
     * @return <boolean>
     */
    private static $logger;

    private static function initialliseLogger() {
        if(self::$logger==null) {
            self::$logger=Logger::getLogger(__CLASS__);
        }
    }
    public static function getDateFromMiliseconds($dateFormat,$miliSeconds) {
        $seconds = $miliSeconds / 1000;
        return date($dateFormat, $seconds);
    }
    
    public static function getMilisecondsFromDate($dateFormat) {
        $miliSeconds=1000 * strtotime($dateFormat);
        return $miliSeconds;
    }
    
    public static function getCurrentDateTime(){
        return date("Y-m-d H:i:s");
    }
    
    public static function getCurrentDate(){
        return date("Y-m-d");
    }
    
    public static function getStartDateOfMonth($month,$year){
        $first = date('Y-m-d', mktime(0, 0, 0, $month, 1, $year));
        return $first;

    }
    
    public static function getLastDateOfMonth($month,$year){
        $last = date('Y-m-t', mktime(0, 0, 0, $month, 1, $year));
        return $last;
    }
    public static function getDayFromDate($date){
        $timestamp = strtotime($date);
        $day=date('d',$timestamp);
        return $day;
    }
    
    public static function getDateDiffBtnDates($date1,$date2){
       $datetime1 = new DateTime($date1);
       $datetime2 = new DateTime($date2);
       $interval = $datetime1->diff($datetime2);
       return $interval->format('%R%a');
    }
	
	public static function getDateDiffBtnDatesWithTime($date1,$date2){
       $datetime1 = new DateTime($date1);
       $datetime2 = new DateTime($date2);
       $interval = $datetime1->diff($datetime2);
       return $interval->format('%R%a days,%R%h hours,%R%i minutes');
    }
    
    public static function getYearDate($date){
        $time=strtotime($date);
        $year=date("Y",$time);
        return $year;
        
    }
     public static function getMonthDate($date,$single=false){
        $time=strtotime($date);
        $month=$single?date("n",$time):date("m",$time);
        return $month;
        
    }
}
?>
