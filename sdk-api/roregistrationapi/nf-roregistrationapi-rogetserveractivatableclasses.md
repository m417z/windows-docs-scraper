# RoGetServerActivatableClasses function

## Description

Retrieves the activatable classes that are registered for a given executable (EXE) server, which was registered under the package ID of the calling process.

## Parameters

### `serverName` [in]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)**

The name of the server to retrieve class registrations for. This server name is passed on the command line when the server is activated.

### `activatableClassIds` [out]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)****

A callee-allocated array of activatable class ID strings which the server is registered to serve. The strings must be released by the caller using the [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring) function. The buffer must then be released using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). The server (caller) is responsible for registering the activation factories for these classes.

### `count` [out]

Type: **DWORD***

The count of activatable class IDs returned in the *activatableClassIds* array.

## Return value

Type: **HRESULT**

The method returns **S_OK** on success, otherwise an error code, including the following.

| Return code | Description |
| --- | --- |
| **REGDB_E_CLASSNOTREG** | An empty server name is provided, the server is not registered, or no classes are registered for this server. |
| **E_ACCESSDENIED** | The process does not have sufficient permissions to read this server’s registration. |

## Remarks

Use the **RoGetServerActivatableClasses** function to retrieve the class names that the server is expected to serve. Get the details on the individual classes by calling the [RoGetActivatableClassRegistration](https://learn.microsoft.com/windows/desktop/api/roregistrationapi/nf-roregistrationapi-rogetactivatableclassregistration) function on each class name individually.