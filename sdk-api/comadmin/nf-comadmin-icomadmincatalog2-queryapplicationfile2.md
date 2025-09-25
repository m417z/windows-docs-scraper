# ICOMAdminCatalog2::QueryApplicationFile2

## Description

Retrieves information about an application that is about to be installed.

## Parameters

### `bstrApplicationFile` [in]

The full path to the application file.

### `ppFilesForImport` [out, retval]

A pointer to an [ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection) interface pointer that specifies the [FilesForImport](https://learn.microsoft.com/windows/desktop/cossdk/filesforimport) collection for the application.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)