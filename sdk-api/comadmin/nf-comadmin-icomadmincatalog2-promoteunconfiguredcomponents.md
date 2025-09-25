# ICOMAdminCatalog2::PromoteUnconfiguredComponents

## Description

Promotes the specified classes from unconfigured components to configured components.

**Note** Before calling this method, its necessary to first import the unconfigured components by using the [ImportUnconfiguredComponents](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-importunconfiguredcomponents) method. Otherwise, this method returns an E_INVALIDARG error.

## Parameters

### `bstrApplicationIDOrName` [in]

The application ID or name of the application containing the components to be promoted.

### `pVarCLSIDOrProgID` [in]

The unconfigured components to be promoted. Each element of the **Variant** may be a **String** containing a class ID or program ID, a single catalog object, or a catalog collection (for example, as returned by the [GetCollectionByQuery2](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-getcollectionbyquery2) method).

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