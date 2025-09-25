# ITFileTrack::put_Format

## Description

The
**put_Format** method sets the format type of the track.

## Parameters

### `pmt` [in]

 The
**AM_MEDIA_TYPE** descriptor of the file track format. For more information about **AM_MEDIA_TYPE**, see the DirectX documentation. The [ITFileTrack](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itfiletrack) only supports the **FORMAT_WaveFormatEx** format type in the **AM_MEDIA_TYPE** structure.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITFileTrack](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itfiletrack)