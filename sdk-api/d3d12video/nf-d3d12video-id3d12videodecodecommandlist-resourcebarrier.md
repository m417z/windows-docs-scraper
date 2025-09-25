# ID3D12VideoDecodeCommandList::ResourceBarrier

## Description

Notifies the driver that it needs to synchronize multiple accesses to resources.

## Parameters

### `NumBarriers`

Type: **UINT**

The number of submitted barrier descriptions.

### `pBarriers`

Type: **const [D3D12_RESOURCE_BARRIER](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_barrier)***

Pointer to an array of barrier descriptions.

## Remarks

## See also