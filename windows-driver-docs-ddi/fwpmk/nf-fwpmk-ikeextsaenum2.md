## Description

The **IkeextSaEnum2** function returns the next page of results from the IKE/AuthIP security association (SA) enumerator.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `enumHandle` [in]

Handle for an IKE/AuthIP SA enumeration. Call **[IkeextSaCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-ikeextsacreateenumhandle0)** to obtain an enumeration handle.

### `numEntriesRequested` [in]

Number of enumeration entries requested.

### `entries` [out]

Addresses of the enumeration entries.

### `numEntriesReturned` [out]

The number of enumeration entries returned.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The SAs were enumerated successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

If the *numEntriesReturned* is less than the *numEntriesRequested*, the enumeration is exhausted.

The returned array of entries (but not the individual entries themselves) must be freed by a call to **[FwpmFreeMemory0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfreememory0)**.

A subsequent call using the same enumeration handle will return the next set of items following those in the last output buffer.

**IkeextSaEnum1** works on a snapshot of the SAs taken at the time the enumeration handle was created.

**IkeextSaEnum1** is a specific implementation of **IkeextSaEnum**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[IkeextSaCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-ikeextsacreateenumhandle0)**
- **[FwpmFreeMemory0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfreememory0)**
- [IKEEXT_SA_DETAILS2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_sa_details2)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)
- [IKE/AuthIP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-ike-functions)
- [WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)