# IDXGIOutputDuplication::GetDesc

## Description

Retrieves a description of a duplicated output. This description specifies the dimensions of the surface that contains the desktop image.

## Parameters

### `pDesc` [out]

A pointer to a [DXGI_OUTDUPL_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_outdupl_desc) structure that describes the duplicated output. This parameter must not be **NULL**.

## Remarks

After an application creates an [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) interface, it calls **GetDesc** to retrieve the dimensions of the surface that contains the desktop image. The format of the desktop image is always [DXGI_FORMAT_B8G8R8A8_UNORM](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format).

## See also

[IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication)