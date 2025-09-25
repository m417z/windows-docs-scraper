# WdsCliCreateSession function

## Description

Starts a new session with a WDS server.

## Parameters

### `pwszServer` [in]

A pointer to a string value that contains the name or IP address of the WDS server.

### `pCred` [in, optional]

A pointer to a [WDS_CLI_CRED](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/ns-wdsclientapi-wds_cli_cred) structure that contains the
client's credentials. This parameter can be null for a session without authentication.

### `phSession` [out]

A pointer to a handle for the new session. This parameter is unmodified if the function is unsuccessful.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To close
the session and release resources, use the [WdsCliClose](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliclose) function.

## See also

[WDS_CLI_CRED](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/ns-wdsclientapi-wds_cli_cred)

[WdsCliClose](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliclose)

[Windows Deployment Services Client Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-client-functions)