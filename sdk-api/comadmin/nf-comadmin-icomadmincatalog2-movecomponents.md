# ICOMAdminCatalog2::MoveComponents

## Description

Moves the specified components from one application to another.

## Parameters

### `bstrSourceApplicationIDOrName` [in]

The application ID or name of the source application.

### `pVarCLSIDOrProgID` [in]

The components to be moved. Each element of the **Variant** may be a **String** containing a class ID or program ID, a single catalog object, or a catalog collection (for example, as returned by the [GetCollectionByQuery2](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-getcollectionbyquery2) method).

### `bstrDestinationApplicationIDOrName` [in]

The application ID or name of the destination application.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADIN_E_AMBIGUOUS_APPLICATION_NAME** | At least one of the named applications exists in multiple partitions. To avoid this error, use application IDs instead of names. |

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)