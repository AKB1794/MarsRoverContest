import pygame
import serial
x=1
# Define some colors
BLACK   =(0,0,0)
BLUE    = (0,   0,   255)
WHITE    = (255, 255, 255)
ser=serial.Serial('COM6',38400,timeout=0) 


class TextPrint:
    def __init__(self):
        self.reset()
        self.font = pygame.font.Font(None, 20)

    def print(self, screen, textString):
        textBitmap = self.font.render(textString, True, BLUE)
        screen.blit(textBitmap, [self.x, self.y])
        self.y += self.line_height
        
    def reset(self):
        self.x = 0
        self.y = 10
        self.line_height = 15
        
    def indent(self):
        self.x += 10
        
    def unindent(self):
        self.x -= 10




pygame.init()
 
# Set the width and height of the screen [width,height]
size = [1000, 700]
screen = pygame.display.set_mode(size)

pygame.display.set_caption("Anjan")

#Loop until the user clicks the close button.
done = True

# Used to manage how fast the screen updates
clock = pygame.time.Clock()

# Initialize the joysticks
pygame.joystick.init()
    
# Get ready to print
textPrint = TextPrint()


while done==True:
    # EVENT PROCESSING STEP
    for event in pygame.event.get(): # User did something
        if event.type == pygame.QUIT: # If user clicked close
            done=False # Flag that we are done so we exit this loop
            pygame.quit ()
 
    
    screen.fill(WHITE)
    textPrint.reset()

    # Get count of joysticks
    joystick_count = pygame.joystick.get_count()

    
    
    # For each joystick:
    for i in range(1):
        joystick = pygame.joystick.Joystick(0)
        joystick.init()
    
        
        buttonforword = joystick.get_button( 0  )

        buttonright = joystick.get_button( 1 )
        
        buttonleft = joystick.get_button( 3 )
        buttonbackword = joystick.get_button( 2 )

        acceleration=joystick.get_button( 5 )
        deacceleration=joystick.get_button( 7 )
        if buttonright==1:
            if x==0:
                ser.write('r'.encode())
                x=1;
        elif buttonforword==1:
            if x==0:
                ser.write('f'.encode())
                x=1;
        elif buttonleft==1:
            if x==0:
                ser.write('l'.encode())
                x=1;
        
        elif buttonbackword==1:
            if x==0:
                ser.write('b'.encode())
                x=1;
        elif acceleration==1:
            if x==0:
                ser.write('a'.encode())
                x=1;
        elif deacceleration==1:
            if x==0:
                ser.write('d'.encode())
                x=1;
        else :
            if x==1:
                ser.write('o'.encode())
                x=0;
        
        
        
        
        textPrint.print(screen,"        {}".format(buttonforword))
        textPrint.print(screen, "{}              {} ".format(buttonleft,buttonright))
        textPrint.print(screen,"        {}".format(buttonbackword))
        textPrint.print(screen,"{}".format(acceleration))
        textPrint.print(screen,"{}".format(deacceleration))
        textPrint.unindent()
    pygame.display.flip()


    clock.tick(20)
    

pygame.quit ()
