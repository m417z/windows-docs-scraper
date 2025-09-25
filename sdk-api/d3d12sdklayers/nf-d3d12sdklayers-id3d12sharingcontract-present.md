# ID3D12SharingContract::Present

## Description

Notifies diagnostic tools about an end-of-frame operation without the use of a swap chain. Calling this API enables usage of tools like PIX with applications that either don't render to a window, or that do so in non-traditional ways.

## Parameters

### `pResource` [in]

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)***

A pointer to the resource that contains the final frame contents. This resource is treated as the *back buffer* of the **Present**.

### `Subresource`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An unsigned 32bit subresource id.

### `window`

If provided, indicates which window the tools should use for displaying additional diagnostic information.

## See also

[ID3D12SharingContract](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12sharingcontract)