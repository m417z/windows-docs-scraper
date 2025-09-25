# ITextStoreAnchor::RetrieveRequestedAttrs

## Description

Returns the attributes obtained by the RequestAttrsAtPosition, RequestAttrsTransitioningAtPosition, or RequestSupportedAttrs methods.

## Parameters

### `ulCount` [in]

Specifies the number of supported attributes to obtain.

### `paAttrVals` [out]

Pointer to the [TS_ATTRVAL](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_attrval) structure that receives the supported attributes. The members of this structure depend upon the *dwFlags* parameter of the calling method.

### `pcFetched` [out]

Receives the number of supported attributes.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::RequestAttrsAtPosition](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestattrsatposition)

[ITextStoreAnchor::RequestAttrsTransitioningAtPosition](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestattrstransitioningatposition)

[ITextStoreAnchor::RequestSupportedAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestsupportedattrs)

[TS_ATTRVAL](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_attrval)