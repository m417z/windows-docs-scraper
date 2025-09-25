# IoCreateUnprotectedSymbolicLink function

## Description

The **IoCreateUnprotectedSymbolicLink** routine sets up an unprotected symbolic link between a device object name and a corresponding Win32-visible name.

## Parameters

### `SymbolicLinkName` [in]

Supplies the symbolic link name as a Unicode string.

### `DeviceName` [in]

Supplies the name of the device object to which the symbolic link name refers.

## Return value

**IoCreateUnprotectedSymbolicLink** returns the final status of the operation.

## Remarks

WDM drivers do not name device objects and therefore should not use this routine. Instead, a WDM driver should call [IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface) to set up a symbolic link.

**IoCreateUnprotectedSymbolicLink** can be used by drivers if the user needs to be able to manipulate the symbolic link. For example, the parallel and serial drivers create unprotected symbolic links for LPTx and COMx, so that users can manipulate and reassign them by using the MODE command.

In general, drivers should call this routine instead of [IoCreateSymbolicLink](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatesymboliclink) if a protected subsystem lets end users change what a named device references as, for example, when using LPT1 to access a network printer.

For more information about when to use **IoCreateSymbolicLink**, see [Named Device Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/named-device-objects).

## See also

[IoAssignArcName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioassignarcname)

[IoCreateSymbolicLink](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatesymboliclink)

[IoDeleteSymbolicLink](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodeletesymboliclink)

[IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface)