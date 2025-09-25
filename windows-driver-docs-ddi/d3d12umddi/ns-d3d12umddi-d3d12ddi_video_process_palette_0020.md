# D3D12DDI_VIDEO_PROCESS_PALETTE_0020 structure

## Description

Specifies whether the palette is enabled and an array of palette entries.

## Members

### `Enable`

Whether palette is enabled.

### `NumEntries`

The number of elements in the **pEntries** array.

### `pEntries`

A pointer to an array of palette entries. For RGB streams, the palette entries use the **DXGI_FORMAT_B8G8R8A8** representation. For YCbCr streams, the palette entries use the **DXGI_FORMAT_AYUV** representation. For more information, see the [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration. The caller allocates the array.

## See also

[**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)