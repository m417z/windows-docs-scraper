# ICOMAdminCatalog::InstallMultipleEventClasses

## Description

Installs event classes from multiple files into a COM+ application.

## Parameters

### `bstrApplIdOrName` [in]

The GUID or name of the application.

### `ppsaVarFileNames` [in]

An array of the names of the DLL files that contains the event classes to be installed.

### `ppsaVarCLSIDS` [in]

An array of CLSIDs for the event classes to be installed.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

Use **InstallMultipleEventClasses** to install event classes from DLLs holding dummy implementations of the event classes. The requirements are a self-registering DLL, a type library describing the interfaces implemented by the event classes, and each event class having a CLSID and a ProgID.

The dummy implementation of the interface exposed by an event class never actually runs; it exists only to register the event class. Instead, when the event class is created by the publisher, an implementation is provided by the Events system to send the event to subscribers.

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)