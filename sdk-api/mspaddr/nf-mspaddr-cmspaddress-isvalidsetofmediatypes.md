# CMSPAddress::IsValidSetOfMediaTypes

## Description

The
**IsValidSetOfMediaTypes** method checks to see if the specified media type is nonzero and is in the specified mask. Your MSP can override this if it needs to do atypically complex checks on specific combinations of media types (for example, can never have more than one media type on a call, can have video with audio but not video alone, and so on). The default implementation accepts any nonempty set of media types that is a subset of the set of types in the mask.

## Parameters

### `dwMediaType` [in]

[Media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) to check.

### `dwMask` [in]

Media types mask indicating types that can be handled.

## See also

[CMSPAddress](https://learn.microsoft.com/windows/desktop/api/mspaddr/nl-mspaddr-cmspaddress)