# IXpsOMDocumentSequence::SetPrintTicketResource

## Description

Sets the job-level print ticket resource for the document sequence.

## Parameters

### `printTicketResource` [in]

A pointer to the [IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource) interface of the job-level print ticket that will be set for the document sequence.
If the document sequence has a print ticket resource, a **NULL** pointer will release it.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

If the document contains an [IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource) interface when this method is called, that interface is released before the new **IXpsOMPrintTicketResource** interface, which is passed in *printTicketResource*, is set.

## See also

[IXpsOMDocumentSequence](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentsequence)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)