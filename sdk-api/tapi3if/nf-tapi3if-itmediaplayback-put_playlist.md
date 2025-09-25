# ITMediaPlayback::put_PlayList

## Description

The
**put_PlayList** method provides the file playback terminal with the list of files to play.

## Parameters

### `PlayListVariant` [in]

Variant of type VT_ARRAY, which contains variants of type VT_BSTR and VT_STORAGE.

The VT_BSTR elements of the array contain the names of the files to play. The file name extension is used to determine the type of file. Currently, the supported file name extensions are .avi and .wav.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITMediaPlayback](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itmediaplayback)

[get_PlayList](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itmediaplayback-get_playlist)