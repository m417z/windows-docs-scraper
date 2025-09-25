# PFN_WSK_GET_NAME_INFO callback function

## Description

The
**WskGetNameInfo** function provides protocol-independent translation from a transport address to a host
name.

## Parameters

### `Client` [in]

[in] A pointer to a
[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client) structure that was returned through
the
*WskProviderNpi* parameter of the
[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi) function.

### `SockAddr` [in]

[in] A pointer to a
[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr) structure that contains the IP address
and port number of the socket.

### `SockAddrLength` [in]

[in] Specifies the length, in bytes, of the buffer pointed to by the
*SockAddr* parameter. The value of
*SockAddrLength* should not exceed the size of the
[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh) structure.

### `NodeName` [out, optional]

[out] An optional pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a
Unicode string that represents a host (node) name. On success, the Unicode host name is written as a
Fully Qualified Domain Name (FQDN) by default. The caller must provide a UNICODE_STRING buffer large
enough to hold the Unicode host name, which includes the terminating NULL character. If the
*NodeBuffer* parameter is **NULL**, the caller does not want to receive a host name string.
*NodeBuffer* and
*ServiceBuffer* must not both be **NULL**.

### `ServiceName` [out, optional]

[out] An optional pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a
Unicode string that represents a service name associated with the port number. The caller must provide a
UNICODE_STRING buffer large enough to hold the Unicode service name, which includes the terminating NULL
character. If the
*NodeBuffer* parameter is **NULL**, the caller does not want to receive a service name string.
*NodeBuffer* and
*ServiceBuffer* must not both be **NULL**.

### `Flags` [in]

[in] A ULONG value that is used to customize the processing of this function.

The following flags are available:

#### NI_DGRAM

Indicates that the service is a datagram service. This flag is necessary for the few services
that provide different port numbers for UDP and TCP service.

#### NI_NAMEREQD

Indicates that a host name that cannot be resolved by DNS results in an error.

#### NI_NOFQDN

Results in a local host having only its Relative Distinguished Name (RDN) returned in the
*NodeName* parameter.

#### NI_NUMERICHOST

Indicates that the function returns the numeric form of the host name instead of its name, a
reverse DNS lookup. The numeric form of the host name is also returned if the host name cannot be
resolved by DNS.

#### NI_NUMERICSERV

Indicates that the function returns the port number of the service instead of its name. Also, if
a host name is not found for an IP address (127.0.0.2, for example), the host name is returned as the
IP address.

### `OwningProcess` [in, optional]

[in] An optional pointer to the process from which the function retrieves the security context.
This security context indicates the user account context in which the function processes the name
resolution request.

If this parameter is **NULL**, the function processes the name resolution request in the context of a
predefined local account with minimal privileges.

If this parameter is not **NULL** and an impersonation token is in effect for the calling thread, this
function fails and returns STATUS_INVALID_PARAMETER.

### `OwningThread` [in, optional]

[in] An optional pointer to the thread from which the function retrieves the security context.
This parameter can be non-**NULL** only if
*OwningProcess* is non-**NULL**. Otherwise, this function fails and returns STATUS_INVALID_PARAMETER.

If this parameter is not **NULL** and an impersonation token is in effect for the calling thread, this
function fails and returns STATUS_INVALID_PARAMETER.

### `Irp` [in, out]

[in/out] A pointer to an I/O request packet (IRP) to use to complete the request asynchronously.
Upon completion of the request,
*Irp* ->
**Iostatus.Information** will hold the returned status code.

## Return value

**WskGetNameInfo** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_NO_MATCH** | The host name cannot be resolved. |
| **STATUS_SUCCESS** | The function completed successfully. If the WSK application specified a pointer to an IRP in the *Irp* parameter, the IRP will be completed with a success status. |
| **STATUS_PENDING** | The WSK subsystem could not complete the function immediately. The WSK subsystem will complete the IRP after it has completed the control operation. The status of the control operation will be returned in the **IoStatus.Status** field of the IRP. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

The process to which the
*OwningProcess* parameter points, or the thread to which the
*OwningThread* process points, indicates the security context for this function. The user account
that is indicated by the security context indicates the context for the function's name resolution
request.

## See also

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client)

[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi)

[WskGetAddressInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_address_info)