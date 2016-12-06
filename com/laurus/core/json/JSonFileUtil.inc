<?php
import("com.laurus.core.file.FileException");
/**
 * Description of JSonFileUtil
 *
 * @author Kunal Mestri <kunal@laurus-it.com>
 */
class JSonFileUtil {
    
    private static $logger;
    /**
     * 
     * @return Logger
     */
    public static function getLogger(){
        if(self::$logger==null){
            self::$logger=  Logger::getLogger(__CLASS__);
        }
        return self::$logger;
    }
    
    public static function getJSONFromFile($file){
        self::getLogger()->debug("Checking if file is present or not :" . $file);
        if(file_exists($file)){
            self::getLogger()->debug("JSON FILE PRESENT");
            $fileContents=file_get_contents($file);
            self::$logger->debug("contents :" . $fileContents);
            $jsonConfig=json_decode($fileContents,true);
        }else{
            self::$logger->error($file . " File is missing.");
            throw new FileException(FileException_SUBTYPE::FILE_NOT_FOUND);
        }
        return $jsonConfig;
    }
     
}

?>
