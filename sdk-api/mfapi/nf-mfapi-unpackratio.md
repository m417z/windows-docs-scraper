# UnpackRatio function

## Description

Gets the low-order and high-order **UINT32** values from a **UINT64** value that represents a ratio.

## Parameters

### `unPacked` [in]

The value to convert.

### `pnNumerator` [out]

Receives the high-order 32 bits.

### `punDenominator` [out]

Receives the low-order 32 bits.

## Remarks

You can use this function to unpack a **UINT64** value that you receive from the [IMFAttributes::GetUINT64](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getuint64) method.

## See also

[MFGetAttributeRatio](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgetattributeratio)

[MFGetAttributeSize](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgetattributesize)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)