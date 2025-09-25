# MsiViewClose function

## Description

The
**MsiViewClose** function releases the result set for an executed view.

## Parameters

### `hView` [in]

Handle to a view that is set to release.

## Return value

Note that in low memory situations, this function can raise a STATUS_NO_MEMORY exception.

## Remarks

The
**MsiViewClose** function must be called before the
[MsiViewExecute](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewexecute) function is called again on the view, unless all rows of the result set have been obtained with the
[MsiViewFetch](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewfetch) function.

## See also

[General Database Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)