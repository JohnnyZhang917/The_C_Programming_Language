/*
* Declare the device registers
* Whether to use int or short
* is implementation dependent
*/

struct devregs{
        unsigned short volatile csr;
        unsigned short const volatile data;
};

/* bit patterns in the csr */
#define ERROR   0x1
#define READY   0x2
#define RESET   0x4

/* absolute address of the device */
#define DEVADDR ((struct devregs *)0xffff0004)

/* number of such devices in system */
#define NDEVS   4

/*
* Busy-wait function to read a byte from device n.
* check range of device number.
* Wait until READY or ERROR
* if no error, read byte, return it
* otherwise reset error, return 0xffff
*/
unsigned int read_dev(unsigned devno){

        struct devregs * const dvp = DEVADDR + devno;
        // dvp points to an volatile address
        // which means *dvp may change its value
        // so the while loop should not optimize as ( since the expression doesn't change, make it a infinite loop)
        
        // if the address is not volatile, then 

        if(devno >= NDEVS)
                return(0xffff);

        while((dvp->csr & (READY | ERROR)) == 0)
                ; /* NULL - wait till done */

        if(dvp->csr & ERROR){
                dvp->csr = RESET;
                return(0xffff);
        }

        return((dvp->data) & 0xff);
}


// or we can do this antoher way:
struct devregs{
      unsigned short  csr;    /* control & status */
      unsigned short  data;   /* data port */
};
volatile struct devregs *const dvp=DEVADDR+devno;
