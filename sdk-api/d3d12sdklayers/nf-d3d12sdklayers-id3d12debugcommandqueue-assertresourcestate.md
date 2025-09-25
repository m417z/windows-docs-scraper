# ID3D12DebugCommandQueue::AssertResourceState

## Description

Checks whether a resource, or subresource, is in a specified state, or not.

## Parameters

### `pResource` [in]

Type: **ID3D12Resource***

Specifies the [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) to check.

### `Subresource`

Type: **UINT**

The index of the subresource to check.
This can be set to an index, or D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES.

### `State`

Type: **UINT**

Specifies the state to check for. This can be one or more D3D12_RESOURCE_STATES flags Or'ed together.

## Return value

Type: **BOOL**

This method returns true if the resource or subresource is in the specified state, false otherwise.

## Remarks

This method is very similar to [ID3D12DebugCommandList::AssertResourceState](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugcommandlist-assertresourcestate), however there are methods on the command queue that work directly with resources that might need to be monitored (for example [ID3D12CommandQueue::CopyTileMappings](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-copytilemappings)).

## See also

[ID3D12DebugCommandQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debugcommandqueue)