## Description

The **SetAllSettingsWithNotify** method reads codec properties from a stream, sets them on the codec, and returns a list of the properties that changed.

## Parameters

### `__MIDL__ICodecAPI0002` [in]

Pointer to the **IStream** interface of the stream.

### `ChangedParam` [out]

Receives a pointer to an array of GUIDs. The array contains the GUIDs of any properties that changed as a result of this method call. The caller must free the array by calling **CoTaskMemFree**.

### `ChangedParamCount` [in]

Receives the number of elements in the *ChangedParam* array.

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