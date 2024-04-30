package com.iiitb.imageEffectApplication.EffectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.DiscreteEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.RotationInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class RotationImplementation implements DiscreteEffect{
    private int rotateValue;
    public void selectOptionValue(String optionName, int value) throws IllegalParameterException{
        if(value==0 || value==1 || value==2 || value==3){
            rotateValue=value;
        }
        else{//checking if value is out of range and throwing an error if that's the case
            throw new IllegalParameterException("Invalid Input");
        }
     }
     public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        if(this.rotateValue==0)//this means rotate by 0 degrees
            loggingService.addLog(fileName, "Rotation", "By 0 degrees");
        else if(this.rotateValue==1)//this means rotate by 90 degrees
            loggingService.addLog(fileName, "Rotation", "By 90 degrees");
        else if(this.rotateValue==2)//this means rotate by 180 degrees
            loggingService.addLog(fileName, "Rotation", "By 180 degrees");
        else if(this.rotateValue==3)//this means rotate by 270 degrees
            loggingService.addLog(fileName, "Rotation", "By 270 degrees");
           
        return RotationInterface.applyRotation(image, rotateValue);
     }
}
