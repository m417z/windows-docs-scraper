# ITextStoreACP::RequestAttrsAtPosition

## Description

Gets text attributes at the specified character position.

## Parameters

### `acpPos` [in]

Specifies the application character position in the document.

### `cFilterAttrs` [in]

Specifies the number of attributes to obtain.

### `paFilterAttrs` [in]

Pointer to the [TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid) data type that specifies the attribute to verify.

### `dwFlags` [in]

Must be zero.

## Return value

This method has no return values.

## See also

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITextStoreACP::RetrieveRequestedAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-retrieverequestedattrs)

[TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid)