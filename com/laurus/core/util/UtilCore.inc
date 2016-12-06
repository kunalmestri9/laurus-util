<?php
/**
 * @author Kunal Mestri
 * @see This is Created for storing all functionalities may be required for all projects
 * 
 */
class UtilCore {
    /**
     * @see Created for Replace all \n \r to &lt;br&gt; tag
     * @param <String> $t
     * @return <String>
     */
    public static function getContentCRLFToBR($t) {
        $characterToReplace   = array("\r\n","\n", "\r");
        $replaceWith = '<br />';
        return  str_replace($characterToReplace, $replaceWith, $t);
    }
}
?>
