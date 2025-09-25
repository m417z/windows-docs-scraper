## Description

The **SetValueWithNotify** method sets a property on a codec and returns a list of other properties that changed as a result.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the property to set.
For a list of standard codec properties, see [Codec API Properties](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-properties).

### `Value` [in]

Pointer to a **VARIANT** that contains the new value for the property.

### `ChangedParam` [out]

Receives a pointer to an array of GUIDs. The array contains the GUIDs of any properties that changed as a result of this method call. The caller must free the array by calling **CoTaskMemFree**.

### `ChangedParamCount` [out]

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