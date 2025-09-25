# ITextStoreACP2::RetrieveRequestedAttrs

## Description

Gets the attributes returned by a call to an attribute request method.

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

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)

[RequestAttrsAtPosition](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-requestattrsatposition)

[RequestAttrsTransitioningAtPosition](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-requestattrstransitioningatposition)

[RequestSupportedAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-requestsupportedattrs)

[TS_ATTRVAL](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_attrval)