## Description

The **FwpmConnectionPolicyDeleteByKey0** function removes the connection policy that was created with the GUID specified in the **[FWPM_PROVIDER_CONTEXT::providerContextKey](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context3)** when you called **[FwpmConnectionPolicyAdd0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmconnectionpolicyadd0)**.

## Parameters

### `engineHandle` [in]

A handle to an open session with the filter engine. To open a session with the filter engine, call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**.

### `key` [in]

The GUID of the connection policy that was created when you called **[FwpmConnectionPolicyAdd0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmconnectionpolicyadd0)**.

## Return value
| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The connection policy was successfully removed. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

## See also

- **[FWPM_PROVIDER_CONTEXT::providerContextKey](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context3)**
- **[FwpmConnectionPolicyAdd0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmconnectionpolicyadd0)**
- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)