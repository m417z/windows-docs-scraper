# RegisterDeviceWithManagementUsingAADCredentials function

## Description

Registers a device with a MDM service, using Azure Active Directory (AAD) credentials.

## Parameters

### `UserToken` [in]

The User to impersonate when attempting to get AAD token

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. If the function fails, the returned value describes the error. Possible
values include those listed at
[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants).

## Remarks

The caller of this function must be running as an elevated process.

## See also

[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants)

[MDM Registration Functions](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-functions)

[UnregisterDeviceWithManagement](https://learn.microsoft.com/windows/desktop/api/mdmregistration/nf-mdmregistration-unregisterdevicewithmanagement)