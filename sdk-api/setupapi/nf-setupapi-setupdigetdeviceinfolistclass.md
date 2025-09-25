# SetupDiGetDeviceInfoListClass function

## Description

The **SetupDiGetDeviceInfoListClass** function retrieves the GUID for the [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) associated with a device information set if the set has an associated class.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) to query.

### `ClassGuid` [out]

A pointer to variable of type GUID that receives the GUID for the associated class.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the specified device information set does not have an associated class because a class GUID was not specified when the set was created with [SetupDiCreateDeviceInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfolist), the function fails. In this case, a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NO_ASSOCIATED_CLASS.

If a device information set is for a remote computer, use [SetupDiGetDeviceInfoListDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinfolistdetaila) to get the associated remote computer handle and computer name.

## See also

[SetupDiCreateDeviceInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfolist)

[SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw)

[SetupDiGetDeviceInfoListDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinfolistdetaila)