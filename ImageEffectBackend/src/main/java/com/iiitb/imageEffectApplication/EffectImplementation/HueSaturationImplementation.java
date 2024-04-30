package com.iiitb.imageEffectApplication.EffectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.ParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.HueSaturationInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class HueSaturationImplementation implements ParameterizableEffect{
    private float saturationValue;
    private float hueValue;
    public void setParameter(String paramName, float value) throws IllegalParameterException
    {
        if(paramName.equals("saturationEffect")){ //error handling
            if(value<0 || value>200)
                throw new IllegalParameterException("Out of range");
            saturationValue=value;
        }
        else if(paramName.equals("hueEffect")){
            if(value<0 || value>200)
                throw new IllegalParameterException("Out of range");
            hueValue=value;
        }
        else{//if option is neither of them,it means it's an error
            throw new IllegalParameterException("Invalid input");
        }
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "HueSaturation", "Saturation:"+saturationValue+" Hue:"+hueValue); //logging the message on to the website
        return HueSaturationInterface.applyHueSaturation(image, saturationValue, hueValue);
     }

}
