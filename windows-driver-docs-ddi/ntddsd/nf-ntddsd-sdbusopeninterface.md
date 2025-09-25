# SdBusOpenInterface function

## Description

The **SdBusOpenInterface** routine obtains an interface from the Secure Digital (SD) bus driver.

## Parameters

### `Pdo` [in]

Pointer to the physical device object that the SD bus driver created for the SD device that the device driver manages. The system passes this pointer to the device driver when it calls the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

### `InterfaceStandard` [out]

Contains, on input, a pointer to a structure of type [SDBUS_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537923(v=vs.85)) supplied by the caller. On output, this structure holds pointers to the SD bus interface routines. This structure also contains some context information in its **Context** member that the caller should pass in every time it calls an interface routine.

### `Size` [in]

Contains the size, in bytes, of the structure pointed to by *InterfaceStandard*.

### `Version` [in]

Must be set to SDBUS_INTERFACE_VERSION.

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or the appropriate error code if the operation fails.

## Remarks

An SD card driver should call this routine from its [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

SD card drivers must call this routine to establish communication with the bus driver. On successful completion of this call, the **Context** member of the structure pointed to by *InterfaceStandard* will contain a handle that the driver must pass in when calling methods that belong to the retrieved interface.

## See also

[AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device)

[SDBUS_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537923(v=vs.85))