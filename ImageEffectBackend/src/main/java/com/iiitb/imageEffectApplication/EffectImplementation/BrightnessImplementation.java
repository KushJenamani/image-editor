package com.iiitb.imageEffectApplication.EffectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.BrightnessInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class BrightnessImplementation implements SingleValueParameterizableEffect{
    //data members
    private float parameterValue;
    //member functions
    public void setParameterValue(float parameterValue) throws IllegalParameterException{
        if(parameterValue<0 || parameterValue>200){//throw error when input is out of range
            throw new IllegalParameterException("Out of range");
        }
        this.parameterValue=parameterValue;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "Brightness", Float.toString(parameterValue));//writing it to the website
        return BrightnessInterface.applyBrightness(image, parameterValue);
    }
}
