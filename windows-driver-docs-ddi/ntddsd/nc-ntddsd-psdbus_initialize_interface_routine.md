# PSDBUS_INITIALIZE_INTERFACE_ROUTINE callback function

## Description

The PSDBUS_INITIALIZE_INTERFACE_ROUTINE prototype declares the routine that a Secure Digital (SD) device driver uses to initialize an interface instance that it creates with the [SdBusOpenInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface) routine.

## Parameters

### `Context` [in]

Contains the interface context that the [SdBusOpenInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface) routine returns in the **Context** member of the [SDBUS_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537923(v=vs.85)) structure.

### `InterfaceParameters` [in]

Pointer to a structure of type [SDBUS_INTERFACE_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537919(v=vs.85)) that contains the information that the bus driver should use to initialize the interface instance.

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or the appropriate error status if the operation fails.

## Remarks

An SD card driver typically calls its initialization routine immediately after the [SdBusOpenInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface) routine returns with a value of STATUS_SUCCESS.

An SD card driver must call its initialization routine before attempting to send requests to the bus driver.

## See also

[SDBUS_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537923(v=vs.85))

[SdBusOpenInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface)