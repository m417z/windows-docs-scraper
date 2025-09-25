# SetupDiBuildDriverInfoList function

## Description

The **SetupDiBuildDriverInfoList** function builds a list of drivers that is associated with a specific device or with the global class driver list for a device information set.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) to contain the driver list, either globally for all device information elements or specifically for a single device information element. The device information set must not contain remote device information elements.

### `DeviceInfoData` [in, out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure for the device information element in *DeviceInfoSet* that represents the device for which to build a driver list. This parameter is optional and can be **NULL**. If this parameter is specified, the list is associated with the specified device. If this parameter is **NULL**, the list is associated with the global class driver list for *DeviceInfoSet*.

If the class of this device is updated because of building a compatible driver list, *DeviceInfoData.***ClassGuid** is updated upon return.

### `DriverType` [in]

The type of driver list to build. Must be one of the following values:

| Value | Meaning |
| --- | --- |
| **SPDIT_CLASSDRIVER** | Build a list of class drivers. If *DeviceInfoData* is **NULL**, this driver list type must be specified. |
| **SPDIT_COMPATDRIVER** | Build a list of compatible drivers. *DeviceInfoData* must not be **NULL** if this driver list type is specified. |

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The device information set should be for a local computer because **SetupDiBuildDriverInfoList** searches for drivers only on a local computer. If the device information set is for a remote computer, the function returns **TRUE** but does not actually update the existing driver list for the device information set or, if supplied, the driver list for the device information element.

The caller can set **Flags** in the [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) that are associated with the device information set or with a specific device (*DeviceInfoData*) to control how the list is built. For example, the caller can set the **DI_FLAGSEX_ALLOWEXCLUDEDDRVS** flag to include drivers that are marked Exclude From Select.

A driver is "Exclude From Select" if either it is marked **ExcludeFromSelect** in the INF file or it is a driver for a device whose whole setup class is marked **NoInstallClass** or **NoUseClass** in the class installer INF file. Drivers for PnP devices are typically "Exclude From Select"; PnP devices should not be manually installed. To build a list of driver files for a PnP device a caller of **SetupDiBuildDriverInfoList** must set this flag.

The **DriverPath** in the [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) contains either a path of a directory that contain INF files or a path of a specific INF file. If **DI_ENUMSINGLEINF** is set, **DriverPath** contains a path of a single INF file. If **DriverPath** is **NULL**, this function builds the driver list from the default INF file location, %SystemRoot%\inf.

After this function has built the specified driver list, the caller can enumerate the elements of the list by calling [SetupDiEnumDriverInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdriverinfoa).

If the driver list is associated with a device instance (that is, *DeviceInfoData* is specified), the resulting list is composed of drivers that have the same class as the device instance with which they are associated. If this is a global class driver list (that is, *DriverType* is **SPDIT_CLASSDRIVER** and *DeviceInfoData* is not specified), the class that is used when building the list is the class associated with the device information set. If the device information set has no associated class, drivers of all classes are used when building the list.

Another thread can terminate the building of a driver list by a call to [SetupDiCancelDriverInfoSearch](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicanceldriverinfosearch).

The *DeviceInfoSet* must only contain elements on the local computer. This function only searches for local drivers.

## See also

[SetupDiCancelDriverInfoSearch](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicanceldriverinfosearch)

[SetupDiDestroyDriverInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidestroydriverinfolist)

[SetupDiEnumDriverInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdriverinfoa)