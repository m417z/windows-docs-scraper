# PackSize function

## Description

Packs a UINT32 width value and a UINT32 height value into a UINT64 value that represents a size.

## Parameters

### `unWidth` [in]

Value to store the **UINT32** width value.

### `unHeight` [in]

Value to store the **UINT32** height value.

## Return value

Returns the packed **UINT64** value.

## Remarks

This function stores two 32-bit values in a 64-bit value that is suitable for the [IMFAttributes::SetUINT64](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-setuint64) method.

## See also

[MFGetAttributeRatio](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgetattributeratio)

[MFGetAttributeSize](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgetattributesize)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)