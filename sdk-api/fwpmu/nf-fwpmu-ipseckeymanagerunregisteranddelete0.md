# IPsecKeyManagerUnregisterAndDelete0 function

## Description

The **IPsecKeyManagerUnregisterAndDelete0** function unregisters a Trusted Intermediary Agent (TIA) which had previously been registered with IPsec.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

A handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `keyMgmtHandle` [in]

Type: **HANDLE**

Address of the previously created registration.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The TIA was successfully unregistered. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## See also

[WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)