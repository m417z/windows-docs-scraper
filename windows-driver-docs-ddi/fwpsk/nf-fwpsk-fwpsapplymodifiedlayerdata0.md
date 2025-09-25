# FwpsApplyModifiedLayerData0 function

## Description

The **FwpsApplyModifiedLayerData0** function applies changes to layer-specific data made after a call to [FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0).

> [!Note]
> **FwpsApplyModifiedLayerData0** is a specific version of **FwpsApplyModifiedLayerData**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `classifyHandle` [in]

The classification handle that identifies the callout driver's processing at the current layer.
This handle is obtained by calling [FwpsAcquireClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquireclassifyhandle0).

### `modifiedLayerData` [in]

The data buffer obtained by calling [FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0) with members modified by the callout driver. Supported data types are defined as structures.

### `flags` [in]

The options to use with this function call. This flag can have the following value.

|Value|Meaning|
|--- |--- |
|**FWPS_CLASSIFY_FLAG_REAUTHORIZE_IF_MODIFIED_BY_OTHERS**|When set, this flag specifies that data at the layer of the pended classify action should be reauthorized if another callout driver modifies the data before the classification is completed. Use this flag only with pended classify and not inline classify, as its use with inline classify can lead to indeterminate results. If you do call this API for inline classify, set flags to zero.|

## Remarks

**FwpsApplyModifiedLayerData0** should be called once for every call made to[FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0), even if the callout driver didn't modify any data.

## See also

[FWPS_BIND_REQUEST0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-_fwps_bind_request0)

[FWPS_CONNECT_REQUEST0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-_fwps_connect_request0)

[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1)

[FwpsAcquireClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquireclassifyhandle0)

[FwpsAcquireWritableLayerDataPointer0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquirewritablelayerdatapointer0)

[FwpsReleaseClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreleaseclassifyhandle0)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)