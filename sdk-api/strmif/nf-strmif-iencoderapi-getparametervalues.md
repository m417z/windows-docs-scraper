# IEncoderAPI::GetParameterValues

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

[[IEncoderAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi) is no longer available for use. Instead, use [ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi).]

The **GetParameterValues** method retrieves the list of values supported by the given parameter.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the parameter.

### `Values` [out]

Address of a pointer to an array that receives the values.

### `ValuesCount` [out]

Indicates the number of entries placed into the array.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns an array of **VARIANT** types representing the individual values supported by the parameter. This array is allocated by the callee through **CoTaskMemAlloc** and placed into the *Values* parameter. On exit, *ValuesCount* contains the number of elements in the array. The caller must free the array by calling **CoTaskMemFree**.

## See also

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[IEncoderAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi)