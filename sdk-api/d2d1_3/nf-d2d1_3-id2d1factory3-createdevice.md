## Description

Creates an [ID2D1Device2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1device2) object.

## Parameters

### `dxgiDevice` [in]

Type: **[IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice)***

The [IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice) object used when creating the [ID2D1Device2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1device2).

### `d2dDevice2` [out]

Type: **[ID2D1Device2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1device2)****

The requested [ID2D1Device2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1device2) object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1Factory3](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1factory3)