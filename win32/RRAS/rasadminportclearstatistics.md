# RasAdminPortClearStatistics function

\[This function is provided only for backward compatibility with Windows NT Server 4.0. It returns ERROR\_CALL\_NOT\_IMPLEMENTED on Windows Server 2003. Applications should use the [**MprAdminPortClearStats**](https://learn.microsoft.com/windows/desktop/api/Mprapi/nf-mprapi-mpradminportclearstats) function.\]

The **RasAdminPortClearStatistics** function resets the counters representing the various statistics reported by the [**RasAdminPortGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminportgetinfo) function in the [**RAS\_PORT\_STATISTICS**](https://learn.microsoft.com/windows/win32/rras/ras-port-statistics-str) structure. The counters are reset to zero and start accumulating.

## Parameters

*lpszServer* \[in\]

Pointer to a null-terminated Unicode string that specifies the name of the RAS server. Specify the name with leading "\\\\" characters, in the form: \\\\*servername*.

*lpszPort* \[in\]

Pointer to a null-terminated Unicode string that specifies the name of the port on the server.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value can be the following error code.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------|-------------------------------------------|
| **ERROR\_DEV\_NOT\_EXIST** | The specified port is invalid.<br> |

There is no extended error information for this function; do not call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **RasAdminPortClearStatistics** function clears the statistics on the server, not locally within the application that makes the call. This means that the statistics are also reset for any other application that is monitoring the specified port.

If the *lpszPort* port is part of a multilink connection, **RasAdminPortClearStatistics** resets the statistics for the specified port, The function also resets the cumulative statistics for the multilink connection. However, the function does not affect the individual statistics for other ports that are part of the multilink connection.

## Requirements

| Requirement | Value |
|----------------------------------|----------------------------------------------------------------------------------------|
| End of client support<br> | Windows 2000 Professional<br> |
| End of server support<br> | Windows 2000 Server<br> |
| Header<br> | Rassapi.h |
| Library<br> | Rassapi.lib |
| DLL<br> | Rassapi.dll |

## See also

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/win32/rras/about-remote-access-service)

[RAS Server Administration Functions](https://learn.microsoft.com/windows/win32/rras/ras-server-administration-functions)

[**RAS\_PORT\_STATISTICS**](https://learn.microsoft.com/windows/win32/rras/ras-port-statistics-str)

[**RasAdminPortGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminportgetinfo)

