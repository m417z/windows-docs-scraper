# IPsecGetStatistics0 function

## Description

The **IPsecGetStatistics0** function retrieves Internet Protocol Security (IPsec) statistics.

**Note** **IPsecGetStatistics0** is the specific implementation of IPsecGetStatistics used in Windows Vista. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7 and later, [IPsecGetStatistics1](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecgetstatistics1) is available.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `ipsecStatistics` [out]

Type: [IPSEC_STATISTICS0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_statistics0)*

Top-level object of IPsec statistics organization.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The IPsec statistics were successfully retrieved. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

This function cannot be called from within a transaction. It will fail with
**FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

The caller needs [FWPM_ACTRL_READ_STATS](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the IPsec security associations database. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

## See also

[IPSEC_STATISTICS0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_statistics0)