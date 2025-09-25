## Description

The **FwpmEngineGetSecurityInfo0** function retrieves a copy of the security descriptor for the filter engine.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `securityInfo` [in]

The type of security information to retrieve.

### `sidOwner` [out]

The owner security identifier (SID) in the returned security descriptor.

### `sidGroup` [out]

The primary group security identifier (SID) in the returned security descriptor.

### `dacl` [out]

The discretionary access control list (DACL) in the returned security descriptor.

### `sacl` [out]

The system access control list (SACL) in the returned security descriptor.

### `securityDescriptor` [out]

The returned security descriptor.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The security descriptor was retrieved successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

The returned *securityDescriptor* parameter must be freed through a call to **[FwpmFreeMemory0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfreememory0)**. The other four (optional) returned parameters must not be freed, as they point to addresses within the *securityDescriptor* parameter.

This function behaves like the standard Win32 **[GetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getsecurityinfo)** function. The caller needs the same standard access rights as described in the GetSecurityInfo reference topic.

**FwpmEngineGetSecurityInfo0** is a specific implementation of **FwpmEngineGetSecurityInfo**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[FwpmFreeMemory0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfreememory0)**
- **[GetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getsecurityinfo)**
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)