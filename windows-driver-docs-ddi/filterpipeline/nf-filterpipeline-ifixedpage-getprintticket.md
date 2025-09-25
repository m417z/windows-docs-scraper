# IFixedPage::GetPrintTicket

## Description

The **GetPrintTicket** method gets the print ticket object for the fixed page.

## Parameters

### `ppPrintTicket` [out]

Pointer to a location into which the method writes a pointer to the [IPartPrintTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ipartprintticket) interface of a print ticket object. This object contains the print ticket for the fixed page.

## Return value

**GetPrintTicket** returns an **HRESULT** value. If a print ticket is not in the fixed page, **GetPrintTicket** might return E_ELEMENT_NOT_FOUND.

## Remarks

After calling this method to get the page-level print ticket, a print driver filter can obtain the *effective* print ticket for the fixed page by merging the page-level print ticket with the document-level print ticket and the job-level print ticket. The filter can get the document-level and job-level print tickets by calling the [IFixedDocument::GetPrintTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-ifixeddocument-getprintticket) and [IFixedDocumentSequence::GetPrintTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-ifixeddocumentsequence-getprintticket) methods. For more information about merging print tickets, see [Print Ticket Merging](https://learn.microsoft.com/windows-hardware/drivers/print/print-ticket-merging).

## See also

[IFixedDocument::GetPrintTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-ifixeddocument-getprintticket)

[IFixedDocumentSequence::GetPrintTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-ifixeddocumentsequence-getprintticket)

[IFixedPage](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ifixedpage)

[IPartPrintTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ipartprintticket)