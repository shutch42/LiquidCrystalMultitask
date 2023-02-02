# LiquidCrystalMultitask
A (mostly) non-blocking fork of the Arduino Liquid Crystal Library

So there's a bit of a story with this library. 
I've been working on making a multi-track audio recorder, and it uses an LCD to display information while it records audio. 
I ran into a bug while I was working on this, where if I updated the LCD while the device was recording audio, it would cause skipping in the recording. 
In my naive brain, I determined that the delay in updating the LCD is what was causing the audio skipping. I even did a bunch of math to justify this theory!
I determined that since I was reading an audio sample every 23us, and the LCD write() function contains a 100us delay, the delay must be causing missing samples.
I completely ignored the fact that my audio samples were being queued in, and could still be processed after a delay.
So, in my ignorance, I decided to take the Arduino LiquidCrystal library, and modify it so that it uses elapsedMicros variables, rather than delay() function calls. 
This would allow the processor to continue working on other things while it waits out the delay. I spent probably a good 8 hours modifying and debugging this new library so that it works. 
After I finally got it working, I loaded it into my audio recorder code, and tested it out. Everything started off nicely, and then then I started recording. 
It recorded everything skipping, but the LCD was frozen as it happened. It was at this point that I realized my original code was wrong, not the library. 
I was attempting to update the LCD in almost every loop of the main code, whether it needed to be updated or not.
This was causing the repeated delays, which resulting in skipped audio samples. 
But when I used my multitasking LCD library, I immediately filled up the queued display actions, which then required the LCD to process an impossible number of functions with everything else going on in the background.
So finally, I sat back down with my original code, and decided to only send an LCD write() command every 100ms, with the original LiquidCrystal library, and this solved the issue.
