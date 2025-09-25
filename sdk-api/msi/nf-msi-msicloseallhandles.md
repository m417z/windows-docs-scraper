# MsiCloseAllHandles function

## Description

The
**MsiCloseAllHandles** function closes all open installation handles allocated by the current thread. This is a diagnostic function and should not be used for cleanup.

## Return value

This function returns 0 if all handles are closed. Otherwise, the function returns the number of handles open prior to its call.

## Remarks

**MsiCloseAllHandles** only closes handles allocated by the calling thread, and does not affect handles allocated by other threads, such as the install handle passed to custom actions.

The
[MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea) function opens a handle to a package and the
[MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta) function opens a handle to a product. These function are for use with functions that access the product database.

## See also

[Handle Management Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)