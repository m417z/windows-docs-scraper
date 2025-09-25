## Description

Specifies an event that should be fired when one or more of a collection of fences reach specific values.

## Parameters

### `ppFences` [in]

Type: **ID3D12Fence***

An array of length *NumFences* that specifies the [ID3D12Fence](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12fence) objects.

### `pFenceValues` [in]

Type: **const UINT64***

An array of length *NumFences* that specifies the fence values required for the event is to be signaled.

### `NumFences`

Type: **UINT**

Specifies the number of fences to be included.

### `Flags`

Type: **[D3D12_MULTIPLE_FENCE_WAIT_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_multiple_fence_wait_flags)**

Specifies one of the [D3D12_MULTIPLE_FENCE_WAIT_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_multiple_fence_wait_flags) that determines how to proceed.

### `hEvent`

Type: **HANDLE**

A handle to the event object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## Remarks

To specify a single fence refer to the [SetEventOnCompletion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12fence-seteventoncompletion) method.

If *hEvent* is a null handle, then this API will not return until the specified fence value(s) have been reached.

## See also

[ID3D12Device1](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device1)