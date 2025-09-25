## Description

The **GetParameterRange** method gets the range of values for a codec property.

This method applies only to properties whose values form a linear range.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the property to query. For a list of standard codec properties, see [Codec API Properties](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-properties).

### `ValueMin` [out]

Pointer to a **VARIANT** that receives the minimum value of the property. The caller must free the **VARIANT** by calling **VariantClear**.

### `ValueMax[out]`

Pointer to a **VARIANT** that receives the maximum value of the property. The caller must free the **VARIANT** by calling **VariantClear**.

### `SteppingDelta` [out]

Pointer to a **VARIANT** that receives the stepping delta, which defines the valid increments from *ValueMin* to *ValueMax*. The caller must free the **VARIANT** by calling **VariantClear**.

If the **VARIANT** type is VT_EMPTY, any increment is valid.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | The method succeeded. |
| **VFW_E_CODECAPI_ENUMERATED** | The property supports a list of possible values, not a linear range. |

## Remarks

The valid range for the property is [*ValueMin*... *ValueMax*], with increments of *SteppingDelta*. If a property supports a linear range of values, the property must use one of the following variant types:

* Unsigned types: **VT_UI8**, **VT_UI4**, **VT_UI2**, **VT_UI1**
* Signed types: **VT_I8**, **VT_I4**, **VT_I2**
* Floating-point types: **VT_R8**, **VT_R4**

If the property supports a list of values, instead of a range, the method returns **VFW_E_CODECAPI_ENUMERATED**. In that case, call [ICodecAPI::GetParameterValues](https://learn.microsoft.com/windows/desktop/api/icodecapi/nf-icodecapi-icodecapi-getparametervalues) to get the list of values.

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/icodecapi/nn-icodecapi-icodecapi)