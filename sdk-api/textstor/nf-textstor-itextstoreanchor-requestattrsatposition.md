# ITextStoreAnchor::RequestAttrsAtPosition

## Description

Obtains a list of attributes that begin or end at the specified anchor location.

## Parameters

### `paPos` [in]

Pointer to the anchor.

### `cFilterAttrs` [in]

Specifies the number of attributes to obtain.

### `paFilterAttrs` [in]

Pointer to the [TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid) data type that specifies the attribute to verify.

### `dwFlags` [in]

Must be zero.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The *paPos* anchor is invalid. |

## See also

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::RetrieveRequestedAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-retrieverequestedattrs)

[TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid)