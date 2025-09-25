# IPsecKeyManagerGetSecurityInfoByKey0 function

## Description

The **IPsecKeyManagerGetSecurityInfoByKey0** function retrieves a copy of the security descriptor that controls access to the key manager.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

A handle to an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `reserved`

Type: **const void***

Reserved. Must be set to NULL.

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
| **ERROR_SUCCESS**<br><br>0 | The security descriptor was successfully retrieved. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## See also

[WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)