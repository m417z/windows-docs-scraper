# MFCompareFullToPartialMediaType function

## Description

Compares a full media type to a partial media type.

## Parameters

### `pMFTypeFull`

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the full media type.

### `pMFTypePartial`

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the partial media type.

## Return value

If the full media type is compatible with the partial media type, the function returns **TRUE**. Otherwise, the function returns **FALSE**.

## Remarks

A pipeline component can return a partial media type to describe a range of possible formats the component might accept. A partial media type has at least a major type GUID, but might be missing some of the other attributes that are needed to fully describe the type. The missing attributes represent "don't care" values for the partial type. For example, a partial video type might be missing the attributes for the width and height of the video.

This function returns **TRUE** if the following conditions are both true:

* The partial media type contains a major type GUID.
* All of the attributes in the partial type exist in the full type and are set to the same value.

Otherwise, the function returns **FALSE**.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)