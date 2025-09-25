## Description

The SDBUS\_INTERFACE\_PARAMETERS structure contains the information necessary to initialize a Secure Digital (SD) card bus interface.

## Members

### `Size`

Indicates the size, in bytes, of this structure, including the area pointed to by the **CallbackRoutineContext** member.

### `SdioFlags`

Reserved.

### `TargetObject`

Pointer to the next lower device object in the device stack. The caller should initialize this member to point to the device object below the caller's device object in the device stack.

### `DeviceGeneratesInterrupts`

Indicates, when **TRUE**, that the SD device generates interrupts. If **FALSE**, the device does not generate interrupts.

### `CallbackAtDpcLevel`

Indicates, when **TRUE**, that the callback routine must run at DISPATCH\_LEVEL. If **FALSE**, the callback must run at PASSIVE\_LEVEL. A device driver can often lower the latency of interrupt delivery by setting this member to **TRUE**; however, drivers that set this value to **TRUE** must be able to run at both PASSIVE\_LEVEL and DISPATCH\_LEVEL.

### `CallbackRoutine`

Pointer to a callback routine of type [**PSDBUS\_CALLBACK\_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nc-ntddsd-sdbus_callback_routine) that the bus driver calls when a device interrupt occurs. If **DeviceGeneratesInterrupts** is not set to **TRUE**, then the bus driver ignores the value in this member.

### `CallbackRoutineContext`

Pointer to the context information that the bus driver should pass to the callback routine when it dispatches a device interrupt.

## Remarks

An SD device driver that obtains a bus interface instance from the bus driver must initialize the interface. After obtaining an interface instance, the device driver passes the data in the SDBUS\_INTERFACE\_PARAMETERS structure to the routine pointed to by the **InitializeInterface** member of the [**SDBUS\_INTERFACE\_STANDARD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ns-ntddsd-sdbus_interface_standard) structure.

## See also

[**PSDBUS\_CALLBACK\_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nc-ntddsd-sdbus_callback_routine)

[**SDBUS\_INTERFACE\_STANDARD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ns-ntddsd-sdbus_interface_standard)