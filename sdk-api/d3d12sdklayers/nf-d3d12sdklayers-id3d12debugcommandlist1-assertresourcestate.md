# ID3D12DebugCommandList1::AssertResourceState

## Description

Validates that the given state matches the state of the subresource, assuming the state of the given subresource is known during recording of a command list (e.g. the resource was transitioned earlier in the same command list recording). If the state is not yet known this method sets the known state for further validation later in the same command list recording.

## Parameters

### `pResource` [in]

Type: **ID3D12Resource***

Specifies the [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) to check.

### `Subresource`

Type: **UINT**

The index of the subresource to check. This can be set to an index, or D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES.

### `State`

Type: **UINT**

Specifies the state to check for. This can be one or more [D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states) flags Or'ed together.

## Return value

Type: **BOOL**

This method returns **true** if the tracked state of the resource or subresource matches the specified state, **false** otherwise.

## Remarks

Since execution of command lists occurs sometime after recording, the state of a resource often cannot be known during command list recording. **AssertResourceState** gives an application developer the ability to impose an assumed state on a resource or subresource at a fixed recording point in a command list.

Often the state of a resource or subresource can either be known due to a previous barrier or inferred-by-use (for example, was used in an earlier call to [CopyBufferRegion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copybufferregion)) during command list recording. In such cases **AssertResourceState** can produce a debug message if the given state does not match the known or assumed state.

This API is for debug validation only and does not affect the actual runtime or GPU state of the resource.

## See also

[ID3D12DebugCommandList1](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debugcommandlist1)