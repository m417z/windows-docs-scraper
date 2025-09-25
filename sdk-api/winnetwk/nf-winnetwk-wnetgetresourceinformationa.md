# WNetGetResourceInformationA function

## Description

When provided with a remote path to a network resource, the
**WNetGetResourceInformation** function identifies the network provider that owns the resource and obtains information about the type of the resource. The function is typically used in conjunction with the
[WNetGetResourceParent](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetresourceparenta) function to parse and interpret a network path typed in by a user.

## Parameters

### `lpNetResource` [in]

Pointer to a
[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) structure that specifies the network resource for which information is required.

The **lpRemoteName** member of the structure should specify the remote path name of the resource, typically one typed in by a user. The **lpProvider** and **dwType** members should also be filled in if known, because this operation can be memory intensive, especially if you do not specify the **dwType** member. If you do not know the values for these members, you should set them to **NULL**. All other members of the
**NETRESOURCE** structure are ignored.

### `lpBuffer` [out]

Pointer to the buffer to receive the result. On successful return, the first portion of the buffer is a
[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) structure representing that portion of the input resource path that is accessed through the WNet functions, rather than through system functions specific to the input resource type. (The remainder of the buffer contains the variable-length strings to which the members of the
**NETRESOURCE** structure point.)

For example, if the input remote resource path is \\server\share\dir1\dir2, then the output
**NETRESOURCE** structure contains information about the resource \\server\share. The \dir1\dir2 portion of the path is accessed through the
[file management functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions). The **lpRemoteName**, **lpProvider**, **dwType**, **dwDisplayType**, and **dwUsage** members of
**NETRESOURCE** are returned, with all other members set to **NULL**.

The **lpRemoteName** member is returned in the same syntax as the one returned from an enumeration by the
[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea) function. This allows the caller to perform a string comparison to determine whether the resource passed to
**WNetGetResourceInformation** is the same as the resource returned by a separate call to
**WNetEnumResource**.

### `lpcbBuffer` [in, out]

Pointer to a location that, on entry, specifies the size of the *lpBuffer* buffer, in bytes. The buffer you allocate must be large enough to hold the
**NETRESOURCE** structure, plus the strings to which its members point. If the buffer is too small for the result, this location receives the required buffer size, and the function returns ERROR_MORE_DATA.

### `lplpSystem` [out]

If the function returns successfully, this parameter points to a string in the output buffer that specifies the part of the resource that is accessed through system functions. (This applies only to functions specific to the resource type rather than the WNet functions.)

For example, if the input remote resource name is \\server\share\dir1\dir2, the **lpRemoteName** member of the output
[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) structure points to \\server\share. Also, the *lplpSystem* parameter points to \dir1\dir2. Both strings are stored in the buffer pointed to by the *lpBuffer* parameter.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_NET_NAME** | The input **lpRemoteName** member is not an existing network resource for any network. |
| **ERROR_BAD_DEV_TYPE** | The input **dwType** member does not match the type of resource specified by the **lpRemoteName** member. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. Call [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) to obtain a description of the error. |
| **ERROR_MORE_DATA** | The buffer pointed to by the *lpBuffer* parameter is too small. |
| **ERROR_NO_NETWORK** | The network is unavailable. |

## See also

[WNetGetNetworkInformation](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetnetworkinformationa)

[WNetGetProviderName](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetprovidernamea)

[WNetGetResourceParent](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetresourceparenta)

[WNetGetUniversalName](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetuniversalnamea)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)

## Remarks

> [!NOTE]
> The winnetwk.h header defines WNetGetResourceInformation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).