# ICOMAdminCatalog2::AreApplicationInstancesPaused

## Description

Determines whether any of the specified application instances (processes) are paused.

## Parameters

### `pVarApplicationInstanceID` [in]

The application instances to be checked. Each element of the **Variant** may be a **String** containing an application instance ID (for example, as returned by the [GetApplicationInstanceIDFromProcessID](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-getapplicationinstanceidfromprocessid) method), a single catalog object, or a catalog collection (for example, as returned by the [GetCollectionByQuery2](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-getcollectionbyquery2) method).

### `pVarBoolPaused` [out, retval]

Indicates whether the specified applications are paused.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADIN_E_OBJECT_DOES_NOT_EXIST** | A specified application instance does not exist. |

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)