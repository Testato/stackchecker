/**
 *  \brief Stack checker extension utility file.
 *
 *  This file has been automatically added to your project by the Stack Checker
 *  Atmel Studio extension. If you are not currently using this extension, this
 *  file may be removed from your project.
 */

#include <stdint.h>

/** Linker provided symbols for the end of the static data section, and the
 *  of the stack.
 */
extern void *_end, *__stack;

/** \internal
 *  \brief Low level stack painting function, hooked into the avr-libc initialization code.
 *
 *  This function paints the internal SRAM between the end of the static data
 *  and the start of the stack with a known \c 0xDC hex constant. This is then
 *  detected by the Stack Checker extension when a debug session is halted to
 *  determine the maximim stack usage of the running application.
 */
void _StackPaint(void) __attribute__ ((naked)) __attribute__ ((section (".init1")));
void _StackPaint(void)
{
	uint8_t *p = (uint8_t*)&_end;

	while (p <= (uint8_t*)&__stack)
	  *(p++) = 0xDC;
}