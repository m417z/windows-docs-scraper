# D3D11DDIARG_BUFFER_UNORDEREDACCESSVIEW structure

## Description

The D3D11DDIARG_BUFFER_UNORDEREDACCESSVIEW structure describes a buffer that is used to create an unordered access view (UAV) in a call to the [CreateUnorderedAccessView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createunorderedaccessview) function.

## Members

### `FirstElement` [in]

The offset, in bytes, to the first element in the buffer.

### `NumElements` [in]

The number of elements in the buffer.

### `Flags` [in]

A valid bitwise OR of flag values that describe the buffer. The Direct3D runtime supports the following values.

|Value|Meaning|
|--- |--- |
|D3D11_DDI_BUFFER_UAV_FLAG_RAW (0x00000001)|The buffer is in raw format.|
|D3D11_DDI_BUFFER_UAV_FLAG_APPEND (0x00000002)|Associate a counter with the UAV that has append semantics. The count reflects how many items are stored. However, the order in which the items are stored can change.|
|D3D11_DDI_BUFFER_UAV_FLAG_COUNTER (0x00000004)|Associate a counter with the UAV whose semantics prevent the reordering of the contents of the UAV. Therefore, applications can depend on the storage order. For example, applications can create linked lists by using count values to reference stored items.|

## See also

[CalcPrivateUnorderedAccessViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivateunorderedaccessviewsize)

[CreateUnorderedAccessView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createunorderedaccessview)

[D3D11DDIARG_CREATEUNORDEREDACCESSVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createunorderedaccessview)