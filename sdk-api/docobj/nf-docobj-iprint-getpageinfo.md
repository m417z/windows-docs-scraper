# IPrint::GetPageInfo

## Description

Retrieves the number of a document's first page and the total number of pages.

## Parameters

### `pnFirstPage` [out]

A pointer to a variable that receives the page number of the first page. This parameter can be **NULL**, indicating that the caller is not interested in this number. If [IPrint::SetInitialPageNum](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iprint-setinitialpagenum) has been called, this parameter should contain the same value passed to that method. Otherwise, the value is the document's internal first page number.

### `pcPages` [out]

A pointer to a variable that receives the total number of pages in this document. This parameter can be **NULL**, indicating that the caller is not interested in this number.

## Return value

This method can return the standard return values E_UNEXPECTED and S_OK.

## See also

[IPrint](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-iprint)