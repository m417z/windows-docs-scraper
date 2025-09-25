# IoCreateSymbolicLink function

## Description

The **IoCreateSymbolicLink** routine sets up a symbolic link between a device object name and a user-visible name for the device.

## Parameters

### `SymbolicLinkName` [in]

Pointer to a buffered Unicode string that is the user-visible name.

### `DeviceName` [in]

Pointer to a buffered Unicode string that is the name of the driver-created device object.

## Return value

**IoCreateSymbolicLink** returns STATUS_SUCCESS if the symbolic link object was created.

## Remarks

WDM drivers do not name device objects and therefore should not use this routine. Instead, a WDM driver should call [IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface) to set up a symbolic link.

For more information about when to use **IoCreateSymbolicLink**, see [Named Device Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/named-device-objects).

## See also

[IoAssignArcName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioassignarcname)

[IoCreateUnprotectedSymbolicLink](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreateunprotectedsymboliclink)

[IoDeleteSymbolicLink](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodeletesymboliclink)

[IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface)