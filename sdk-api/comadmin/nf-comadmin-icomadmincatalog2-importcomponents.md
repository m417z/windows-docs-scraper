# ICOMAdminCatalog2::ImportComponents

## Description

Imports the specified components that are already registered into an application.

To import unconfigured components, you can use the [ImportUnconfiguredComponents](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-importunconfiguredcomponents) and [PromoteUnconfiguredComponents](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-promoteunconfiguredcomponents) methods.

## Parameters

### `bstrApplicationIDOrName` [in]

The application ID or name of the application into which the components are to be imported.

### `pVarCLSIDOrProgID` [in]

The components to be imported. Each element of the **Variant** may be a **String** containing a class ID or program ID, a single catalog object, or a catalog collection (for example, as returned by the [GetCollectionByQuery2](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-getcollectionbyquery2) method).

### `pVarComponentType` [in, optional]

The bitnes of each component. This parameter can be one of the following values. If this parameter is omitted, the native bitness of the computer is assumed.

| Value | Meaning |
| --- | --- |
| **COMAdmin32BitComponent**<br><br>0x1 | Uses a 32-bit format. |
| **COMAdmin64BitComponent**<br><br>0x2 | Uses a 64-bit format. |

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)