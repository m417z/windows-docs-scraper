# IMFSharingEngineClassFactory::CreateInstance

## Description

Creates an instance of the media sharing engine.

## Parameters

### `dwFlags` [in]

A bitwise **OR** of zero or more flags from the [MF_MEDIA_ENGINE_CREATEFLAGS](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_createflags) enumeration.

### `pAttr` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. This parameter specifies configuration attributes; see [Media Engine Attributes](https://learn.microsoft.com/windows/desktop/medfound/media-engine-attributes).

### `ppEngine` [out]

Receives a pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the media sharing engine. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSharingEngineClassFactory](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/nn-mfsharingengine-imfsharingengineclassfactory)