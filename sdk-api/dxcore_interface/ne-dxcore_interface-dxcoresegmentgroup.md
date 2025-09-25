## Description

Defines constants that specify an adapter's memory segment grouping.

## Constants

### `Local:0`

Specifies a grouping of segments that is considered local to the adapter, and represents the fastest memory available to the GPU. Your application should target the local segment group as the target size for its working set.

### `NonLocal:1`

Specifies a grouping of segments that is considered non-local to the adapter, and may have slower performance than the local segment group.

## See also

[DXCore reference](https://learn.microsoft.com/windows/win32/dxcore/dxcore-reference), [Using DXCore to enumerate adapters](https://learn.microsoft.com/windows/win32/dxcore/dxcore-enum-adapters)