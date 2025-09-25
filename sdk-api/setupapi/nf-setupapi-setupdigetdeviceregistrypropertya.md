# SetupDiGetDeviceRegistryPropertyA function

## Description

The **SetupDiGetDeviceRegistryProperty** function retrieves a specified Plug and Play device property.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device for which to retrieve a Plug and Play property.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*.

### `Property` [in]

One of the following values that specifies the property to be retrieved:

#### SPDRP_ADDRESS

The function retrieves the device's address.

#### SPDRP_BUSNUMBER

The function retrieves the device's bus number.

#### SPDRP_BUSTYPEGUID

The function retrieves the GUID for the device's bus type.

#### SPDRP_CAPABILITIES

The function retrieves a bitwise OR of the following CM_DEVCAP_*Xxx*  flags in a DWORD. The device capabilities that are represented by these flags correspond to the device capabilities that are represented by the members of the [DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ns-wdm-_device_capabilities) structure. The CM_DEVCAP_Xxx constants are defined in *Cfgmgr32.h.*

| CM_DEVCAP_Xxx flag | Corresponding DEVICE_CAPABILITIES structure member |
| --- | --- |
| CM_DEVCAP_LOCKSUPPORTED | **LockSupported** |
| CM_DEVCAP_EJECTSUPPORTED | **EjectSupported** |
| CM_DEVCAP_REMOVABLE | **Removable** |
| CM_DEVCAP_DOCKDEVICE | **DockDevice** |
| CM_DEVCAP_UNIQUEID | **UniqueID** |
| CM_DEVCAP_SILENTINSTALL | **SilentInstall** |
| CM_DEVCAP_RAWDEVICEOK | **RawDeviceOK** |
| CM_DEVCAP_SURPRISEREMOVALOK | **SurpriseRemovalOK** |
| CM_DEVCAP_HARDWAREDISABLED | **HardwareDisabled** |
| CM_DEVCAP_NONDYNAMIC | **NonDynamic** |

#### SPDRP_CHARACTERISTICS

The function retrieves a bitwise OR of a device's characteristics flags in a DWORD. For a description of these flags, which are defined in *Wdm.h* and *Ntddk.h*, see the *DeviceCharacteristics* parameter of the [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iocreatedevice) function.

#### SPDRP_CLASS

The function retrieves a REG_SZ string that contains the [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) of a device.

#### SPDRP_CLASSGUID

The function retrieves a REG_SZ string that contains the GUID that represents the device setup class of a device.

#### SPDRP_COMPATIBLEIDS

The function retrieves a REG_MULTI_SZ string that contains the list of compatible IDs for a device. For information about compatible IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

#### SPDRP_CONFIGFLAGS

The function retrieves a bitwise OR of a device's configuration flags in a DWORD value. The configuration flags are represented by the CONFIGFLAG_*Xxx* bitmasks that are defined in *Regstr.h*.

#### SPDRP_DEVICE_POWER_DATA

(Windows XP and later) The function retrieves a [CM_POWER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ns-wdm-cm_power_data_s) structure that contains the device's power management information.

#### SPDRP_DEVICEDESC

The function retrieves a REG_SZ string that contains the description of a device.

#### SPDRP_DEVTYPE

The function retrieves a DWORD value that represents the device's type. For more information, see [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types).

#### SPDRP_DRIVER

The function retrieves a string that identifies the device's [software key](https://learn.microsoft.com/windows-hardware/drivers/) (sometimes called the [driver key](https://learn.microsoft.com/windows-hardware/drivers/)). For more information about driver keys, see [Registry Trees and Keys for Devices and Drivers](https://learn.microsoft.com/windows-hardware/drivers/install/registry-trees-and-keys).

#### SPDRP_ENUMERATOR_NAME

The function retrieves a REG_SZ string that contains the name of the device's [enumerator](https://learn.microsoft.com/windows-hardware/drivers/).

#### SPDRP_EXCLUSIVE

The function retrieves a DWORD value that indicates whether a user can obtain exclusive use of the device. The returned value is one if exclusive use is allowed, or zero otherwise. For more information, see [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iocreatedevice).

#### SPDRP_FRIENDLYNAME

The function retrieves a REG_SZ string that contains the friendly name of a device.

#### SPDRP_HARDWAREID

The function retrieves a REG_MULTI_SZ string that contains the list of hardware IDs for a device. For information about hardware IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

#### SPDRP_INSTALL_STATE

(Windows XP and later) The function retrieves a DWORD value that indicates the installation state of a device. The installation state is represented by one of the CM_INSTALL_STATE_*Xxx* values that are defined in *Cfgmgr32.h*. The CM_INSTALL_STATE_*Xxx* values correspond to the [DEVICE_INSTALL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ne-wdm-_device_install_state) enumeration values.

#### SPDRP_LEGACYBUSTYPE

The function retrieves the device's legacy bus type as an INTERFACE_TYPE value (defined in *Wdm.h* and *Ntddk.h*).

#### SPDRP_LOCATION_INFORMATION

The function retrieves a REG_SZ string that contains the hardware location of a device.

#### SPDRP_LOCATION_PATHS

(Windows Server 2003 and later) The function retrieves a REG_MULTI_SZ string that represents the location of the device in the device tree.

#### SPDRP_LOWERFILTERS

The function retrieves a REG_MULTI_SZ string that contains the names of a device's lower-filter drivers.

#### SPDRP_MFG

The function retrieves a REG_SZ string that contains the name of the device manufacturer.

#### SPDRP_PHYSICAL_DEVICE_OBJECT_NAME

The function retrieves a REG_SZ string that contains the name that is associated with the device's PDO. For more information, see [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iocreatedevice).

#### SPDRP_REMOVAL_POLICY

(Windows XP and later) The function retrieves the device's current removal policy as a DWORD that contains one of the CM_REMOVAL_POLICY_*Xxx* values that are defined in *Cfgmgr32.h*.

#### SPDRP_REMOVAL_POLICY_HW_DEFAULT

(Windows XP and later) The function retrieves the device's hardware-specified default removal policy as a DWORD that contains one of the CM_REMOVAL_POLICY_*Xxx* values that are defined in *Cfgmgr32.h*.

#### SPDRP_REMOVAL_POLICY_OVERRIDE

(Windows XP and later) The function retrieves the device's override removal policy (if it exists) from the registry, as a DWORD that contains one of the CM_REMOVAL_POLICY_*Xxx* values that are defined in *Cfgmgr32.h*.

#### SPDRP_SECURITY

The function retrieves a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/ns-ntifs-_security_descriptor) structure for a device.

#### SPDRP_SECURITY_SDS

The function retrieves a REG_SZ string that contains the device's security descriptor. For information about security descriptor strings, see [Security Descriptor Definition Language (Windows)](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-definition-language). For information about the format of security descriptor strings, see Security Descriptor Definition Language (Windows).

#### SPDRP_SERVICE

The function retrieves a REG_SZ string that contains the service name for a device.

#### SPDRP_UI_NUMBER

The function retrieves a DWORD value set to the value of the **UINumber** member of the device's [DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ns-wdm-_device_capabilities) structure.

#### SPDRP_UI_NUMBER_DESC_FORMAT

The function retrieves a format string (REG_SZ) used to display the **UINumber** value.

#### SPDRP_UPPERFILTERS

The function retrieves a REG_MULTI_SZ string that contains the names of a device's upper filter drivers.

### `PropertyRegDataType` [out, optional]

A pointer to a variable that receives the data type of the property that is being retrieved. This is one of the standard registry data types. This parameter is optional and can be **NULL**.

### `PropertyBuffer` [out, optional]

A pointer to a buffer that receives the property that is being retrieved. If this parameter is set to **NULL**, and *PropertyBufferSize* is also set to zero, the function returns the required size for the buffer in *RequiredSize*.

### `PropertyBufferSize` [in]

The size, in bytes, of the *PropertyBuffer*  buffer.

### `RequiredSize` [out, optional]

A pointer to a variable of type DWORD that receives the required size, in bytes, of the *PropertyBuffer* buffer that is required to hold the data for the requested property. This parameter is optional and can be **NULL**.

## Return value

**SetupDiGetDeviceRegistryProperty** returns **TRUE** if the call was successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). **SetupDiGetDeviceRegistryProperty** returns the ERROR_INVALID_DATA error code if the requested property does not exist for a device or if the property data is not valid.

## See also

[IoGetDeviceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iogetdeviceproperty)

[SetupDiGetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassregistrypropertya)

[SetupDiSetClassRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclassregistrypropertya)

[SetupDiSetDeviceRegistryProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdeviceregistrypropertya)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDiGetDeviceRegistryProperty as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).