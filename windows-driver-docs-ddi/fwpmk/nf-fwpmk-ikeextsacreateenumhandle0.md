## Description

The **IkeextSaCreateEnumHandle0** function creates a handle used to enumerate a set of Internet Key Exchange (IKE) and Authenticated Internet Protocol (AuthIP) security association (SA) objects.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `enumTemplate` [in, optional]

Template for selectively restricting the enumeration.

### `enumHandle` [out]

Address of a **HANDLE** variable. On function return, it contains the handle of the newly created enumeration.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The enumeration was created successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

If *enumTemplate* is **NULL**, all IKE/AuthIP SA objects are returned.

The caller must call **[IkeextSaDestroyEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-ikeextsadestroyenumhandle0)** to free the returned handle.

The caller needs [FWPM_ACTRL_ENUM](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) and [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the IKE/AuthIP security associations database. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**IkeextSaCreateEnumHandle0** is a specific implementation of **IkeextSaCreateEnumHandle**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[IkeextSaDestroyEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-ikeextsadestroyenumhandle0)**
- [FWPM_ACTRL_ENUM](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers)
- [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers)
- [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)
- [IKE/AuthIP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-ike-functions)
- [WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)
- [Windows Filtering Platform API Reference](https://learn.microsoft.com/windows/desktop/FWP/fwp-reference)