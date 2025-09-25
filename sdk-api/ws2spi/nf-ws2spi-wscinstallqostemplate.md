# WSCInstallQOSTemplate function

## Description

[ This function is not supported in Windows Vista and subsequent versions of the operating system.]

The
**WSCInstallQOSTemplate** function installs the specified QoS template in the system configuration database.

## Parameters

### `Guid` [in]

The globally unique identifier (GUID) for the quality of service (QoS) provider.

### `QosName` [in]

A pointer to a [WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structure that contains the QoS name of the template to install.

### `Qos` [in]

A pointer to a [QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure that specifies the quality of service flow specifications and any provider-specific information for the QoS template.

## Return value

If
**WSCInstallQOSTemplate** function succeeds, the return value is zero. Otherwise, it returns one of the following error codes.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments is not in a valid part of the user address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more of the arguments are invalid. This error is returned if the QoS provider specified in the *Guid* parameter is invalid or the QoS template name specified in the *QosName* parameter is invalid. This error is also returned if the contents of the template structure specified in the *Qos* parameter is invalid or incomplete. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Memory cannot be allocated for buffers. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred. This error is returned under several conditions including the following: the provider is already installed, the user lacks the administrative privileges required to write to the Winsock registry, or a failure occurred when creating or installing a catalog entry. |
| **[WSASYSCALLFAILURE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A system call that should never fail has failed. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient memory was available. This error is returned when there is insufficient memory to allocate a new catalog entry. |

## Remarks

The **WSCInstallQOSTemplate** function is not supported on Windows Vista and later. If this function is called on Windows Vista, and error is returned.

The **WSCInstallQOSTemplate** function installs a QoS template, based on a QoS name. The caller of the **WSCInstallQOSTemplate** function must have appropriate administrative rights for the call to succeed.

The [QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure that contains the QoS settings can later be retrieved by calling the [WSPGetQOSByName](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpwspgetqosbyname) function and passing in the associated QoS name.

The
**WSCInstallQOSTemplate** function installs a named QoS template that contains the
[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure specified in the *Qos* parameter. If a QoS template already exists with the QoS name specified in the *Qosname* parameter, the settings specified in the *Qos* parameter replace the settings of the existing template.

If the *Guid* parameter is set to **NULL**, the installed QOS template applies to all service providers. If the *Guid* parameter is not **NULL**, then the installed QoS template applies only to the provider indicated by the *Guid* parameter.

QoS template settings are stored in nonvolatile storage, so subsequent calls to
the [WSAGetQOSByName](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetqosbyname) function with the same QoS name specified in the *lpQOSName* parameter, return the
same **QOS** structure passed to the **WSCInstallQOSTemplate** function .

Windows Sockets 2 includes a base set of QoS templates. You can override and replace any of these QoS templates or change an existing QoS template by simply installing a new template with the existing name. You do not need to delete an existing template before replacing or modifying it. You cannot delete the base set of QoS-named templates included in Windows Sockets 2. However, you can delete templates added subsequently, perhaps by other service providers.

The *Qos* parameter points to a
**QOS** structure that can include a
buffer that contains provider-specific settings in the **ProviderSpecific** member of the **QOS** structure. Any provider-specific settings are stored with the basic
**QOS** structure and are returned in subsequent
calls to the **WSAGetQOSByName** function.

The **ProviderSpecific** member of the **QOS** structure can be set even if the *Guid* parameter is set to **NULL** to install a global QoS template for all service providers. Note that this practice may lead a service provider to ignore the **ProviderSpecific** member of the **QOS** structure if the service provider does not recognize its contents. The recommended use of
**WSCInstallQOSTemplate** function is to include provider-specific settings in the **ProviderSpecific** member of the **QOS** structure only if the named template is being installed on a particular service provider (the *Guid* parameter is not **NULL**).

## See also

[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos)

[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf)

[WSPGetQOSByName](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpwspgetqosbyname)