# PFNDEREFERENCEDEVICEOBJECT callback function (ks.h)

## Description

The driver can use this routine to decrement the reference count of the PDO.

## Parameters

### `Context` [in]

Pointer to a device extension of the device's PDO.

## Remarks

Minidrivers access this method through the **DereferenceDeviceObject** member of the [BUS_INTERFACE_REFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-bus_interface_reference) structure.

When the PDO's reference count is 0, it becomes eligible for removal. Note that this condition does not guarantee removal.