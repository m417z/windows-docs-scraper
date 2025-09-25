# IWdsTransportSetupManager::RegisterContentProvider

## Description

Enables an application run on a client computer to register a content provider DLL. This makes the provider available for use by the WDS transport server.

## Parameters

### `bszName` [in]

The name of the content provider to be registered. This name must be unique on the server.

### `bszDescription` [in]

A description of the content provider that can be read by an administrator.

### `bszFilePath` [in]

The full path to the DLL that implements the content provider. The path can include environment variables.

### `bszInitializationRoutine` [in]

The name of a function exported by the content provider that the WDS transport server can use to initialize the provider.

## Return value

Standard HRESULT error values are used: S_OK for success; others for failure.

## Remarks

To enable a multicast provider to support unauthenticated connections, the provider developer can add the **AllowUnAuth** key to the registry and set its **DWORD** value equal to 1.

**HKLM**\**System**\**CurrentControlSet**\**Services**\**WDSServer**\**Providers**\**WDSMC**\**Providers**\***Content Provider Name (i.e. bszName)***\**AllowUnauth**

## See also

[IWdsTransportSetupManager](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportsetupmanager)