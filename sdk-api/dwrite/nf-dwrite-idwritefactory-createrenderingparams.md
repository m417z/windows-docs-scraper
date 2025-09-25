# IDWriteFactory::CreateRenderingParams

## Description

 Creates a rendering parameters object with default settings for the primary monitor.
Different monitors may have different rendering parameters, for more information see the [How to Add Support for Multiple Monitors](https://learn.microsoft.com/windows/win32/DirectWrite/how-to-add-support-for-multiple-monitors) topic.

## Parameters

### `renderingParams` [out]

Type: **[IDWriteRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriterenderingparams)****

When this method returns, contains an address of a pointer to the newly created rendering parameters object.

## Return value

Type: **HRESULT**

Standard HRESULT error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)

[IDWriteFactory::CreateMonitorRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-createmonitorrenderingparams)