# ITextStoreAnchorSink::OnAttrsChange

## Description

The **ITextStoreAnchorSink::OnAttrsChange** method is called when the value of one or more text attributes changes.

## Parameters

### `paStart` [in]

Pointer to the start anchor of the range of text that has the attribute change.

### `paEnd` [in]

Pointer to the end anchor of the range of text that has the attribute change.

### `cAttrs` [in]

Specifies the number of attributes in the *paAttrs* array.

### `paAttrs` [in]

Pointer to an array of [TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid) values that identify the attributes changed.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## See also

[ITextStoreAnchor::FindNextAttrTransition](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-findnextattrtransition)

[ITextStoreAnchor::RequestAttrsAtPosition](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestattrsatposition)

[ITextStoreAnchor::RequestAttrsTransitioningAtPosition](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestattrstransitioningatposition)

[ITextStoreAnchor::RequestSupportedAttrs](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestsupportedattrs)

[ITextStoreAnchorSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchorsink)