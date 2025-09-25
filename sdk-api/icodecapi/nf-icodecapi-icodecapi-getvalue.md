## Description

The **GetValue** method gets the current value of a codec property.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the property. For a list of standard codec properties, see [Codec API Properties](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-properties).

### `Value` [out]

Pointer to a **VARIANT** that receives the value of the property. The caller must free the **VARIANT** by calling **VariantClear**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **VFW_E_CODECAPI_NO_CURRENT_VALUE** | The property does not currently have a value. |

## Remarks

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/icodecapi/nn-icodecapi-icodecapi)

[ICodecAPI::SetValue](https://learn.microsoft.com/windows/desktop/api/icodecapi/nf-icodecapi-icodecapi-setvalue)