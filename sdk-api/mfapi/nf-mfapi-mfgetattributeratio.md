# MFGetAttributeRatio function

## Description

Retrieves an attribute whose value is a ratio.

## Parameters

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `guidKey` [in]

**GUID** that identifies which value to retrieve. The attribute type must be MF_ATTRIBUTE_UINT64.

### `punNumerator` [out]

Receives the numerator of the ratio.

### `punDenominator` [out]

Receives the denominator of the ratio.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Some attributes specify a ratio as a packed **UINT64** value. Use this function to get the numerator and denominator as separate 32-bit values.

## See also

[MFSetAttributeRatio](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfsetattributeratio)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)