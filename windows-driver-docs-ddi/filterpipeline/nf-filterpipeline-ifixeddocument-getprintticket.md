# IFixedDocument::GetPrintTicket

## Description

The **GetPrintTicket** method gets the print ticket object for the fixed document.

## Parameters

### `ppPrintTicket` [out]

The print ticket object for the fixed document.

## Return value

**GetPrintTicket** returns an **HRESULT** value. If a print ticket is not in the fixed document, this method might return E_ELEMENT_NOT_FOUND.