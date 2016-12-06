<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of TUtilEmail
 *
 * @author Shreeniwas
 */
class TUtilEmail {
   /**
     *This method wil check PAN is valid or not
     * @param <string> $email
     * @return <Boolean>
     */
     public static function isValidEmail($email) {
            if((!preg_match("/^(([^<>()[\]\\.,;:\s@\"]+(\.[^<>()[\]\\.,;:\s@\"]+)*)|(\".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/", $email))){
                return false;
            }
            return true;
    }
    
}

?>
