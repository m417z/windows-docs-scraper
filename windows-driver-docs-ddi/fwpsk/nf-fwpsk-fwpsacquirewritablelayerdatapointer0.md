# FwpsAcquireWritableLayerDataPointer0 function

## Description

The
**FwpsAcquireWritableLayerDataPointer0** function returns layer-specific data that can be inspected and
changed.

**Note** **FwpsAcquireWritableLayerDataPointer0** is a specific version of **FwpsAcquireWritableLayerDataPointer**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `classifyHandle` [in]

A handle for the classify request.
This handle is obtained by calling
[FwpsAcquireClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquireclassifyhandle0).

### `filterId` [in]

The value of the
**FilterId** member of the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function's
*filter* parameter. For more information about the
**FilterId** member, see
[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1).

### `flags` [in]

Reserved for future use. Set to zero.

### `writableLayerData` [out]

A data buffer that contains the modifiable data for the layer. The supported data types, which are listed in the following Remarks section, are defined as
structures. On return, the data can be accessed by casting the void pointer to the appropriate structure
type.

### `classifyOut` [in, out]

Set to the
*classifyOut* parameter of the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function. The
*classifyOut* parameter of
classifyFn is listed as an output parameter in the header, but it contains enough information on
input to be useful to the engine when passed to
**FwpsAcquireWritableLayerDataPointer0**.

## Return value

The
**FwpsAcquireWritableLayerDataPointer0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callback function was successfully registered. |
| **Other status codes** | An error occurred. |

## Remarks

**FwpsAcquireWritableLayerDataPointer0** sets the following members of the [FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0) structure:

* *classifyOut*->**actionType** = **FWP_ACTION_BLOCK**
* *classifyOut*->**rights** &= ~**FWPS_RIGHT_ACTION_WRITE**

For every call to this function, you must make a matching call to
[FwpsApplyModifiedLayerData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsapplymodifiedlayerdata0) to
finalize the changes that were made, even if your callout driver didn't modify any data. If you do not make the call to **FwpsApplyModifiedLayerData0**, this could result in the classify not completing correctly.

The following structures are defined to contain modifiable layer data. The pointer set on output as
the
*writableLayerData* parameter can be cast to one of these types:

* [FWPS_BIND_REQUEST0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-_fwps_bind_request0)
* [FWPS_CONNECT_REQUEST0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-_fwps_connect_request0)

## See also

[FWPS_BIND_REQUEST0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-_fwps_bind_request0)

[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0)

[FWPS_CONNECT_REQUEST0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-_fwps_connect_request0)

[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1)

[FwpsAcquireClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsacquireclassifyhandle0)

[FwpsApplyModifiedLayerData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsapplymodifiedlayerdata0)

[FwpsReleaseClassifyHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreleaseclassifyhandle0)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)