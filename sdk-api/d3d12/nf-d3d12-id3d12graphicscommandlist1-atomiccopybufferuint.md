# ID3D12GraphicsCommandList1::AtomicCopyBufferUINT

## Description

Atomically copies a primary data element of type UINT from one resource to another, along with optional dependent resources.

These 'dependent resources' are so-named because they depend upon the primary data element to locate them, typically the key element is an address, index, or other handle that refers to one or more the dependent resources indirectly.

This function supports a primary data element of type UINT (32bit). A different version of this function, [AtomicCopyBufferUINT64](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist1-atomiccopybufferuint64), supports a primary data element of type UINT64 (64bit).

## Parameters

### `pDstBuffer` [in]

Type: **ID3D12Resource***

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values?view=vs-2015&preserve-view=true): `_In_`

The resource that the UINT primary data element is copied into.

### `DstOffset`

Type: **UINT64**

An offset into the destination resource buffer that specifies where the primary data element is copied into, in bytes. This offset combined with the base address of the resource buffer must result in a memory address that's naturally aligned for UINT values.

### `pSrcBuffer` [in]

Type: **ID3D12Resource***

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values?view=vs-2015&preserve-view=true): `_In_`

The resource that the UINT primary data element is copied from. This data is typically an address, index, or other handle that shader code can use to locate the most-recent version of latency-sensitive information.

### `SrcOffset`

Type: **UINT64**

An offset into the source resource buffer that specifies where the primary data element is copied from, in bytes. This offset combined with the base address of the resource buffer must result in a memory address that's naturally aligned for UINT values.

### `Dependencies`

Type: **UINT**

The number of dependent resources.

### `ppDependentResources` [in]

Type: **ID3D12Resource***

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values?view=vs-2015&preserve-view=true): `_In_reads_(Dependencies)`

An array of resources that contain the dependent elements of the data payload.

### `pDependentSubresourceRanges` [in]

Type: **const [D3D12_SUBRESOURCE_RANGE_UINT64](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_range_uint64)***

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-parameters-and-return-values?view=vs-2015&preserve-view=true): `_In_reads_(Dependencies)`

An array of subresource ranges that specify the dependent elements of the data payload. These elements are completely updated before the primary data element is itself atomically copied. This ensures that the entire operation is logically atomic; that is, the primary data element never refers to an incomplete data payload.

## Remarks

This method is typically used to update resources for which normal rendering pipeline latency can be detrimental to user experience. For example, an application can compute a view matrix from the latest user input (such as from the sensors of a head-mounted display), and use this function to update and activate this matrix in command lists already dispatched to the GPU to reduce perceived latency between input and rendering.

## See also

[ID3D12GraphicsCommandList1](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist1)