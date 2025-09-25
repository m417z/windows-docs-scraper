# FwpmProviderContextGetSecurityInfoByKey0 function

## Description

The **FwpmProviderContextGetSecurityInfoByKey0** function retrieves a copy of the security descriptor for a provider context object.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `key` [in, optional]

Type: **const GUID***

Unique identifier of the provider context. This is a pointer to the same GUID that was specified when the application called [FwpmProviderContextAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextadd0) for this object.

### `securityInfo` [in]

Type: **[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)**

The type of security information to retrieve.

### `sidOwner` [out, optional]

Type: **[PSID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)***

The owner security identifier (SID) in the returned security descriptor.

### `sidGroup` [out, optional]

Type: **[PSID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)***

The primary group security identifier (SID) in the returned security descriptor.

### `dacl` [out, optional]

Type: **[PACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)***

The discretionary access control list (DACL) in the returned security descriptor.

### `sacl` [out, optional]

Type: **[PACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)***

The system access control list (SACL) in the returned security descriptor.

### `securityDescriptor` [out]

Type: **[PSECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)***

The returned security descriptor.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The security descriptor was retrieved successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If the *key* parameter is **NULL** or if it is a **NULL** GUID, this function manages the security information of the provider contexts container.

The returned *securityDescriptor* parameter must be freed through a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0). The other four (optional) returned parameters must not be freed, as they point to addresses within the *securityDescriptor* parameter.

This function behaves like the standard Win32 [GetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getsecurityinfo) function. The caller needs the same standard access rights as described in the **GetSecurityInfo** reference topic.

**FwpmProviderContextGetSecurityInfoByKey0** is a specific implementation of FwpmProviderContextGetSecurityInfoByKey. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FwpmProviderContextSetSecurityInfoByKey0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextsetsecurityinfobykey0)