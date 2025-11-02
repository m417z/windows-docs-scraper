## Description

The **Icmp6SendEcho2** function sends an IPv6 ICMPv6 echo request and returns either immediately (if *Event* or *ApcRoutine* is non-**NULL**) or returns after the specified time-out. The *ReplyBuffer* contains the IPv6 ICMPv6 echo response, if any.

## Parameters

### `IcmpHandle` [in]

The open handle returned by [Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile).

### `Event` [in, optional]

An event to be signaled whenever an ICMPv6 response arrives. If this parameter is specified, it requires a handle to a valid event object. Use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) or [CreateEventEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventexa) function to create this event object.

For more information on using events, see [Event Objects](https://learn.microsoft.com/windows/desktop/Sync/event-objects).

### `ApcRoutine` [in, optional]

The routine that is called when the calling thread is in an alertable thread and an ICMPv6 reply arrives. On Windows Vista and later, **PIO_APC_ROUTINE_DEFINED** must be defined to force the datatype for this parameter to **PIO_APC_ROUTINE** rather than **FARPROC**.

On Windows Server 2003 and Windows XP,
**PIO_APC_ROUTINE_DEFINED** must not be defined to force the datatype for this parameter to **FARPROC**.

### `ApcContext` [in, optional]

An optional parameter passed to the callback routine specified in the *ApcRoutine* parameter whenever an ICMPv6 response arrives or an error occurs.

### `SourceAddress` [in]

The IPv6 source address on which to issue the echo request, in the form of a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

### `DestinationAddress` [in]

The IPv6 destination address of the echo request, in the form of a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

### `RequestData` [in]

A pointer to a buffer that contains data to send in the request.

### `RequestSize` [in]

The size, in bytes, of the request data buffer pointed to by the *RequestData* parameter.

### `RequestOptions` [in, optional]

A pointer to the IPv6 header options for the request, in the form of an [IP_OPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information) structure. On a 64-bit platform, this parameter is in the form for an [IP_OPTION_INFORMATION32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information32) structure.

This parameter may be NULL if no IP header options need to be specified.

**Note** On Windows Server 2003 and Windows XP, the *RequestOptions* parameter is not optional and must not be NULL and only the **Ttl** and **Flags** members are used.

### `ReplyBuffer` [out]

A pointer to a buffer to hold replies to the request. Upon return, the buffer contains an [ICMPV6_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmpv6_echo_reply_lh) structure followed by the message body from the ICMPv6 echo response reply data. The buffer must be large enough to hold at least one
**ICMPV6_ECHO_REPLY** structure plus the number of bytes of data specified in the *RequestSize* parameter. This buffer should also be large enough to also hold 8 more bytes of data (the size of an ICMP error message) plus space for an **IO_STATUS_BLOCK** structure.

### `ReplySize` [in]

The size, in bytes, of the reply buffer pointed to by the *ReplyBuffer* parameter. This buffer should be large enough to hold at least one
[ICMPV6_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmpv6_echo_reply_lh) structure plus *RequestSize* bytes of data. This buffer should also be large enough to also hold 8 more bytes of data (the size of an ICMP error message) plus space for an **IO_STATUS_BLOCK** structure.

### `Timeout` [in]

The time, in milliseconds, to wait for replies. This parameter is only used if the **Icmp6SendEcho2** function is called synchronously. So this parameter is not used if either the *ApcRoutine* or *Event* parameter are not **NULL**.

## Return value

When called synchronously, returns the number of replies that are received and stored in *ReplyBuffer*.

When called asynchronously, indicates that the operation is in progress by returning **ERROR_IO_PENDING**. You can retrieve the number-of-replies result later, when the event specified in the *Event* parameter signals, or when the callback function in the *ApcRoutine* parameter is called.

If the (synchronous or asynchronous) number-of-replies value is zero, then for extended error information call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the function fails, then the extended error code returned by [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_CALL_NOT_IMPLEMENTED** | This function is not supported on this system. |
| **ERROR_INSUFFICIENT_BUFFER** | The data area passed to a system call is too small. This error is returned if the *ReplySize* parameter indicates that the buffer pointed to by the *ReplyBuffer* parameter is too small. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. This error is returned if the *IcmpHandle* parameter contains an invalid handle. |
| **ERROR_IO_PENDING** | The operation is in progress. This value is returned by a successful asynchronous call to [Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2) and is not an indication of an error. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to process this command. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv6 stack is on the local computer. |
| **IP_BUF_TOO_SMALL** | The size of the *ReplyBuffer* specified in the *ReplySize* parameter was too small. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **Icmp6SendEcho2** function is called synchronously if the *ApcRoutine* and *Event* parameters are **NULL**. When called synchronously, the return value contains the number of replies received and stored in *ReplyBuffer* after waiting for the time specified in the *Timeout* parameter. If the return value is zero, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

The **Icmp6SendEcho2** function is called asynchronously when either the *ApcRoutine* or *Event* parameters are specified. When called asynchronously, the *ReplyBuffer* and *ReplySize* parameters are required to accept the response. ICMP response data is copied to the *ReplyBuffer* provided and the application is signaled (when the *Event* parameter is specified) or the callback function is called (when the *ApcRoutine* parameter is specified). The application must parse the data pointed to by *ReplyBuffer* parameter using the [Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies) function.

If the *Event* parameter is specified, the **Icmp6SendEcho2** function is called asynchronously. The event specified in the *Event* parameter is signaled whenever an ICMPv6 response arrives. Use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function to create this event object.

If the *ApcRoutine* parameter is specified, the **Icmp6SendEcho2** function is called asynchronously. The *ApcRoutine* parameter should point to a user-defined callback function. The callback function specified in the *ApcRoutine* parameter is called whenever an ICMPv6 response arrives. The invocation of the callback function specified in the *ApcRoutine* parameter is serialized.

If both the *Event* and *ApcRoutine* parameters are specified, the event specified in the *Event* parameter is signaled whenever an ICMPv6 response arrives, but the callback function specified in the *ApcRoutine* parameter is ignored .

On Windows Vista and later, any application that calls **Icmp6SendEcho2** function asynchronously using the *ApcRoutine* parameter must define **PIO_APC_ROUTINE_DEFINED** to force the datatype for the *ApcRoutine* parameter to **PIO_APC_ROUTINE** rather than **FARPROC**.

**Note** **PIO_APC_ROUTINE_DEFINED** must be defined before the *Icmpapi.h* header file is included.

On Windows Vista and later, the callback function pointed to by the *ApcRoutine* must be defined as a function of type **VOID** with the following syntax:

``` syntax
typedef
VOID WINAPI
(*PIO_APC_ROUTINE) (
    IN PVOID ApcContext,
    IN PIO_STATUS_BLOCK IoStatusBlock,
    IN ULONG Reserved
    );
```

On Windows Vista and later, the parameters passed to the callback function include the following:

| Parameter | Description |
| --- | --- |
| IN PVOID ApcContext | The *ApcContext* parameter passed to the **Icmp6SendEcho2** function. This parameter can be used by the application to identify the **Icmp6SendEcho2** request that the callback function is responding to. |
| IN PIO_STATUS_BLOCK IoStatusBlock | A pointer to a **IO_STATUS_BLOCK**. This variable contains the final completion status and information about the operation. The number of bytes actually received in the reply is returned in the **Information** member of the **IO_STATUS_BLOCK** struct.<br><br>The **IO_STATUS_BLOCK** structure is defined in the *Wdm.h* header file. |
| IN ULONG Reserved | This parameter is reserved. |

On Windows Server 2003 and Windows XP, any application that calls the **Icmp6SendEcho2** function asynchronously using the *ApcRoutine* parameter must not define **PIO_APC_ROUTINE_DEFINED** to force the datatype for the *ApcRoutine* parameter to **FARPROC** rather than **PIO_APC_ROUTINE**.

On Windows Server 2003 and Windows XP, the callback function pointed to by the *ApcRoutine* must be defined as a function of type **VOID** with the following syntax:

``` syntax
typedef
VOID WINAPI
(*FARPROC) (
    IN PVOID ApcContext,
    );
```

On Windows Server 2003 and Windows XP, the parameters passed to the callback function include the following:

| Parameter | Description |
| --- | --- |
| IN PVOID ApcContext | The *ApcContext* parameter passed to the **Icmp6SendEcho2** function. This parameter can be used by the application to identify the **Icmp6SendEcho2** request that the callback function is responding to. |

The callback function specified in the *ApcRoutine* parameter must be implemented in the same process as the application calling the **Icmp6SendEcho2** function. If the callback function is in a separate DLL, then the DLL should be loaded before calling the **Icmp6SendEcho2** function.

For IPv4, use the [IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile), **IcmpSendEcho**, [IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2), [IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex), and [IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies) functions.

Note that the include directive for *Iphlpapi.h* header file must be placed before the *Icmpapi.h* header file.

## See also

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[CreateEventEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventexa)

[Event Objects](https://learn.microsoft.com/windows/desktop/Sync/event-objects)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[ICMPV6_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmpv6_echo_reply_lh)

[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply)

[IP_OPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information)

[Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile)

[Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies)

[IcmpCloseHandle](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpclosehandle)

[IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile)

[IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies)

[IcmpSendEcho](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho)

[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2)

[IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)