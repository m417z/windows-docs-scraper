## Description

For a given input type, returns the "natural output type" of the video.

## Parameters

### `ppType` [out]

A pointer to an [IMFMediaType](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfmediatype) object specifying the natural output type of the video.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The natural type is defined as:

* No scaling is applied
* No color conversions are applied

This accounts for any rotation, cropping, or pixel aspect applied to the video.

## See also