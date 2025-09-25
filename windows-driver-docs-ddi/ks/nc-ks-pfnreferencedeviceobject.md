# PFNREFERENCEDEVICEOBJECT callback function (ks.h)

## Description

The driver can use this routine to increment the reference count of the PDO.

## Parameters

### `Context` [in]

Pointer to a device extension of the device's PDO.

## Remarks

The driver can access this method through the **ReferenceDeviceObject** member of the [BUS_INTERFACE_REFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-bus_interface_reference) structure.

The device object remains active and enumerated until the reference count returns to 0.