# PFND3D12DDI_QUERY_VIDEO_MEMORY_INFO_0054 callback function

## Description

Queries for video memory info.

## Parameters

### `unnamedParam1` [in]

Handle to the device to query.

### `NodeIndex` [in]

The index of the GPU node.

### `MemorySegmentGroup` [in]

The memory segment group to query.

### `pVideoMemoryInfo` [out]

Pointer to a D3D12DDI_QUERY_VIDEO_MEMORY_INFO_0054 structure that contains the video memory info.

## Prototype

```
//Declaration

PFND3D12DDI_QUERY_VIDEO_MEMORY_INFO_0054 Pfnd3d12ddiQueryVideoMemoryInfo0054;

// Definition

void Pfnd3d12ddiQueryVideoMemoryInfo0054
(
	D3D12DDI_HDEVICE Arg1
	UINT NodeIndex
	D3D12DDI_MEMORY_SEGMENT_GROUP_0054 MemorySegmentGroup
	D3D12DDI_QUERY_VIDEO_MEMORY_INFO_0054 *pVideoMemoryInfo
)
{...}

```

## Remarks

## See also