# MFSetAttributeRatio function

## Description

Sets a ratio as a 64-bit attribute value.

## Parameters

### `pAttributes` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `guidKey` [in]

A **GUID** that identifies the value to set. If this key already exists, the function overwrites the old value.

### `unNumerator` [in]

The numerator of the ratio.

### `unDenominator` [in]

The denominator of the ratio.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Some attributes specify a ratio as a packed **UINT64** value. This function packs the numerator and denominator into a single **UINT64** value.

## See also

[Attributes in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[MFGetAttributeRatio](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgetattributeratio)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)