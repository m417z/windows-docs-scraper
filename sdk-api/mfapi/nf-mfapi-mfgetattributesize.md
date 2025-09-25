# MFGetAttributeSize function

## Description

Retrieves an attribute whose value is a size, expressed as a width and height.

## Parameters

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `guidKey` [in]

**GUID** that identifies which value to retrieve. The attribute type must be MF_ATTRIBUTE_UINT64.

### `punWidth` [out]

Receives the width.

### `punHeight` [out]

Receives the height.

## Return value

This function can return one of these values.

## Remarks

Some attributes specify a size as a packed **UINT64** value. Use this function to get the numerator and denominator as separate 32-bit values.

## See also

[MFSetAttributeSize](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfsetattributesize)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)