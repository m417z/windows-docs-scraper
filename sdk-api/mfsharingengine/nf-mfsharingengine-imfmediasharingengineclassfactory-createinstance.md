# IMFMediaSharingEngineClassFactory::CreateInstance

## Description

Creates an instance of the [IMFMediaSharingEngine](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/nn-mfsharingengine-imfmediasharingengine).

## Parameters

### `dwFlags` [in]

A bitwise **OR** of zero or more flags from the [MF_MEDIA_ENGINE_CREATEFLAGS](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_createflags) enumeration.

### `pAttr` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of an attribute store.

### `ppEngine` [out]

Receives a pointer to the [IMFMediaSharingEngine](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/nn-mfsharingengine-imfmediasharingengine) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaSharingEngineClassFactory](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/nn-mfsharingengine-imfmediasharingengineclassfactory)