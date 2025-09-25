# IComAppEvents::OnAppForceShutdown

## Description

Generated when an application server is forced to shut down. This is usually initiated by the user calling a catalog method, such as [ICOMAdminCatalog::ShutdownApplication](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog-shutdownapplication), to shut down the server.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidApp` [in]

The globally unique identifier (GUID) of the application.

## Return value

The user verifies the return values from this method.

## See also

[IComAppEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomappevents)