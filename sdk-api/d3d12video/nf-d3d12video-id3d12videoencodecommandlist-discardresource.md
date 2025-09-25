## Description

Indicate that the current contents of a resource can be discarded. The current contents of the resource are no longer valid allowing optimizations for subsequent operations such as [ResourceBarrier](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodecodecommandlist-discardresource).

## Parameters

### `pResource`

A pointer to the [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) interface for the resource to discard.

### `pRegion`

A pointer to a [D3D12_DISCARD_REGION](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_discard_region) structure that describes details for the discard-resource operation.

## Remarks

## See also