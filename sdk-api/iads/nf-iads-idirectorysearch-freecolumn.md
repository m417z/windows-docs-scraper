# IDirectorySearch::FreeColumn

## Description

The **IDirectorySearch::FreeColumn** method
releases memory that the
[IDirectorySearch::GetColumn](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getcolumn) method allocated
for data for the column.

## Parameters

### `pSearchColumn` [in]

Provides a pointer to the column to be freed.

## Return value

This method returns the standard return values, as well as the following:

For other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)

[IDirectorySearch::GetColumn](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getcolumn)