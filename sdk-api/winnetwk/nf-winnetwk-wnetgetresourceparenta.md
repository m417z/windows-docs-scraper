# WNetGetResourceParentA function

## Description

The
**WNetGetResourceParent** function returns the parent of a network resource in the network browse hierarchy. Browsing begins at the location of the specified network resource.

Call the
[WNetGetResourceInformation](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetresourceinformationa) and
**WNetGetResourceParent** functions to move up the network hierarchy. Call the
[WNetOpenEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetopenenuma) function to move down the hierarchy.

## Parameters

### `lpNetResource` [in]

Pointer to a [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcea) structure that specifies the network resource for which the parent name is required.

Specify the members of the input
**NETRESOURCE** structure as follows. The caller typically knows the values to provide for the **lpProvider** and **dwType** members after previous calls to
**WNetGetResourceInformation** or
**WNetGetResourceParent**.

| Member | Meaning |
| --- | --- |
| ****dwType**** | This member should be filled in if known; otherwise, it should be set to **NULL**. |
| ****lpRemoteName**** | This member should specify the remote name of the network resource whose parent is required. |
| ****lpProvider**** | This member should specify the network provider that owns the resource. This member is required; otherwise, the function could produce incorrect results. |

All other members of the
**NETRESOURCE** structure are ignored.

### `lpBuffer` [out]

Pointer to a buffer to receive a single
**NETRESOURCE** structure that represents the parent resource. The function returns the **lpRemoteName**, **lpProvider**, **dwType**, **dwDisplayType**, and **dwUsage** members of the structure; all other members are set to **NULL**.

The **lpRemoteName** member points to the remote name for the parent resource. This name uses the same syntax as the one returned from an enumeration by the
[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea) function. The caller can perform a string comparison to determine whether the
**WNetGetResourceParent** resource is the same as that returned by
**WNetEnumResource**. If the input resource has no parent on any of the networks, the **lpRemoteName** member is returned as **NULL**.

The presence of the RESOURCEUSAGE_CONNECTABLE bit in the **dwUsage** member indicates that you can connect to the parent resource, but only when it is available on the network.

### `lpcbBuffer` [in, out]

Pointer to a location that, on entry, specifies the size of the *lpBuffer* buffer, in bytes. If the buffer is too small to hold the result, this location receives the required buffer size, and the function returns ERROR_MORE_DATA.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have access to the network resource. |
| **ERROR_BAD_NET_NAME** | The input **lpRemoteName** member is not an existing network resource for any network. |
| **ERROR_BAD_PROVIDER** | The input **lpProvider** member does not match any installed network provider. |
| **ERROR_MORE_DATA** | The buffer pointed to by the *lpBuffer* parameter is too small. |
| **ERROR_NOT_AUTHENTICATED** | The caller does not have the necessary permissions to obtain the name of the parent. |

## Remarks

The
**WNetGetResourceParent** function is typically used in conjunction with the
[WNetGetResourceInformation](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetresourceinformationa) function to parse and interpret a network path typed in by a user.

Unlike the
**WNetGetResourceInformation** function, if the resource includes a parent in its syntax, the
**WNetGetResourceParent** function returns the parent, whether or not the resource actually exists.
**WNetGetResourceParent** should typically be used only by applications that display network resources to the user in a hierarchical fashion. The Windows Explorer and the **File Open** dialog box are two well-known examples of this type of application. Note that no assumptions should be made about the type of resource that will be returned.

You can call the
[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea),
[WNetGetResourceInformation](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetresourceinformationa), or
**WNetGetResourceParent** function to return information from the
[NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcea) structure. You can also construct network resource information using the members of the
**NETRESOURCE** structure.

An example of an inappropriate use of
**WNetGetResourceParent** is to determine the name of the domain to which a specified server belongs. The function may happen to return the correct domain name for some networks in which domains appear directly above servers in the browse hierarchy. The function will return incorrect results for other networks.

> [!NOTE]
> The winnetwk.h header defines WNetGetResourceParent as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WNetGetNetworkInformation](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetnetworkinformationa)

[WNetGetProviderName](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetprovidernamea)

[WNetGetResourceInformation](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetresourceinformationa)

[WNetGetUniversalName](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetuniversalnamea)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)