# WNetGetUniversalNameA function

## Description

The
**WNetGetUniversalName** function takes a drive-based path for a network resource and returns an information structure that contains a more universal form of the name.

## Parameters

### `lpLocalPath` [in]

A pointer to a constant null-terminated string that is a drive-based path for a network resource.

For example, if drive H has been mapped to a network drive share, and the network resource of interest is a file named Sample.doc in the directory \Win32\Examples on that share, the drive-based path is H:\Win32\Examples\Sample.doc.

### `dwInfoLevel` [in]

The type of structure that the function stores in the buffer pointed to by the *lpBuffer* parameter. This parameter can be one of the following values defined in the *Winnetwk.h* header file.

| Value | Meaning |
| --- | --- |
| **UNIVERSAL_NAME_INFO_LEVEL** | The function stores a [UNIVERSAL_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-universal_name_infoa) structure in the buffer. |
| **REMOTE_NAME_INFO_LEVEL** | The function stores a [REMOTE_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-remote_name_infow) structure in the buffer. |

The
[UNIVERSAL_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-universal_name_infoa) structure points to a Universal Naming Convention (UNC) name string.

The
[REMOTE_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-remote_name_infow) structure points to a UNC name string and two additional connection information strings. For more information, see the following Remarks section.

### `lpBuffer` [out]

A pointer to a buffer that receives the structure specified by the *dwInfoLevel* parameter.

### `lpBufferSize` [in, out]

A pointer to a variable that specifies the size, in bytes, of the buffer pointed to by the *lpBuffer* parameter.

If the function succeeds, it sets the variable pointed to by *lpBufferSize* to the number of bytes stored in the buffer. If the function fails because the buffer is too small, this location receives the required buffer size, and the function returns ERROR_MORE_DATA.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_DEVICE** | The string pointed to by the *lpLocalPath* parameter is invalid. |
| **ERROR_CONNECTION_UNAVAIL** | There is no current connection to the remote device, but there is a remembered (persistent) connection to it. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. Use the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function to obtain a description of the error. |
| **ERROR_MORE_DATA** | The buffer pointed to by the *lpBuffer* parameter is too small. The function sets the variable pointed to by the *lpBufferSize* parameter to the required buffer size. More entries are available with subsequent calls. |
| **ERROR_NOT_SUPPORTED** | The *dwInfoLevel* parameter is set to UNIVERSAL_NAME_INFO_LEVEL, but the network provider does not support UNC names. (None of the network providers support this function.) |
| **ERROR_NO_NET_OR_BAD_PATH** | None of the network providers recognize the local name as having a connection. However, the network is not available for at least one provider to whom the connection may belong. |
| **ERROR_NO_NETWORK** | The network is unavailable. |
| **ERROR_NOT_CONNECTED** | The device specified by the *lpLocalPath* parameter is not redirected. |

## Remarks

A universal form of a local drive-based path identifies a network resource in an unambiguous, computer-independent manner. The name can then be passed to processes on other computers, allowing those processes to obtain access to the resource.

The
**WNetGetUniversalName** function currently supports one universal name form: universal naming convention (UNC) names, which look like the following:

``` syntax
\\servername\sharename\path\file

```

Using the example from the preceding description of the *lpLocalPath* parameter, if the shared network drive is on a server named COOLSERVER, and the share name is HOTSHARE, the UNC name for the network resource whose drive-based name is H:\Win32\Examples\Sample.doc would be the following:

``` syntax
\\coolserver\hotshare\win32\examples\sample.doc

```

The
[UNIVERSAL_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-universal_name_infoa) structure contains a pointer to a UNC name string. The
[REMOTE_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-remote_name_infow) structure also contains a pointer to a UNC name string as well as pointers to two other useful strings. For example, a process can pass the
**REMOTE_NAME_INFO** structure's **lpszConnectionInfo** member to the
[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a) function to connect a local device to the network resource. Then the process can append the string pointed to by the **lpszRemainingPath** member to the local device string. The resulting string can be passed to functions that require a drive-based path.

The *lpLocalPath* parameter does not have to specify a path or resource that is already present on a remote resource. For example, the *lpLocalPath* parameter could specify and folder, a hierarchy of folders, or a file that does not currently exist. The
**WNetGetUniversalName** function returns a more universal form of the name in these cases.

The size of the buffer pointed to by the *lpBuffer* parameter and specified in the *lpBufferSize* parameter must be much larger than the size of the [REMOTE_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-remote_name_infow)
or [UNIVERSAL_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-universal_name_infoa) structures. The buffer pointed to by the *lpBuffer* parameter must be large enough to store the UNC strings pointed to by the members in the **REMOTE_NAME_INFO**
or **UNIVERSAL_NAME_INFO** structures. If the buffer size is too small, then the function fails with ERROR_MORE_DATA and the variable pointed to by the *lpBufferSize* parameter indicates the required buffer size.

**Windows Server 2003 and Windows XP:** This function queries the MS-DOS device namespaces associated with a logon session because MS-DOS devices are identified by AuthenticationID. (An AuthenticationID is the
[locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly), or LUID, associated with a logon session.) This can affect applications that call one of the WNet functions to create a network drive letter under one user logon, but query for existing network drive letters under a different user logon. An example of this situation could be when a user's second logon is created within a logon session, for example, by calling the
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function, and the second logon runs an application that calls the
[GetLogicalDrives](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlogicaldrives) function. **GetLogicalDrives** does not return network drive letters created by a WNet function under the first logon. Note that in the preceding example the first logon session still exists, and the example could apply to any logon session, including a Terminal Services session. For more information, see
[Defining an MS-DOS Device Name](https://learn.microsoft.com/windows/desktop/FileIO/defining-an-ms-dos-device-name).

#### Examples

The following code sample illustrates how to use the
**WNetGetUniversalName** function to retrieve the universal UNC name strings associated with drive-based path for a network resource.

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

    WCHAR Buffer[1024];
    DWORD dwBufferLength = 1024;

    UNIVERSAL_NAME_INFO * unameinfo;
    REMOTE_NAME_INFO *remotenameinfo;

    wprintf(L"Calling WNetGetUniversalName with Local Path = %s\n", argv[1]);

    unameinfo = (UNIVERSAL_NAME_INFO *) &Buffer;
    dwRetVal = WNetGetUniversalName(argv[1], UNIVERSAL_NAME_INFO_LEVEL, (LPVOID) unameinfo, &dwBufferLength );
    //
    // If the call succeeds, print the user information.
    //
    if (dwRetVal == NO_ERROR) {

        wprintf(L"WNetGetUniversalName returned success for InfoLevel=UNIVERSAL_NAME_INFO_LEVEL\n");
        wprintf(L"\tUniversal name = %s\n", unameinfo->lpUniversalName);
    }

    else {
        wprintf(L"WNetGetUser failed for InfoLevel=UNIVERSAL_NAME_INFO_LEVEL with error: %u\n", dwRetVal);
    }

    remotenameinfo = (REMOTE_NAME_INFO *) &Buffer;
    dwRetVal = WNetGetUniversalName(argv[1], REMOTE_NAME_INFO_LEVEL,
        (LPVOID) remotenameinfo, &dwBufferLength );
    //
    // If the call succeeds, print the user information.
    //
    if (dwRetVal == NO_ERROR) {

        wprintf(L"WNetGetUniversalName returned success for InfoLevel=REMOTE_NAME_INFO_LEVEL\n");
        wprintf(L"\tUniversal name = %s\n", remotenameinfo->lpUniversalName);
        wprintf(L"\tConnection name = %s\n", remotenameinfo->lpConnectionName);
        wprintf(L"\tRemaining path = %s\n", remotenameinfo->lpRemainingPath);
    }

    else {
        wprintf(L"WNetGetUser failed for InfoLevel=REMOTE_NAME_INFO_LEVEL with error: %u\n", dwRetVal);
    }
}

```

> [!NOTE]
> The winnetwk.h header defines WNetGetUniversalName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Determining the Location of a Share](https://learn.microsoft.com/windows/desktop/WNet/determining-the-location-of-a-share)

[REMOTE_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-remote_name_infow)

[UNIVERSAL_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-universal_name_infoa)

[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)