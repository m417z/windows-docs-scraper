## Description

The **D3DDDI_BATCHEDMARKERDATA** structure provides high-performance marker data from D3D12 drivers.

## Members

### `hRTCommandListHandle`

D3D12DDI_HRTCOMMANDLIST::handle value for the command list that this marker data corresponds to. This handle was provided during command list creation.

### `FirstAPISequenceNumberHigh`

The high bits of the API sequence numbers represented by this batch of marker data.

### `CompletedAPISequenceNumberLowSize`

The number of API sequence numbers present in this batch of marker data (the number of elements in **pCompletedAPISequenceNumberLow**).

### `pCompletedAPISequenceNumberLow`

Array of the low bits of API sequence numbers represented by this batch of marker data.

## Remarks

The driver is responsible for filling out this structure when submitting rendering work or history buffers to the runtime, and when the driver uses the D3DDDIMLT_BATCHED value for the **MarkerLogType** field in the structure that contains this structure. The containing structure could be one of [**D3DDDICB_RENDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render), [**D3DDDICB_SUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_submitcommand), or [**D3DDDICB_SUBMITHISTORYSEQUENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_submithistorysequence). See [**D3DDDI_MARKERLOGTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_markerlogtype) for details on when a driver should set D3DDDIMLT_BATCHED.

## See also

[**D3DDDI_MARKERLOGTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_markerlogtype)

[**D3DDDICB_RENDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render)

[**D3DDDICB_SUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_submitcommand)

[**D3DDDICB_SUBMITHISTORYSEQUENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_submithistorysequence)