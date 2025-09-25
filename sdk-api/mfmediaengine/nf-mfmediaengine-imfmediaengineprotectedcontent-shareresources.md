# IMFMediaEngineProtectedContent::ShareResources

## Description

Enables the Media Engine to access protected content while in frame-server mode.

## Parameters

### `pUnkDeviceContext` [in]

A pointer to the Direct3D 11 device content. The Media Engine queries this pointer for the [ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In frame-server mode, this method enables the Media Engine to share protected content with the Direct3D 11 device.

## See also

[IMFMediaEngineProtectedContent](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineprotectedcontent)