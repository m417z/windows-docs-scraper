# MFGetAttributeString function

## Description

Gets a string value from an attribute store.

## Parameters

### `pAttributes` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface.

### `guidKey` [in]

A GUID that identifies which value to retrieve. The attribute type must be **MF_ATTRIBUTE_STRING**.

### `ppsz` [out]

If the key is found and the value is a string type, this parameter receives a copy of the string. The caller must free the memory for the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is a wrapper for the [IMFAttributes::GetAllocatedString](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getallocatedstring) method.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)