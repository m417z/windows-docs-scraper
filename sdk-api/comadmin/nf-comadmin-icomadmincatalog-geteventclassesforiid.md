# ICOMAdminCatalog::GetEventClassesForIID

## Description

Retrieves a list of the event classes registered on the computer that implement a specified interface.

## Parameters

### `bstrIID` [in]

A GUID representing the interface for which event classes should be found. If this parameter is **NULL**, the method retrieves all event classes registered on the computer.

### `ppsaVarCLSIDs` [out]

An array of CLSIDs for the event classes implementing the interface specified in *bstrIID*.

### `ppsaVarProgIDs` [out]

An array of ProgIDs for the event classes implementing the interface specified in *bstrIID*.

### `ppsaVarDescriptions` [out]

An array of descriptions for the event classes implementing the interface specified in *bstrIID*.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)