## Description

The **IPsecDospSetSecurityInfo0** function sets specified security information in the security descriptor of the IPsec DoS Protection database.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `securityInfo` [in]

The type of security information to set.

### `sidOwner` [in, optional]

The owner's security identifier (SID) to be set in the security descriptor.

### `sidGroup` [in, optional]

The group's SID to be set in the security descriptor.

### `dacl` [in, optional]

The discretionary access control list (DACL) to be set in the security descriptor.

### `sacl` [in, optional]

The system access control list (SACL) to be set in the security descriptor.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The security information was set successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

This function behaves like the standard Win32 **[SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo)** function. The caller needs the same standard access rights as described in the **SetSecurityInfo** reference topic.

**IPsecDospSetSecurityInfo0** is a specific implementation of **IPsecDospSetSecurityInfo**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[IPsecDospGetSecurityInfo0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-ipsecdospgetsecurityinfo0)**
- **[SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo)**
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)