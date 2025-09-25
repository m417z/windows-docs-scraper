# IMFMediaEngineClassFactoryEx::IsTypeSupported

## Description

Gets a value that indicates if the specified key system supports the specified media type.

## Parameters

### `type`

The MIME type to check support for.

### `keySystem`

The key system to check support for.

### `isSupported`

**true** if type is supported by *keySystem*; otherwise, **false.**

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineClassFactoryEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineclassfactoryex)