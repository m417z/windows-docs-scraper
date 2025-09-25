# IMFMediaEngine::GetPlayed

## Description

Gets the time ranges that have been rendered.

## Parameters

### `ppPlayed` [out]

Receives a pointer to the [IMFMediaTimeRange](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediatimerange) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to the **played** attribute of the **HTMLMediaElement** interface in HTML5.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)