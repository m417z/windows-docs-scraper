## Description

Describes a memory segment group for an adapter.

## Members

### `nodeIndex`

Type: **uint32_t**

Specifies the device's physical adapter for which the adapter memory information is queried. For single-adapter operation, set this to zero. If there are multiple adapter nodes, then set this to the index of the node (the device's physical adapter) for which you want to query for adapter memory information (see [Multi-adapter](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine)).

### `segmentGroup`

Type: **[DXCoreSegmentGroup](https://learn.microsoft.com/windows/win32/api/dxcore_interface/ne-dxcore_interface-dxcoresegmentgroup)**

Specifies the adapter memory segment grouping that you want to query about.

## See also

[DXCore reference](https://learn.microsoft.com/windows/win32/dxcore/dxcore-reference), [Using DXCore to enumerate adapters](https://learn.microsoft.com/windows/win32/dxcore/dxcore-enum-adapters), [Multi-adapter](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine)