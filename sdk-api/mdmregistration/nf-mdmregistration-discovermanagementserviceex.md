# DiscoverManagementServiceEx function

## Description

Discovers the MDM service using a candidate server. The discovery process uses the
[[MS-MDE]: Mobile Device Enrollment Protocol](https://learn.microsoft.com/openspecs/windows_protocols/ms-mde/5c841535-042e-489e-913c-9d783d741267)
protocol.

## Parameters

### `pszUPN` [in]

Address of a **NULL**-terminated Unicode string containing the user principal name
(UPN) of the user requesting registration.

### `pszDiscoveryServiceCandidate` [in]

Address of a **NULL**-terminated Unicode string containing the discovery service
candidate to use in lieu of automatic discovery.

### `ppMgmtInfo` [out]

Address of a [MANAGEMENT_SERVICE_INFO](https://learn.microsoft.com/windows/win32/api/mdmregistration/ns-mdmregistration-management_service_info)
structure that contains pointers to the URIs of the management and authentication services.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. If the function
fails, the returned value describes the error. Possible
values include those listed at
[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants).

## Remarks

The caller of this function must be running as an elevated process.

This function is not available before Windows Server 2012 R2 Update and Windows 8.1 Update.

## See also

[DiscoverManagementService](https://learn.microsoft.com/windows/desktop/api/mdmregistration/nf-mdmregistration-discovermanagementservice)

[MANAGEMENT_SERVICE_INFO](https://learn.microsoft.com/windows/win32/api/mdmregistration/ns-mdmregistration-management_service_info)

[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants)

[MDM Registration Functions](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-functions)