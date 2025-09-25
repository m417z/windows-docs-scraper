## Description

The **FwpmCalloutSetSecurityInfoByKey0** function sets specified security information in the security descriptor of a callout object.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `key` [in, optional]

Pointer to a GUID that uniquely identifies the callout. This GUID was specified in the **calloutKey** member of the *callout* parameter when the application called **[FwpmCalloutAdd0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutadd0)** for this object.

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
| --- | --- |
| **ERROR_SUCCESS**<br>0 | The security descriptor was set successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

If the *key* parameter is **NULL** or if it is a **NULL** GUID, this function manages the security information of the callouts container.

This function cannot be called from within a transaction, it fails with **FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

This function can be called within a dynamic session if the corresponding object was added during the same session. If this function is called for an object that was added during a different dynamic session, it fails with **FWP_E_WRONG_SESSION**. If this function is called for an object that was not added during a dynamic session, it fails with **FWP_E_DYNAMIC_SESSION_IN_PROGRESS**.

This function behaves like the standard Win32 **[SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo)** function. The caller needs the same standard access rights as described in the **SetSecurityInfo** reference topic.

**FwpmCalloutSetSecurityInfoByKey0** is a specific implementation of **FwpmCalloutSetSecurityInfoByKey**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[FwpmCalloutAdd0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutadd0)**
- **[SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo)**
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)