## Description

The **IsModifiable** method queries whether a codec property can be changed, given the codec's current configuration.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the property. For a list of standard codec properties, see [Codec API Properties](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-properties).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The value of this property cannot be changed. |
| **S_OK** | The value of this property can be changed. |

## Remarks

Any errors besides those in the previous table indicate an inability to process the call.

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/icodecapi/nn-icodecapi-icodecapi)