## Description

The **IkeextSaGetById1** function retrieves an IKE/AuthIP security association (SA) from the database.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `id` [in]

The SA identifier.

### `saLookupContext` [in., optional]

Optional pointer to the SA lookup context propagated from the SA to data connections flowing over that SA. It is made available to any application that queries socket security properties using the Winsock API **[WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity)** function, allowing the application to obtain detailed IPsec authentication information for its connection.

### `sa` [out]

Address of the SA details.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The SA was retrieved successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

The caller must free sa by a call to **[FwpmFreeMemory0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfreememory0)**.

The caller needs [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the IKE/AuthIP security associations database. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

 **IkeextSaGetById1** is a specific implementation of **IkeextSaGetById**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[FwpmFreeMemory0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmfreememory0)**
- **[WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity)**
- [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers)
- [IKEEXT_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_sa_details1)
- [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)
- [IKE/AuthIP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-ike-functions)
- [WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)