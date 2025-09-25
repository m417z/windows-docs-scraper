# ICOMAdminCatalog::InstallEventClass

## Description

Installs event classes from a file into a COM+ application.

## Parameters

### `bstrApplIdOrName` [in]

The GUID or name of the application.

### `bstrDLL` [in]

The file name of the DLL containing the event classes to be installed.

### `bstrTLB` [in]

The name of an external type library file. If the type library file is embedded in the DLL, pass in an empty string for this parameter.

### `bstrPSDLL` [in]

The name of the proxy-stub DLL file. If there is no proxy-stub DLL associated with the event class, pass in an empty string for this parameter.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

Use **InstallEventClass** to install event classes from a DLL holding dummy implementations of the event classes. The requirements are a self-registering DLL, a type library describing the interfaces implemented by the event classes, and each event class having a CLSID and a ProgID.

The dummy implementation of the interface exposed by an event class never actually runs; it exists only to register the event class. Instead, when the event class is created by the publisher, an implementation is provided by the Events system to send the event to subscribers.

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)