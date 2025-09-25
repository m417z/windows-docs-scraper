## Description

The **FwpmSubLayerCreateEnumHandle0** function creates a handle used to enumerate a set of sublayers.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `enumTemplate` [in, optional]

Template to selectively restrict the enumeration.

### `enumHandle` [out]

Handle for sublayer enumeration.

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The enumerator was created successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

If *enumTemplate* is **NULL**, all sublayers are returned.

The enumerator is not live, meaning it does not reflect changes made to the system after the call to **FwpmSubLayerCreateEnumHandle0** returns. If you need to ensure that the results are current, you must call **FwpmSubLayerCreateEnumHandle0** and **[FwpmSubLayerEnum0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmsublayerenum0)** from within the same explicit transaction.

The caller must free the returned handle by a call to **[FwpmSubLayerDestroyEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmsublayerdestroyenumhandle0)**.

The caller needs [FWPM_ACTRL_ENUM](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the sublayers' containers and **FWPM_ACTRL_READ** access to the sub-layers. Only sublayers to which the caller has **FWPM_ACTRL_READ** access will be returned. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmSubLayerCreateEnumHandle0** is a specific implementation of **FwpmSubLayerCreateEnumHandle**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[FwpmSubLayerEnum0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmsublayerenum0)**
- **[FwpmSubLayerDestroyEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmsublayerdestroyenumhandle0)**
- [FWPM_ACTRL_ENUM](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers)
- [FWPM_SUBLAYER_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_sublayer_enum_template0)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)