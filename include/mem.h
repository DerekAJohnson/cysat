/* 
 * File:   mem.h
 * Author: Jake Drahos
 *
 * Header file for memory management functions.
 *
 * These will use SPI. This will contain functions to read/write to heaps on
 * flash and FRAM
 *
 * Created on November 11, 2013, 5:43 PM
 */

#ifndef MEM_H
#define	MEM_H

#ifdef	__cplusplus
extern "C" {
#endif

    //ONLY CALL ONCE. CALL BEFORE ANYTHING ELSE
    //NOT -TECHNICALLY- RTOS-SAFE. ONLY RUN ONE TEST TASK
    void vSetupMem();
    void vStartMemTestTask();


    //NOT RTOS-SAFE
    //Addresses will be 3 byte arrays. [MSB, 2SB, LSB]. Terrible.
#if 0
    void vFlashErase(char * address);  //terrible and destructive. Nukes everything
                                    //within the 4KB boundary containing the
                                    //given address.
    void vFlashWrite(unsigned char * address, int length, unsigned char * bytes);
    void vFlashRead(unsigned char * address, int length, unsigned char * buffer);
    void vFlashReadId(unsigned char * buffer);
#endif

    void vFRAMRead(unsigned long address, int length, unsigned char * buffer);
    void vFRAMWrite(unsigned long address, int length, unsigned char * buffer);
   // void vFRAMReadId(unsigned char * buffer);


#ifdef	__cplusplus
}
#endif

#endif	/* MEM_H */

