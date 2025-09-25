# FwpmSystemPortsGet0 function

## Description

The **FwpmSystemPortsGet0** function retrieves an array of all of the system port types.

## Parameters

### `engineHandle` [in, optional]

Type: **HANDLE**

Optional handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `sysPorts` [out]

Type: [FWPM_SYSTEM_PORTS0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_system_ports0)**

The array of system port types.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The subscriptions were retrieved successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

The returned array (but not the individual entries in the array) must be freed through a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

**FwpmSystemPortsGet0** is a specific implementation of FwpmSystemPortsGet. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_SYSTEM_PORTS0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_system_ports0)