# IDsAdminNewObjExt::OnError

## Description

The **IDsAdminNewObjExt::OnError** method is called when an error has occurred in the wizard pages.

## Parameters

### `hWnd` [in]

The window handle used as the parent window for possible error messages.

### `hr` [in]

**HRESULT** of the error that occurred.

### `uContext` [in]

Specifies the context in which **OnError** is called. This will be one of the following values.

#### DSA_NEWOBJ_CTX_PRECOMMIT

An error occurred prior to the new object committed to persistent storage.

#### DSA_NEWOBJ_CTX_COMMIT

An error occurred while the new object was committed to persistent storage.

#### DSA_NEWOBJ_CTX_POSTCOMMIT

An error occurred after the new object was committed to persistent storage.

#### DSA_NEWOBJ_CTX_CLEANUP

An error occurred while the new object was committed to persistent storage.

## Return value

A primary creation extension returns **S_OK** to indicate that the error was handled by the extension or an OLE-defined error code to cause the system to display an error message.

The return value is ignored for a secondary creation extension.

## See also

[IDsAdminNewObjExt](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobjext)