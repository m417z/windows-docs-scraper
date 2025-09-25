# IMFMediaSourceEx::SetD3DManager

## Description

Sets a pointer to the Microsoft DirectX Graphics Infrastructure (DXGI) Device Manager on the media source.

## Parameters

### `pManager` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the DXGI Manager. The media source should query this pointer for the [IMFDXGIDeviceManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgidevicemanager) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | The media source does not support source-level attributes. |

## See also

[IMFMediaSourceEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasourceex)