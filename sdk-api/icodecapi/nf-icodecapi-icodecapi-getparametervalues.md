## Description

The **GetParameterValues** method gets the list of possible values for a codec property.

This method applies only to properties that support a list of possible values, as opposed to a linear range.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the property to query. For a list of standard codec properties, see [Codec API Properties](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-properties).

### `Values` [out]

Receives a pointer to an array of **VARIANT** types. The array contains the list of values that the encoder supports for this property. The caller must free each **VARIANT** by calling **VariantClear**. The caller must also free the array by calling **CoTaskMemFree**.

### `ValuesCount` [out]

Receives the number of elements in the *Values* array.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **VFW_E_CODECAPI_LINEAR_RANGE** | The property supports a range of values, not a list. |

## Remarks

If the property supports a range of values, instead of a list, the method returns **VFW_E_CODECAPI_LINEAR_RANGE**. In that case, call [ICodecAPI::GetParameterRange](https://learn.microsoft.com/windows/desktop/api/icodecapi/nf-icodecapi-icodecapi-getparameterrange) to get the range of values.

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/icodecapi/nn-icodecapi-icodecapi)