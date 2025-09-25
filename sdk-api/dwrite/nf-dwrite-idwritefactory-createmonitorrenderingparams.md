# IDWriteFactory::CreateMonitorRenderingParams

## Description

 Creates a rendering parameters object with default settings for the specified monitor.
In most cases, this is the preferred way to create a rendering parameters object.

## Parameters

### `monitor`

Type: **HMONITOR**

A handle for the specified monitor.

### `renderingParams` [out]

Type: **[IDWriteRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriterenderingparams)****

When this method returns, contains an address of a pointer to the rendering parameters object created by this method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)