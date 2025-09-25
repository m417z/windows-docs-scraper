# FwpmSubLayerSetSecurityInfoByKey0 function

## Description

The **FwpmSubLayerSetSecurityInfoByKey0** function sets specified security information in the security descriptor of a sublayer.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `key` [in, optional]

Type: **const GUID***

Unique identifier of the sublayer. This must be the same GUID that was specified when the application called [FwpmSubLayerAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsublayeradd0).

### `securityInfo` [in]

Type: **[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)**

The type of security information to set.

### `sidOwner` [in, optional]

Type: **const [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)***

The owner's security identifier (SID) to be set in the security descriptor.

### `sidGroup` [in, optional]

Type: **const [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)***

The group's SID to be set in the security descriptor.

### `dacl` [in, optional]

Type: **const [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)***

The discretionary access control list (DACL) to be set in the security descriptor.

### `sacl` [in, optional]

Type: **const [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)***

The system access control list (SACL) to be set in the security descriptor.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The security descriptor was set successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If the *key* parameter is **NULL** or if it is a **NULL** GUID, this function manages the security information of the sublayers container.

This function cannot be called from within a transaction. It will fail with
**FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

This function can be called within a dynamic session if the corresponding object was added during the same session. If this function is called for an object that was added during a different dynamic session, it will fail with **FWP_E_WRONG_SESSION**. If this function is called for an object that was not added during a dynamic session, it will fail with **FWP_E_DYNAMIC_SESSION_IN_PROGRESS**.

This function behaves like the standard Win32 [SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo) function. The caller needs the same standard access rights as described in the **SetSecurityInfo** reference topic.

**FwpmSubLayerSetSecurityInfoByKey0** is a specific implementation of FwpmSubLayerSetSecurityInfoByKey. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FwpmSubLayerGetSecurityInfoByKey0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsublayergetsecurityinfobykey0)