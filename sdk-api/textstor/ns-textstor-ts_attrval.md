# TS_ATTRVAL structure

## Description

The **TS_ATTRVAL** structure contains document attribute values.

## Members

### `idAttr`

GUID for the attribute type.

### `dwOverlapId`

A unique identifier of this attribute when overlapped with other attributes. This is a feature in [Microsoft Active Accessibility](https://learn.microsoft.com/previous-versions/ms971350(v=msdn.10)). In TSF, this parameter value is zero (0). Any nonzero value is ignored.

### `varValue`

Value of the attribute.

## Remarks

An application uses attributes to expose its data to TSF, whereas text services use properties to expose their data to TSF. **TS_ATTRVAL** is used in [ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp) and [ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor) methods.

## See also

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITextStoreACP::RequestAttrsTransitioningAtPosition](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-requestattrstransitioningatposition)

[ITextStoreACP::RequestSupportedAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-requestsupportedattrs)

[ITextStoreACP::RetrieveRequestedAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-retrieverequestedattrs)

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::RequestAttrsTransitioningAtPosition](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestattrstransitioningatposition)

[ITextStoreAnchor::RequestSupportedAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestsupportedattrs)

[ITextStoreAnchor::RetrieveRequestedAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-retrieverequestedattrs)

[Microsoft Active Accessibility](https://learn.microsoft.com/previous-versions/ms971350(v=msdn.10))

[TF_PROPERTYVAL](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_propertyval)

[TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid)