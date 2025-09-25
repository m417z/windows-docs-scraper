## Description

The **SetValue** method sets the value of a codec property.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the property to set.
For a list of standard codec properties, see [Codec API Properties](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-properties).

### `Value` [in]

Pointer to a **VARIANT** that contains the new value for the property.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The property is read-only. |
| **E_INVALIDARG** | Invalid property GUID or value. |

## Remarks

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/icodecapi/nn-icodecapi-icodecapi)

[ICodecAPI::GetValue](https://learn.microsoft.com/windows/desktop/api/icodecapi/nf-icodecapi-icodecapi-getvalue)