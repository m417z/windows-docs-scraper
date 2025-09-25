# IMFMediaEngine::GetSeekable

## Description

Gets the time ranges to which the Media Engine can currently seek.

## Parameters

### `ppSeekable` [out]

Receives a pointer to the [IMFMediaTimeRange](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediatimerange) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to the **seekable** attribute of the **HTMLMediaElement** interface in HTML5.

To find out whether the media source supports seeking, call [IMFMediaEngineEx::GetResourceCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-getresourcecharacteristics).

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)