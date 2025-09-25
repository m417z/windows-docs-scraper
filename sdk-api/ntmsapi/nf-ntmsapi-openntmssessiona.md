# OpenNtmsSessionA function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**OpenNtmsSession** function sets up a session with a RSM server.

## Parameters

### `lpServer` [in]

RSM server name. If this parameter is **NULL**, the current computer name is used.

### `lpApplication` [in]

Unique character string that identifies the application. This name identifies resources and operator requests. This parameter is optional and may be **NULL**.

### `dwOptions`

Reserved; must be zero.

## Return value

If
**OpenNtmsSession** succeeds, it returns a handle that uniquely identifies this session. If the function fails, it returns INVALID_HANDLE_VALUE. To retrieve more information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. This function can return one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_COMPUTERNAME** | The computer name format that was specified was not in a valid format. |
| **ERROR_INVALID_PARAMETER** | One of the parameter values was not valid. |
| **ERROR_NO_NETWORK** | The network is not started or not available. |
| **ERROR_NOT_CONNECTED** | Unable to connect to the RSM service. |
| **ERROR_NOT_READY** | RSM service has not started. The application should wait and retry. |
| **ERROR_SUCCESS** | The function was successful. |
| **INVALID_HANDLE_VALUE** | RSM cannot open a session. |
| **RPC_S_NO_INTERFACES** | The service is using an older version of RSM than your application. |

## Remarks

The
**OpenNtmsSession** function returns a session handle used with other RSM functions, establishes a connection with the RSM database, and initializes the RSM subsystem for the application.

When
**OpenNtmsSession** returns, the application can perform RSM operations.

Sessions are thread-safe but cannot be passed among processes.

> [!NOTE]
> The ntmsapi.h header defines OpenNtmsSession as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-closentmssession)

[Session Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)