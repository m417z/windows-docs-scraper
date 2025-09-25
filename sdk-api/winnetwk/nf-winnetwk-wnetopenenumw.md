# WNetOpenEnumW function

## Description

The
**WNetOpenEnum** function starts an enumeration of network resources or existing connections. You can continue the enumeration by calling the
[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea) function.

## Parameters

### `dwScope` [in]

Scope of the enumeration. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RESOURCE_CONNECTED** | Enumerate all currently connected resources. The function ignores the *dwUsage* parameter. For more information, see the following Remarks section. |
| **RESOURCE_CONTEXT** | Enumerate only resources in the network context of the caller. Specify this value for a Network Neighborhood view. The function ignores the *dwUsage* parameter. |
| **RESOURCE_GLOBALNET** | Enumerate all resources on the network. |
| **RESOURCE_REMEMBERED** | Enumerate all remembered (persistent) connections. The function ignores the *dwUsage* parameter. |

### `dwType` [in]

Resource types to be enumerated. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **RESOURCETYPE_ANY** | All resources. This value cannot be combined with RESOURCETYPE_DISK or RESOURCETYPE_PRINT. |
| **RESOURCETYPE_DISK** | All disk resources. |
| **RESOURCETYPE_PRINT** | All print resources. |

If a network provider cannot distinguish between print and disk resources, it can enumerate all resources.

### `dwUsage` [in]

Resource usage type to be enumerated. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **0** | All resources. |
| **RESOURCEUSAGE_CONNECTABLE** | All connectable resources. |
| **RESOURCEUSAGE_CONTAINER** | All container resources. |
| **RESOURCEUSAGE_ATTACHED** | Setting this value forces **WNetOpenEnum** to fail if the user is not authenticated. The function fails even if the network allows enumeration without authentication. |
| **RESOURCEUSAGE_ALL** | Setting this value is equivalent to setting RESOURCEUSAGE_CONNECTABLE, RESOURCEUSAGE_CONTAINER, and RESOURCEUSAGE_ATTACHED. |

This parameter is ignored unless the *dwScope* parameter is equal to RESOURCE_GLOBALNET. For more information, see the following Remarks section.

### `lpNetResource` [in]

Pointer to a
[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcew) structure that specifies the container to enumerate. If the *dwScope* parameter is not RESOURCE_GLOBALNET, this parameter must be **NULL**.

If this parameter is **NULL**, the root of the network is assumed. (The system organizes a network as a hierarchy; the root is the topmost container in the network.)

If this parameter is not **NULL**, it must point to a
**NETRESOURCE** structure. This structure can be filled in by the application or it can be returned by a call to the
[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea) function. The
**NETRESOURCE** structure must specify a container resource; that is, the RESOURCEUSAGE_CONTAINER value must be specified in the *dwUsage* parameter.

To enumerate all network resources, an application can begin the enumeration by calling
**WNetOpenEnum** with the *lpNetResource* parameter set to **NULL**, and then use the returned handle to call
**WNetEnumResource** to enumerate resources. If one of the resources in the
**NETRESOURCE** array returned by the
**WNetEnumResource** function is a container resource, you can call
**WNetOpenEnum** to open the resource for further enumeration.

### `lphEnum` [out]

Pointer to an enumeration handle that can be used in a subsequent call to
[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_CONTAINER** | The *lpNetResource* parameter does not point to a container. |
| **ERROR_INVALID_PARAMETER** | Either the *dwScope* or the *dwType* parameter is invalid, or there is an invalid combination of parameters. |
| **ERROR_NO_NETWORK** | The network is unavailable. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. To obtain a description of the error, call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function. |
| **ERROR_INVALID_ADDRESS** | A remote network resource name supplied in the **NETRESOURCE** structure resolved to an invalid network address. |

## Remarks

If the *dwScope* parameter is equal to RESOURCE_CONNECTED, a network connection made using the Microsoft LAN Manager network is omitted from the enumeration if the connection was made by an application running in a different logon session than the application calling the
**WNetOpenEnum** function. This is because connections made using Microsoft LAN Manager are visible only to applications running in the same logon session as the application that made the connection. (To include the connection in the enumeration, it is not sufficient for the application to be running in the user account that created the connection.)

The exact interpretation of RESOURCE_CONTEXT in the *dwScope* parameter depends on the networks installed on the machine.

The
**WNetOpenEnum** function is used to begin enumeration of the resources in a single container. The following examples show the hierarchical structure of a Microsoft LAN Manager network and a Novell NetWare network and identify the containers.

``` syntax
LanMan (container, in this case the provider)
  ACCOUNTING (container, in this case the domain)
    \\ACCTSPAY (container, in this case the server)
      PAYFILES (disk)
      LASERJET (print)

NetWare (container, in this case the provider)
  MARKETING (container, in this case the server)
    SYS (disk, first one on any NetWare server)
    ANOTHERVOLUME (disk)
    LASERJET (print)

```

#### Examples

For a code sample that illustrates an application-defined function that enumerates all the resources on a network, see
[Enumerating Network Resources](https://learn.microsoft.com/windows/desktop/WNet/enumerating-network-resources).

> [!NOTE]
> The winnetwk.h header defines WNetOpenEnum as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcew)

[WNetCloseEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcloseenum)

[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)