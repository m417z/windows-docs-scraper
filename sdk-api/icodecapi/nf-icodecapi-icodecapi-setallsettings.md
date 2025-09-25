## Description

The **SetAllSettings** method reads codec properties from a stream and sets them on the codec.

## Parameters

### `__MIDL__ICodecAPI0001`

Pointer to the **IStream** interface of the stream.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

Codecs that implement [ICodecAPI](https://learn.microsoft.com/windows/desktop/api/icodecapi/nn-icodecapi-icodecapi) are not required to support this method.

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/icodecapi/nn-icodecapi-icodecapi)

[ICodecAPI::GetValue](https://learn.microsoft.com/windows/desktop/api/icodecapi/nf-icodecapi-icodecapi-getvalue)