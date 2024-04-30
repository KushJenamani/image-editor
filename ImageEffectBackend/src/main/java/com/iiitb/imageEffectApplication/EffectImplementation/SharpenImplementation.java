package com.iiitb.imageEffectApplication.EffectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.SharpenInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class SharpenImplementation implements SingleValueParameterizableEffect{
    //data members
    private float parameterValue;
    //member methods
    public void setParameterValue(float parameterValue) throws IllegalParameterException{
        if(parameterValue<0 || parameterValue>200)//check if input is out of range and throw exception
        {
            throw new IllegalParameterException("Out of Range");
        }
        this.parameterValue=parameterValue;
        
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "Sharpen", Float.toString(parameterValue));//logging the message on to the website
        return SharpenInterface.applySharpen(image, parameterValue);
    }
}
    
