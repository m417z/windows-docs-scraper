# SetupDiCreateDeviceInfoW function

## Description

The **SetupDiCreateDeviceInfo** function creates a new device information element and adds it as a new member to the specified device information set.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for the local computer.

### `DeviceName` [in]

A pointer to a NULL-terminated string that supplies either a full [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) (for example, "Root\*PNP0500\0000") or a root-enumerated [device ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-ids) without the enumerator prefix and instance identifier suffix (for example, "*PNP0500"). The root-enumerated device identifier can be used only if the DICD_GENERATE_ID flag is specified in the *CreationFlags* parameter.

### `ClassGuid` [in]

A pointer to the [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) GUID for the device. If the device setup class of the device is not known, set **ClassGuid* to a GUID_NULL structure.

### `DeviceDescription` [in, optional]

A pointer to a NULL-terminated string that supplies the text description of the device. This pointer is optional and can be **NULL**.

### `hwndParent` [in, optional]

A handle to the top-level window to use for any user interface that is related to installing the device. This handle is optional and can be **NULL**.

### `CreationFlags` [in]

A variable of type DWORD that controls how the device information element is created. Can be a combination of the following values:

#### DICD_GENERATE_ID

If this flag is specified, *DeviceName* contains only a Root-enumerated [device ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-ids) and the system uses that ID to generate a full [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) for the new device information element.

Call **SetupDiGetDeviceInstanceId** to retrieve the device instance ID that was generated for this device information element.

#### DICD_INHERIT_CLASSDRVS

If this flag is specified, the resulting device information element inherits the class driver list, if any, associated with the device information set. In addition, if there is a selected driver for the device information set, that same driver is selected for the new device information element.

### `DeviceInfoData` [out, optional]

A pointer to a [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that receives the new device information element. This pointer is optional and can be **NULL**. If the structure is supplied, the caller must set the **cbSize** member of this structure to **sizeof(**SP_DEVINFO_DATA**)** before calling the function. For more information, see the following **Remarks** section.

##### - CreationFlags.DICD_GENERATE_ID

If this flag is specified, *DeviceName* contains only a Root-enumerated [device ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-ids) and the system uses that ID to generate a full [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) for the new device information element.

Call **SetupDiGetDeviceInstanceId** to retrieve the device instance ID that was generated for this device information element.

##### - CreationFlags.DICD_INHERIT_CLASSDRVS

If this flag is specified, the resulting device information element inherits the class driver list, if any, associated with the device information set. In addition, if there is a selected driver for the device information set, that same driver is selected for the new device information element.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of this function must be a member of the Administrators group.

If this device instance is being added to a set that has an associated class, the device class must be the same or the call fails. In this case, a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_CLASS_MISMATCH.

If the specified device instance is the same as an existing device instance key in the registry, the call fails. In this case, a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_DEVINST_ALREADY_EXISTS. This occurs only if the DICD_GENERATE_ID flag is not set.

If the new device information element was successfully created but the caller-supplied *DeviceInfoData* buffer is invalid, the function returns **FALSE**. In this case, a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_USER_BUFFER. However, the device information element will have been added as a new member of the set already.

The *DeviceInfoSet* must only contain elements on the local computer.

> [!NOTE]
> The setupapi.h header defines SetupDiCreateDeviceInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)

[SetupDiDeleteDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdideletedeviceinfo)

[SetupDiEnumDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinfo)

[SetupDiOpenDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinfoa)