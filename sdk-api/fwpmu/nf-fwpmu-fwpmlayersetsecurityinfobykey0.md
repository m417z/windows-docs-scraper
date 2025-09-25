# FwpmLayerSetSecurityInfoByKey0 function

## Description

The **FwpmLayerSetSecurityInfoByKey0** function sets specified security information in the security descriptor of a layer object.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `key` [in, optional]

Type: **const GUID***

Unique identifier of the layer. See [Filtering Layer Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-) for a list of possible GUID values.

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

If the *key* parameter is **NULL** or if it is a **NULL** GUID, this function manages the security information of the layers container.

This function cannot be called from within a transaction. It will fail with
**FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

This function behaves like the standard Win32 [SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo) function. The caller needs the same standard access rights as described in the **SetSecurityInfo** reference topic.

**FwpmLayerSetSecurityInfoByKey0** is a specific implementation of FwpmLayerSetSecurityInfoByKey. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Filtering Layer Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-)

[FwpmLayerGetSecurityInfoByKey0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmlayergetsecurityinfobykey0)