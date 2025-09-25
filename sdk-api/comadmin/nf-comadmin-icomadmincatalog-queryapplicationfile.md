# ICOMAdminCatalog::QueryApplicationFile

## Description

Retrieves information about a COM+ application from an application file.

## Parameters

### `bstrApplicationFile` [in]

The application file from which information is to be retrieved.

### `pbstrApplicationName` [out]

The application name in the specified file.

### `pbstrApplicationDescription` [out]

The application description.

### `pbHasUsers` [out]

Indicates whether the application has user information associated with its roles.

### `pbIsProxy` [out]

Indicates whether the file contains an application proxy.

### `ppsaVarFileNames` [out]

An array of names of the DLL files for the components installed in the application.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)