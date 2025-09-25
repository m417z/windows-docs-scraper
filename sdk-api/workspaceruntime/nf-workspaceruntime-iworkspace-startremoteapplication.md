# IWorkspace::StartRemoteApplication

## Description

Starts a RemoteApp program.

## Parameters

### `bstrWorkspaceId` [in]

A string that contains the ID of the connection in which to the start the application.

### `psaParams` [in]

A pointer to an array of **BSTR** values that contains parameters to pass to the workspace runtime.

For RDP connections, this parameter contains two strings:

* Serialized RDP file
* Command line parameters for Remote Desktop Connection client

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling the **StartRemoteApplication** method can result in a new connection.

When a custom client calls the **StartRemoteApplication** method, the workspace runtime verifies that the RDP file is properly signed. If the RDP file signature is not valid, the user is prompted for new credentials with which to validate the file.

## See also

[IWorkspace](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspace)

[IWorkspace2](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspace2)

[IWorkspace3](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspace3)