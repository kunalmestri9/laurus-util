<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of TUtilPan
 *
 * @author Shreeniwas
 */
class TUtilPan {
    /**
     *This method wil check PAN is valid or not
     * @param <string> $pan 
     * @return <Boolean>
     */
     public static function isValidPAN($pan) {
            if((!preg_match("/^([a-zA-Z]){5}([0-9]){4}([a-zA-Z]){1}?$/", $pan))){
                return false;
            }
            return TRUE;
    }
    
}

?>
