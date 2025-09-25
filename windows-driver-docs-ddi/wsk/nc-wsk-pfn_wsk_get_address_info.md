# PFN_WSK_GET_ADDRESS_INFO callback function

## Description

The
*WskGetAddressInfo* function performs protocol-independent translation from a host name to a transport
address.

## Parameters

### `Client` [in]

[in] A pointer to a
[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client) structure that was returned through
the
*WskProviderNpi* parameter of the
[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi) function.

### `NodeName` [in, optional]

[in] An optional pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a
Unicode string that represents a host (node) name or a numeric host address string. For the Internet
protocol, the numeric host address string is a dotted-decimal IPv4 address or an IPv6 hexadecimal
address.

### `ServiceName` [in, optional]

[in] An optional pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a
Unicode string that represents a service name or a port number.

### `NameSpace` [in, optional]

[in] An optional namespace identifier that specifies the namespace providers that are queried.
Only namespace providers that support the specified namespace can be queried successfully.

### `Provider` [in, optional]

[in] An optional pointer to a GUID of a specific namespace provider to be queried.

### `Hints` [in, optional]

[in] An optional pointer to an [ADDRINFOEXW](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-addrinfoexw) structure that provides hints about the type of socket
that the caller supports.

The [ADDRINFOEXW](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-addrinfoexw) structure is defined in the
Ws2def.h header. It is identical to the
[addrinfoex](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-addrinfoexw) structure.

**Important** The
Ws2def.h header file is automatically included in
Wsk.h. Do not use
Ws2def.h directly.

### `Result` [out]

[out] A pointer to a caller-allocated buffer that receives a linked list of one or more
[ADDRINFOEXW](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-addrinfoexw) structures that represent response information about the host.

**Note** The caller must call the
[WskFreeAddressInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_free_address_info) function to free
this pointer.

The [ADDRINFOEXW](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-addrinfoexw) structure is defined in the
Ws2def.h header. It is identical to the
[addrinfoex](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-addrinfoexw) structure.

**Important** The
Ws2def.h header file is automatically included in
Wsk.h. Do not use
Ws2def.h directly.

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

**WskGetAddressInfo** returns one of the following NTSTATUS codes:

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

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client)

[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi)

[WskFreeAddressInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_free_address_info)