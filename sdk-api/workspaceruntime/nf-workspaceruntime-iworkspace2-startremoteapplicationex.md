# IWorkspace2::StartRemoteApplicationEx

## Description

Not supported.

Starts a RemoteApp program with additional options and features.

## Parameters

### `bstrWorkspaceId` [in]

A string that contains the ID of the connection in which to the start the application.

### `bstrRequestingAppId` [in]

A string that contains the ID of an application to launch on the remote desktop.

### `bstrRequestingAppFamilyName` [in]

A string that contains the family name of the application to launch.

### `bLaunchIntoImmersiveClient` [in]

**VARIANT_TRUE** to make the remote application launch as though it were accessed via the web client, using the modern Remote Desktop protocol. **VARIANT_FALSE** to make the remote application launch using classic Terminal Server methodology.

### `bstrImmersiveClientActivationContext` [in]

A string containing the context for the specific remote desktop client.

### `psaParams` [in]

A pointer to an array of **BSTR** values that contains parameters to pass to the workspace runtime.

For RDP connections, this parameter contains two strings:

* Serialized RDP file
* Command line parameters for Remote Desktop Connection client

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**StartRemoteApplicationEx** contains a number of new features: launching a 3rd party application when the remote desktop first starts, handling multiple remote desktops, and launching with the web-based client UI.

## See also

[IWorkspace2](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspace2)

[IWorkspace3](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspace3)