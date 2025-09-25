# SetupDiCreateDeviceInfoList function

## Description

The **SetupDiCreateDeviceInfoList** function creates an empty [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) and optionally associates the set with a [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) and a top-level window.

## Parameters

### `ClassGuid` [in, optional]

A pointer to the **GUID** of the device setup class to associate with the newly created device information set. If this parameter is specified, only devices of this class can be included in this device information set. If this parameter is set to **NULL**, the device information set is not associated with a specific device setup class.

### `hwndParent` [in, optional]

A handle to the top-level window to use for any user interface that is related to non-device-specific actions (such as a select-device dialog box that uses the global class driver list). This handle is optional and can be **NULL**. If a specific top-level window is not required, set *hwndParent* to **NULL**.

## Return value

The function returns a handle to an empty device information set if it is successful. Otherwise, it returns **INVALID_HANDLE_VALUE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of this function must delete the returned device information set when it is no longer needed by calling **SetupDiDestroyDeviceInfoList**.

To create a device information list for a remote computer use [SetupDiCreateDeviceInfoListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfolistexa).

## See also

[SetupDiCreateDeviceInfoListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfolistexa)

[SetupDiDestroyDeviceInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidestroydeviceinfolist)

[SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw)

[SetupDiGetDeviceInfoListClass](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinfolistclass)