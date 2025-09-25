# IFixedDocumentSequence::GetPrintTicket

## Description

The **GetPrintTicket** method gets the print ticket object for the fixed document sequence.

## Parameters

### `ppPrintTicket` [out]

The print ticket object for the sequence.

## Return value

**GetPrintTicket** returns an **HRESULT** value. If a print ticket is not in the fixed document sequence, **GetPrintTicket** might return E_ELEMENT_NOT_FOUND.