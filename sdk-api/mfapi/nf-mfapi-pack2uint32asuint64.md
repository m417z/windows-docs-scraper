# Pack2UINT32AsUINT64 function

## Description

Packs two **UINT32** values into a **UINT64** value.

## Parameters

### `unHigh` [in]

Value to store in the high-order 32 bits of the **UINT64** value.

### `unLow` [in]

Value to store in the low-order 32 bits of the **UINT64** value.

## Return value

Returns the packed **UINT64** value.

## Remarks

This function stores two 32-bit values in a 64-bit value that is suitable for the [IMFAttributes::SetUINT64](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-setuint64) method.

## See also

[MFSetAttributeRatio](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfsetattributeratio)

[MFSetAttributeSize](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfsetattributesize)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)