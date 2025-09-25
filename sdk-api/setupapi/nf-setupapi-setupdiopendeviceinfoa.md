# SetupDiOpenDeviceInfoA function

## Description

The **SetupDiOpenDeviceInfo** function adds a device information element for a device instance to a device information set, if one does not already exist in the device information set, and retrieves information that identifies the device information element for the device instance in the device information set.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) to which **SetupDiOpenDeviceInfo** adds a device information element, if one does not already exist, for the device instance that is specified by *DeviceInstanceId*.

### `DeviceInstanceId` [in]

A pointer to a NULL-terminated string that supplies the device instance identifier of a device (for example, "Root\*PNP0500\0000"). If *DeviceInstanceId* is **NULL** or references a zero-length string, **SetupDiOpenDeviceInfo** adds a device information element to the supplied device information set, if one does not already exist, for the root device in the device tree.

### `hwndParent` [in, optional]

The handle to the top-level window to use for any user interface related to installing the device.

### `OpenFlags` [in]

A variable of DWORD type that controls how the device information element is opened. The value of this parameter can be one or more of the following:

#### DIOD_CANCEL_REMOVE

If this flag is specified and the device had been marked for pending removal, the operating system cancels the pending removal.

#### DIOD_INHERIT_CLASSDRVS

If this flag is specified, the resulting device information element inherits the class driver list, if any, associated with the device information set. In addition, if there is a selected driver for the device information set, that same driver is selected for the new device information element.

If the device information element was already present, its class driver list, if any, is replaced with the inherited list.

### `DeviceInfoData` [out, optional]

A pointer to a caller-supplied [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that receives information about the device information element for the device instance that is specified by *DeviceInstanceId*. The caller must set **cbSize** to **sizeof(**SP_DEVINFO_DATA**)**. This parameter is optional and can be **NULL**.

## Return value

**SetupDiOpenDeviceInfo** returns **TRUE** if it is successful. Otherwise, the function returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this device instance is being added to a set that has an associated class, the device class must be the same or the call will fail. In this case, a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_CLASS_MISMATCH.

If the new device information element is successfully opened but the caller-supplied *DeviceInfoData* buffer is invalid, this function returns **FALSE**. In this case, a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_USER_BUFFER. However, the device information element is added as a new member of the set anyway.

> [!NOTE]
> The setupapi.h header defines SetupDiOpenDeviceInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)

[SetupDiCreateDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfoa)

[SetupDiDeleteDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdideletedeviceinfo)

[SetupDiEnumDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinfo)