# IPsecSaContextDeleteById0 function

## Description

The **IPsecSaContextDeleteById0** function deletes an IPsec security association (SA) context.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `id` [in]

Type: **UINT64**

A runtime identifier for the object being removed from the system. This identifier was received from the system when the application called [IPsecSaContextCreate0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextcreate0).

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The IPsec SA context was successfully deleted. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

This function cannot be called from within a transaction. It will fail with
**FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

This function cannot be called from within a dynamic session. The call will fail with **FWP_E_DYNAMIC_SESSION_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about dynamic sessions.

The caller needs [DELETE](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights) access to the IPsec security associations database. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**IPsecSaContextDeleteById0** is a specific implementation of IPsecSaContextDeleteById. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IPsecSaContextCreate0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextcreate0)