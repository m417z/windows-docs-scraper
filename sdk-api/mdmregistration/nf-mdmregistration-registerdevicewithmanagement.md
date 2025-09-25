# RegisterDeviceWithManagement function

## Description

Registers a device with a MDM service, using the
[[MS-MDE]: Mobile Device Enrollment Protocol](https://learn.microsoft.com/openspecs/windows_protocols/ms-mde/5c841535-042e-489e-913c-9d783d741267).

## Parameters

### `pszUPN` [in]

Address of a **NULL**-terminated Unicode string containing the user principal name
(UPN) of the user requesting the registration.

**Windows 8.1:** This parameter was located after the *ppszMDMServiceUri* parameter in Windows 8.1.

### `ppszMDMServiceUri` [in]

Address of a **NULL**-terminated Unicode string containing the URI of the MDM
service.

### `ppzsAccessToken` [in]

Address of a **NULL**-terminated Unicode string containing a token acquired from
a Secure Token Service which the management service will use to validate the user.

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