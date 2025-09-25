# IMFMediaEngine::GetBuffered

## Description

Queries how much resource data the media engine has buffered.

## Parameters

### `ppBuffered` [out]

Receives a pointer to the [IMFMediaTimeRange](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediatimerange) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to the **buffered** attribute of the **HTMLMediaElement** interface in HTML5.

The returned [IMFMediaTimeRange](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediatimerange) interface represents a list of time ranges. The time ranges indicate which portions of the media resource have been downloaded. The time range list can be empty.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)