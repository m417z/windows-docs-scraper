# FwpmProviderDeleteByKey0 function

## Description

The **FwpmProviderDeleteByKey0** function removes a provider from the system.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `key` [in]

Type: **const GUID***

Unique identifier of the object being removed from the system. This is the same GUID that was specified when the application called [FwpmProviderAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovideradd0).

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The provider was successfully deleted. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

This function cannot be called from within a read-only transaction. It will fail with
**FWP_E_INCOMPATIBLE_TXN**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

This function can be called within a dynamic session if the corresponding object was added during the same session. If this function is called for an object that was added during a different dynamic session, it will fail with **FWP_E_WRONG_SESSION**. If this function is called for an object that was not added during a dynamic session, it will fail with **FWP_E_DYNAMIC_SESSION_IN_PROGRESS**.

The caller needs [DELETE](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights) access to the provider. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmProviderDeleteByKey0** is a specific implementation of FwpmProviderDeleteByKey. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FwpmProviderAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovideradd0)