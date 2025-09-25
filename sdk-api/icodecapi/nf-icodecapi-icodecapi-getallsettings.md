## Description

The **GetAllSettings** method gets the codec's current properties and writes them to a stream.

## Parameters

### `__MIDL__ICodecAPI0000` [in]

Pointer to the *IStream* interface of the stream.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

Codecs that implement [ICodecAPI](https://learn.microsoft.com/windows/desktop/api/icodecapi/nn-icodecapi-icodecapi) are not required to support this method.

To load the properties from the stream back onto the codec, call [ICodecAPI::SetAllSettings](https://learn.microsoft.com/windows/desktop/api/icodecapi/nf-icodecapi-icodecapi-setallsettings) or [ICodecAPI::SetAllSettingsWithNotify](https://learn.microsoft.com/windows/desktop/api/icodecapi/nf-icodecapi-icodecapi-setallsettingswithnotify).

The format of the data that is written to the stream depends on the implementation of the codec. There is no standard serialization format. An application should not attempt to save the properties from one codec and load them on a different codec.

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)