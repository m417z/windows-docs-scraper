# ICOMAdminCatalog2::AliasComponent

## Description

Creates an alias for an existing COM+ component.

## Parameters

### `bstrSrcApplicationIDOrName` [in]

The application ID or name of the source application containing the component.

### `bstrCLSIDOrProgID` [in]

The class ID or program ID of the component for which an alias is created.

### `bstrDestApplicationIDOrName` [in]

The application ID or the name of the destination application that contains the alias. If this argument is **NULL** or an empty string, the alias is created within the source application.

### `bstrNewProgId` [in]

The program ID of the alias.

### `bstrNewClsid` [in]

The class ID of the alias. If this argument is **NULL** or an empty string, a new, unique class ID is assigned.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_AMBIGUOUS_APPLICATION_NAME** | At least one of the named applications exists in multiple partitions. To avoid this error, use application IDs instead of names. |

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)