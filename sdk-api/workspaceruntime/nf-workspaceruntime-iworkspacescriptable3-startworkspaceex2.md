# IWorkspaceScriptable3::StartWorkspaceEx2

## Description

Not implemented.

Associates user credentials and certificates with a connection ID.

## Parameters

### `bstrWorkspaceId` [in]

A string that contains the connection ID.

### `bstrWorkspaceFriendlyName` [in]

TBD

### `bstrRedirectorName` [in]

TBD

### `bstrUserName` [in]

A string that contains a user name.

### `bstrPassword` [in]

A string that contains a password.

### `bstrAppContainer` [in]

TBD

### `bstrWorkspaceParams` [in]

A string that contains one or more Secure Hash Algorithm 1 (SHA-1) hashes of signing certificates to associate with the specified connection ID. The hash values should be in hexadecimal string format and delimited by semicolons.

### `lTimeout` [in]

The time period, in minutes, after which the credentials are deleted.

### `lFlags` [in]

A flag that specifies properties of the user credentials. This can be a bitwise **OR** of the following values.

#### WKS_FLAG_CLEAR_CREDS_ON_LAST_RESOURCE (1 (0x1))

Delete credentials as soon as the last RemoteApp application is closed.

#### WKS_FLAG_PASSWORD_ENCRYPTED (2 (0x2))

The password is encrypted.

#### WKS_FLAG_CREDS_AUTHENTICATED (4 (0x4))

The user credentials are verified. If this flag is not set, you must call the [OnAuthenticated](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee351600(v=vs.85)) method before using the credentials.

### `bstrEventLogUploadAddress` [in]

TBD

### `correlationId` [in]

TBD

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list.

## See also

[IWorkspaceScriptable3](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable3)