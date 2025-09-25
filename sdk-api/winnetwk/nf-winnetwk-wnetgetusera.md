# WNetGetUserA function

## Description

The
**WNetGetUser** function retrieves the current default user name, or the user name used to establish a network connection.

## Parameters

### `lpName` [in]

A pointer to a constant **null**-terminated string that specifies either the name of a local device that has been redirected to a network resource, or the remote name of a network resource to which a connection has been made without redirecting a local device.

If this parameter is **NULL** or the empty string, the system returns the name of the current user for the process.

### `lpUserName` [out]

A pointer to a buffer that receives the **null**-terminated user name.

### `lpnLength` [in, out]

A pointer to a variable that specifies the size of the *lpUserName* buffer, in characters. If the call fails because the buffer is not large enough, this variable contains the required buffer size.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_CONNECTED** | The device specified by the *lpName* parameter is not a redirected device or a connected network name. |
| **ERROR_MORE_DATA** | More entries are available with subsequent calls. |
| **ERROR_NO_NETWORK** | The network is unavailable. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. To obtain a description of the error, call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function. |
| **ERROR_NO_NET_OR_BAD_PATH** | None of the providers recognize the local name as having a connection. However, the network is not available for at least one provider to whom the connection may belong. |

## Remarks

The **WNetGetUser** function is not aware of shares on the Distributed File System (DFS). If the name specified by the *lpName* parameter is a local device redirected to a DFS share or a remote resource that represents a DFS share, the **WNetGetUser** function fails with ERROR_NOT_CONNECTED.

#### Examples

The following code sample illustrates how to use the
**WNetGetUser** function to retrieve the name of the user associated with a redirected local device or a remote network resource.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "mpr.lib")

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <Winnetwk.h>

int wmain(int argc, wchar_t * argv[])
{
    DWORD dwRetVal;

    WCHAR UserName[MAX_PATH];

    DWORD dwNameLength = MAX_PATH;

    if (argc != 2) {
        wprintf
            (L"Usage: %s [Redirected-LocalDevice or Network-Resource-Remote-name\n",
             argv[0]);
        exit(1);
    }

    wprintf(L"Calling WNetGetUser with Network-Resource = %s\n", argv[1]);

    dwRetVal = WNetGetUser(argv[1], UserName, &dwNameLength);
    //
    // If the call succeeds, print the user information.
    //
    if (dwRetVal == NO_ERROR) {

        wprintf(L"WNetGetUser returned success\n");
        wprintf(L"\tUsername=%s   NameLength=%d\n", &UserName, dwNameLength);
        exit(0);
    }

    else {
        wprintf(L"WNetGetUser failed with error: %u\n", dwRetVal);
        exit(1);
    }
}

```

> [!NOTE]
> The winnetwk.h header defines WNetGetUser as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Retrieving the User Name](https://learn.microsoft.com/windows/desktop/WNet/retrieving-the-user-name)

[WNetGetConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetconnectiona)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)