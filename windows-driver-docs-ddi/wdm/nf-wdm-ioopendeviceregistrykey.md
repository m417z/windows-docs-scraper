## Description

The IoOpenDeviceRegistryKey routine returns a handle to a registry state location for a particular device instance.

## Parameters

### `DeviceObject` [in]

Pointer to the [physical device object (PDO)](https://learn.microsoft.com/windows-hardware/drivers/kernel/when-are-wdm-device-objects-created-) of the device instance for which the registry state location is to be opened.

### `DevInstKeyType` [in]

Specifies flags indicating whether to open a device-specific hardware key or a driver-specific software key. The flags also indicate whether the key is relative to the current hardware profile. For more information about hardware and software keys, see [Introduction to Registry Keys for Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/introduction-to-registry-keys-for-drivers).

The flags are defined as follows:

#### PLUGPLAY_REGKEY_DEVICE

Open the device's hardware key, a device-specific registry state location that contains information about the device. This flag cannot be specified with PLUGPLAY_REGKEY_DRIVER.

#### PLUGPLAY_REGKEY_DRIVER

Open the device's software key, a device-specific registry state location for storing driver-specific information. This flag cannot be specified with PLUGPLAY_REGKEY_DEVICE.

#### PLUGPLAY_REGKEY_CURRENT_HWPROFILE

Hardware profiles are deprecated and state should not be stored relative to a hardware profile.

Open a key relative to the current hardware profile for device or driver information. This allows the driver to access configuration information that is hardware-profile-specific. The caller must specify either PLUGPLAY_REGKEY_DEVICE or PLUGPLAY_REGKEY_DRIVER with this flag.

### `DesiredAccess` [in]

Specifies the [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that represents the access the caller needs to the key. See the [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) routine for a description of each KEY_*XXX* access right.

### `DeviceRegKey` [out]

Pointer to a caller-allocated buffer that, on successful return, contains a handle to the requested registry state location.

## Return value

**IoOpenDeviceRegistryKey** returns STATUS_SUCCESS if the call was successful. Possible error return values include the following:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | Possibly indicates that the caller specified an illegal set of *DevInstKeyType* flags or provided a *DeviceObject* that is not a valid PDO. |

## Remarks

The driver must call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwclose) to close the handle returned from this routine when access is no longer required.

The registry keys opened by this routine are nonvolatile.

User-mode setup applications can access these registry keys by using [CM_Open_DevNode_Key](https://learn.microsoft.com/windows/win32/api/cfgmgr32/nf-cfgmgr32-cm_open_devnode_key) or [device information functions](https://learn.microsoft.com/windows-hardware/drivers/install/using-device-installation-functions#device-information-functions) such as [SetupDiOpenDevRegKey](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdiopendevregkey) or [SetupDiCreateDevRegKey](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdicreatedevregkeya).

To pre-populate state in these registry state locations at driver package installation time, use [INF AddReg directives](https://learn.microsoft.com/windows-hardware/drivers/install/inf-addreg-directive) in an INF file.

Callers of **IoOpenDeviceRegistryKey** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

## See also

[Introduction to Registry Keys for Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/introduction-to-registry-keys-for-drivers)

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwclose)

[Device nodes and device stacks](https://learn.microsoft.com/windows-hardware/drivers/gettingstarted/device-nodes-and-device-stacks)