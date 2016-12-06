<?php
/**
 * @author Kunal Mestri.
 */
class JsonBean{
    private $stringSource;
    private $jsonObject;
    public function __construct($jsonSource,$associative=true){
        if($jsonSource!=null && is_string($jsonSource)){
            $this->stringSource=$jsonSource;
            $this->jsonObject=json_decode($this->stringSource,$associative);
        }
    }
    public function getValue($nodeName){
        foreach($this->jsonObject as $key=>$values){
            if($key == $nodeName){
                if(is_array($values)){
                    return new JsonBean(json_encode($values));
                }
                return $values;
            }
        }
    }
}

?>
