# MultinetGetConnectionPerformanceW function

## Description

The
**MultinetGetConnectionPerformance** function returns information about the expected performance of a connection used to access a network resource.

## Parameters

### `lpNetResource` [in]

A pointer to a
[NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew) structure that specifies the network resource. The following members have specific meanings in this context.

| Member | Meaning |
| --- | --- |
| ****lpLocalName**** | A pointer to a buffer that specifies a local device, such as "F:" or "LPT1", that is redirected to a network resource to be queried. <br><br>If this member is **NULL** or an empty string, the network resource is specified in the *lpRemoteName* member. If this flag specifies a local device, *lpRemoteName* is ignored. |
| ****lpRemoteName**** | A pointer to a network resource to query. The resource must currently have an established connection. For example, if the resource is a file on a file server, then having the file open will ensure the connection. |
| ****lpProvider**** | Usually set to **NULL**, but can be a pointer to the owner (provider) of the resource if the network on which the resource resides is known. <br><br>If the *lpProvider* member is not **NULL**, the system attempts to return information only about the named network. |

### `lpNetConnectInfoStruct` [out]

A pointer to the
[NETCONNECTINFOSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netconnectinfostruct) structure that receives the data.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_SUPPORTED** | The network resource does not supply this information. |
| **ERROR_NOT_CONNECTED** | The **lpLocalName** member of the [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew) structure pointed to by the *lpNetResource* parameter does not specify a redirected device, or the *lpRemoteName* member does not specify the name of a resource that is currently connected. |
| **ERROR_NO_NET_OR_BAD_PATH** | The operation could not be completed, either because a network component is not started, or because the specified resource name is not recognized. |
| **ERROR_BAD_DEVICE** | The local device specified by the *lpLocalName* member is invalid. |
| **ERROR_BAD_NET_NAME** | The network name cannot be found. This error is returned if the **lpLocalName** member of the [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew) structure pointed to by the *lpNetResource* parameter was **NULL** and the **lpRemoteName** member of the **NETRESOURCE** structure pointed to by the *lpNetResource* was also or **NULL** or could not recognized by any network. |
| **ERROR_INVALID_ADDRESS** | An attempt to access an invalid address. This error is returned if the *lpNetResource* or *lpNetConnectInfoStruct* parameters were **NULL**. |
| **ERROR_INVALID_PARAMETER** | A bad parameter was passed. This error is returned if the *lpNetConnectInfoStruct* parameter does not point to a [NETCONNECTINFOSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netconnectinfostruct) structure in which the **cbStructure** member is filled with the proper structure size. |
| **ERROR_NO_NETWORK** | The network is unavailable. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. To obtain a description of the error, call [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora). |

## Remarks

The **MultinetGetConnectionPerformance** function returns the information in a
[NETCONNECTINFOSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netconnectinfostruct) structure.

The information returned by the
**MultinetGetConnectionPerformance** function is an estimate only. Network traffic and routing can affect the accuracy of the results returned.

Note that the
**MultinetGetConnectionPerformance** function can be used only to request information for a local device that is redirected to a network resource, or for a network resource to which there is currently a connection.

If a UNC path is specified in the **lpRemoteName** member of the [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew) structure pointed to by the *lpNetResource* parameter, the **lpRemoteName** member must be a directory name, not a filename.

A typical way to use this function would be to open a file on a network server (which would ensure that there is a connection to the file), call this function, and use the results to make decisions about how to manage file I/O. For example, you can decide whether to read the entire file into a temporary file on the client or directly access the file on the server.

> [!NOTE]
> The winnetwk.h header defines MultinetGetConnectionPerformance as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NETCONNECTINFOSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netconnectinfostruct)

[NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)