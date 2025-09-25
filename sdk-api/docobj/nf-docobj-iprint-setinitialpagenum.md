# IPrint::SetInitialPageNum

## Description

Sets the page number of the first page of a document.

## Parameters

### `nFirstPage` [in]

The page number of the first page.

## Return value

This method can return the standard return values E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

Setting the first page to a negative number is valid. This may be useful in printing a portion of the document with page numbers that specify an offset from the usual pagination.

Not all implementations permit the initial page number to be set, as some implementations simply lack the information as to how the page number should be presented in the final output.

## See also

[IPrint](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-iprint)