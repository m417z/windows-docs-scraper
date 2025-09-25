# GetDeviceRegistrationInfo function

## Description

Retrieves the device registration information.

## Parameters

### `DeviceInformationClass` [in]

Contains the maximum length that can be returned through the *pszHyperlink*
parameter.

### `ppDeviceRegistrationInfo` [out]

Details of the device registration.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. .

## Remarks

The caller of this function must be running as an elevated process.

## See also

[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants)

[MDM Registration Functions](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-functions)