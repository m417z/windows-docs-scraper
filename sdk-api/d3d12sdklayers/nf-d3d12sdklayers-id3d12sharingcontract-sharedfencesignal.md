# ID3D12SharingContract::SharedFenceSignal

## Description

Signals a shared fence between the D3D layers and diagnostics tools.

## Parameters

### `pFence` [in]

Type: **[ID3D12Fence](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12fence)***

A pointer to the shared fence to signal.

### `FenceValue`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An unsigned 64bit value to signal the shared fence with.

## See also

[ID3D12SharingContract](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12sharingcontract)