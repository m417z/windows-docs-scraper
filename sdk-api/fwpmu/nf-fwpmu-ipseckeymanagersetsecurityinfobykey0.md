# IPsecKeyManagerSetSecurityInfoByKey0 function

## Description

The **IPsecKeyManagerSetSecurityInfoByKey0** function sets specified security information in the security descriptor that controls access to the key manager.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

A handle to an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `reserved`

Type: **const void***

Reserved. Should be specified as NULL.

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
| **ERROR_SUCCESS**<br><br>0 | The security information was successfully set. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## See also

[WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)