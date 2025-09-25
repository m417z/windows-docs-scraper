# ITAMMediaFormat::put_MediaFormat

## Description

The
**put_MediaFormat** method sets the media format.

## Parameters

### `pmt` [in]

Pointer to
**AM_MEDIA_TYPE** structure. For more information on **AM_MEDIA_TYPE**, see the DirectX documentation.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

On addresses where a variety of formats are supported (such as Wave MSP addresses, which are used on most modems and voice boards), this call is mandatory or the terminal will not be able to connect.

For other addresses, such as those implemented over IP, the format may be fixed/predetermined. In that case, this call will fail if the format is not the same as the predetermined format. To retrieve such a predetermined format, an application can use
[get_MediaFormat](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itammediaformat-get_mediaformat).

## See also

[ITAMMediaFormat](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itammediaformat)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[get_MediaFormat](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itammediaformat-get_mediaformat)