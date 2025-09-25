# PFNQUERYREFERENCESTRING callback function (ks.h)

## Description

This routine creates a buffer from the paged pool and copies the reference string associated with the PDO into this buffer. It is the caller's responsibility to free the buffer using [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool).

## Parameters

### `Context` [in]

Pointer to a device extension of the device's PDO.

### `String` [in, out]

Pointer to a string containing the reference string associated with the PDO.

## Return value

None.

## Remarks

The driver can access this method through the **QueryReferenceString** member of the [BUS_INTERFACE_REFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-bus_interface_reference) structure.