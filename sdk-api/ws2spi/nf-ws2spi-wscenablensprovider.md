# WSCEnableNSProvider function

## Description

The
**WSCEnableNSProvider** function changes the state of a given namespace provider. It is intended to give the end-user the ability to change the state of the namespace providers.

## Parameters

### `lpProviderId` [in]

A pointer to a globally unique identifier (GUID) for the namespace provider.

### `fEnable` [in]

A Boolean value that, if **TRUE**, the provider is set to the active state. If **FALSE**, the provider is disabled and will not be available for query operations or service registration.

## Return value

If no error occurs, the
**WSCEnableNSProvider** function returns **NO_ERROR** (zero). Otherwise, it returns **SOCKET_ERROR** if the function fails, and you must retrieve the appropriate error code using the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpProviderId* parameter points to memory that is not in a valid part of the user address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified namespace provider identifier is invalid. |
| **[WSASYSCALLFAILURE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A system call that should never fail has failed. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient memory was available. This error is returned when there is insufficient memory to allocate a new catalog entry. |

## Remarks

The
**WSCEnableNSProvider** function is intended to be used to change the state of the namespace providers. An independent software vendor (ISV) should not normally de-activate another ISV namespace provider in order to activate its own. The choice should be left to the user.

The **WSCEnableNSProvider** function does not affect applications that are already running. Newly installed namespace providers will not be visible to applications nor will the changes in a namespace provider's activation state be visible. Applications launched after the call to
**WSCEnableNSProvider** will see the changes.

The **WSCEnableNSProvider** function can only be called by a user logged on as a member of the Administrators group. If **WSCEnableNSProvider** is called by a user that is not a member of the Administrators group, the function call will fail.

For computers running Windows Vista or Windows Server 2008, this function can also fail because of user account control (UAC). If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to **requireAdministrator**. If the application on Windows Vista or Windows Server 2008 lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

## See also

[WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols)

[WSCInstallNameSpace](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace)

[WSCUnInstallNameSpace](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscuninstallnamespace)

[WSCWriteNameSpaceOrder](https://learn.microsoft.com/windows/desktop/api/sporder/nf-sporder-wscwritenamespaceorder)