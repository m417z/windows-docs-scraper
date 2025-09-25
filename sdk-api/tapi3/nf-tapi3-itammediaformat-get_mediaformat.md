# ITAMMediaFormat::get_MediaFormat

## Description

The
**get_MediaFormat** method gets the media format.

## Parameters

### `ppmt` [out]

Pointer to an array of
**AM_MEDIA_TYPE** structures. For more information on **AM_MEDIA_TYPE**, see the DirectX documentation.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITAMMediaFormat](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itammediaformat)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[put_MediaFormat](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itammediaformat-put_mediaformat)