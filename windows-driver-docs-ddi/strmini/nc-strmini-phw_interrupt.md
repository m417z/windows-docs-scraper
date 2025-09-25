# PHW_INTERRUPT callback function (strmini.h)

## Description

*StrMiniInterrupt* is the minidriver's interrupt service routine.

## Parameters

### `DeviceExtension` [in]

Pointer to the minidriver's device extension.

## Return value

*StrMiniInterrupt* returns **TRUE** if the device generated the interrupt, and **FALSE** otherwise.

## Remarks

The class driver calls *StrMiniInterrupt* each time it receives an interrupt on behalf of the minidriver.

An interrupt may be shared among several different devices. The minidriver's *StrMiniInterrupt* routine must determine if its underlying hardware actually generated the interrupt. If the device did not generate the interrupt, *StrMiniInterrupt* should return **FALSE** as soon as possible -- for shared interrupts, the operating system calls the interrupt service routines registered for that interrupt until one of the routines returns **TRUE**, so the ISR may keep the actual device that generated the interrupt waiting if it takes too long to complete.