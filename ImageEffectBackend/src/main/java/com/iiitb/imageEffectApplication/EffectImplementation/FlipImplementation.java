package com.iiitb.imageEffectApplication.EffectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.DiscreteEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.FlipInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class FlipImplementation implements DiscreteEffect {
    private int horizontalFlipValue;
    private int verticalFlipValue;
    public void selectOptionValue(String optionName, int value) throws IllegalParameterException{
        if(optionName.equals("toggleHorizontalFlip")){
            horizontalFlipValue=value;
        }
        else if(optionName.equals("toggleVerticalFlip")){
            verticalFlipValue=value;
        }
        else{//if option is neither of them,it means it's an error
            throw new IllegalParameterException("Invalid input");
        }
     }
     public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "Flip", "Horizontal Value:"+horizontalFlipValue+" Vertical Value: "+verticalFlipValue);//this message is logged on to the website whenever flip is used
        return FlipInterface.applyFlip(image, horizontalFlipValue, verticalFlipValue);
     }
}
