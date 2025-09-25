# SDBUS_CALLBACK_ROUTINE callback function

## Description

The PSDBUS_CALLBACK_ROUTINE prototype declares the Secure Digital (SD) driver callback routine that the SD bus driver uses to report device interrupts to the driver.

## Parameters

### `CallbackRoutineContext` [in]

Pointer to the context information that the bus driver passes to the callback routine. The device driver supplies the bus driver with this information when it initializes the SD bus interface.

### `InterruptType` [in]

Must be set to SDBUS_INTTYPE_DEVICE.

## Remarks

When an SD device driver initializes an instance of the SD bus interface, it loads the **CallbackRoutine** member of the [SDBUS_INTERFACE_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537919(v=vs.85)) structure with a pointer to PSDBUS_CALLBACK_ROUTINE.

The bus driver calls the SD card driver's callback routine whenever the card indicates an interrupt. The callback routine must send the appropriate device commands to handle and clear the interrupt on the card. After it completes the series of I/O operations, the SD card driver should acknowledge the interrupt. For more information about how SD card drivers acknowledge interrupts, see [PSDBUS_ACKNOWLEDGE_INT_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nc-ntddsd-psdbus_acknowledge_int_routine).

## See also

[SDBUS_INTERFACE_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537919(v=vs.85))