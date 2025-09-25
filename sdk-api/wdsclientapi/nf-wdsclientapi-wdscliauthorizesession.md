# WdsCliAuthorizeSession function

## Description

Converts a session with a WDS server into an authenticated session.

## Parameters

### `hSession` [in, out]

A handle to a session with a WDS server. This was a handle returned by
the [WdsCliCreateSession](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclicreatesession) function.

### `pCred` [in, optional]

Pointer to a [WDS_CLI_CRED](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/ns-wdsclientapi-wds_cli_cred) structure that contains the
client's credentials.

## Return value

If the function succeeds, the return is **S_OK**.

## See also

[WDS_CLI_CRED](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/ns-wdsclientapi-wds_cli_cred)

[WdsCliCreateSession](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclicreatesession)

[Windows Deployment Services Client Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-client-functions)