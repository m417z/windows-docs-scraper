# FwpmvSwitchEventsSetSecurityInfo0 function

## Description

The **FwpmvSwitchEventsSetSecurityInfo0** function sets specified security information in the security descriptor for a vSwitch event.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

A handle to an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

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

## Remarks

This function cannot be called from within a transaction. It will fail with
**FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

This function cannot be called from within a dynamic session. It will fail with
**FWP_E_DYNAMIC_SESSION_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about sessions.

This function behaves like the standard Win32 [SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo) function. The caller needs the same standard access rights as described in the **SetSecurityInfo** reference topic.

**FwpmvSwitchEventsSetSecurityInfo0** is a specific implementation of FwpmvSwitchEventsSetSecurityInfo. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FwpmvSwitchEventsGetSecurityInfo0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmvswitcheventsgetsecurityinfo0)

[WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)