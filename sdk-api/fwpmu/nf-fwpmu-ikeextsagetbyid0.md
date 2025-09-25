# IkeextSaGetById0 function

## Description

The **IkeextSaGetById0** function retrieves an IKE/AuthIP security association (SA) from the database.

**Note** **IkeextSaGetById0** is the specific implementation of IkeextSaGetById used in Windows Vista. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7, [IkeextSaGetById1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ikeextsagetbyid1) is available. For Windows 8, [IkeextSaGetById2](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ikeextsagetbyid2) is available.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `id` [in]

Type: **UINT64**

The SA identifier.

### `sa` [out]

Type: [IKEEXT_SA_DETAILS0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_sa_details0)**

Address of the SA details.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The SA was retrieved successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

The caller must free *sa* by a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

The caller needs [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the IKE/AuthIP security associations database. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

## See also

[IKE/AuthIP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-ike-functions)

[IKEEXT_SA_DETAILS0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_sa_details0)

[WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)