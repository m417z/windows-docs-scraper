# IoOpenDeviceInterfaceRegistryKey function

## Description

The **IoOpenDeviceInterfaceRegistryKey** routine returns a handle to a registry key for storing information about a particular device interface instance.

## Parameters

### `SymbolicLinkName` [in]

Pointer to a string identifying the device interface instance. This string was obtained from a previous call to [IoGetDeviceInterfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfaces), [IoGetDeviceInterfaceAlias](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfacealias), or [IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface).

### `DesiredAccess` [in]

Specifies the [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that represents the access the caller requires to the key, such as KEY_READ, KEY_WRITE, or KEY_ALL_ACCESS. See [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) for a description of each KEY_*XXX* access right.

### `DeviceInterfaceRegKey` [out]

Pointer to a returned handle to the requested registry key if the call is successful.

## Return value

**IoOpenDeviceInterfaceRegistryKey** returns STATUS_SUCCESS if the call was successful. Possible error return values include the following.

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The routine was not able to locate a registry key for the device interface instance, probably due to an error in the *SymbolicLinkName*. |
| **STATUS_OBJECT_PATH_NOT_FOUND** | The routine was not able to locate a registry key for the device interface instance, probably due to an error in the *SymbolicLinkName*. |
| **STATUS_INVALID_PARAMETER** | Possibly indicates an error in the *SymbolicLinkName*. |

## Remarks

**IoOpenDeviceInterfaceRegistryKey** opens a nonvolatile subkey of the registry key for the device interface instance specified by *SymbolicLinkName*. Drivers can store information in this subkey that is specific to this instance of the device interface, such as the default resolution for a camera. User-mode applications can access this subkey using **SetupDi*Xxx*** routines.

The driver must call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close the handle returned from this routine when access is no longer required.

Callers of **IoOpenDeviceInterfaceRegistryKey** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[IoGetDeviceInterfaceAlias](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfacealias)

[IoGetDeviceInterfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfaces)

[IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)