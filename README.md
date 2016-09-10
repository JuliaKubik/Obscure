# Obscure
Code for [Julia Kubik's](http://juliakubik.com) 2016 "Obscure" artwork

## Introduction
"Obscure" is an artwork which uses a smart mirror designed to deny the viewer any access. This work deals with both desire (the desire to be seen) and denial (the frustration of not being able to view oneself). 

By hiding the viewer’s reflection, I am denying the viewer an opportunity to view themselves. They might gain a fragment of their reflection in the split second between triggering the smart glass and it turning opaque. My hope is that the disappearance of their refection, creates an unsettling, possibly disturbing emotional response, which might conclude with a sense of frustration, as the viewer can no longer confirm their appearance. By obscuring the viewer’s refection in the mirror, I am dismissing their preconceived ideas about their outward appearance, thereby forcing the viewer to question themselves; how will I appear to others?  Or more poignantly, who am I? The title of this work has multiple interpretations. On the one hand, there is the literal interpretation of obscuring the reflection of the viewer, therefore indicating that our physical self-image is to some degree obscured or indeterminate. On the other, we may reflect on our ever-changing logical self-image which is obscured in the sense of our self-formed image being abstruse and therefore difficult to understand.

## Code and Design
To achieve this goal a piece of mirrored glass is placed behind a pane of electronic privacy glass. Privacy glass will change from opaque to transparent depending on the application of a 65v AC feed. As such the code and design within this repository demonstrate how a sensor is used to drive the [ESG Glass HD-1](http://www.esgswitchable.glass) transformer.

In this repository you'll find the Arduino sketch and Fritzing model detailing the parts and connectivity. The code is exceptionally straightforward. The arduino tracks responses from the ultrasonic sensor and places them into a sliding window buffer. If a number of contiguous responses all match near or far the glass is set accordingly. It should be noted that setting the ESG pivacy glass transformer to off sets the glass to opaque therefore denying access to the mirror behind. If no obstruction is found the transformer is set to on which makes the glass transparent. It is important to note that the volt-free control circuit of the transformer must be used; do not connect the arduino to the 230v control circuit!

To open the Fritzing model you may require a custom [Maxbotix Fritzing Part](https://github.com/adafruit/Fritzing-Library/blob/master/parts/Maxbotix%20MaxSonar%20Ultrasonic%20Sensor%20%28Hi-Res%29.fzpz) which can be found via the attached link.
