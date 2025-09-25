# PxeGetServerInfo function

## Description

Returns information about the PXE server.

## Parameters

### `uInfoType` [in]

Selects the information that will be returned.

| Value | Meaning |
| --- | --- |
| **PXE_GSI_TRACE_ENABLED**<br><br>1 | Returns a **BOOL** that indicates whether tracing is enabled for the server. **TRUE** indicates that tracing is enabled. |

### `pBuffer` [out]

Address of a buffer that will receive the results of the query. The size and format of the results depends
on the value of the *uInfoType* parameter.

### `uBufferLen` [in]

Size of buffer pointed to by the *pBuffer* parameter.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)