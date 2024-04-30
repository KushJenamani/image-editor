package com.iiitb.imageEffectApplication.EffectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.ContrastInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class ContrastImplementation implements SingleValueParameterizableEffect{
    //data members
    private float parameterValue;
    //member methods
    public void setParameterValue(float parameterValue) throws IllegalParameterException{
        if(parameterValue<0 || parameterValue>200){//checking if value is out of range and throwing an error if that's the case
            throw new IllegalParameterException("Out of range");
        }
        this.parameterValue=parameterValue;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "Contrast", Float.toString(parameterValue));//logging on to the website
        return ContrastInterface.applyContrast(image, parameterValue);
    }
}