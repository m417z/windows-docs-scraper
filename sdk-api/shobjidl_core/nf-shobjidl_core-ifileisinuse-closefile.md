# IFileIsInUse::CloseFile

## Description

Closes the file currently in use.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Only files that return the [capability flag](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileisinuse-getcapabilities) OF_CAP_CANCLOSE can be closed by this method. If that flag is returned, the user can be presented with a dialog box that includes a **Close** option that calls this method.