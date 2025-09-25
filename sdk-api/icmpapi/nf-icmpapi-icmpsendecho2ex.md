# IcmpSendEcho2Ex function

## Description

The
**IcmpSendEcho2Ex** function sends an IPv4 ICMP echo request and returns either immediately (if *Event* or *ApcRoutine* is non-**NULL**) or returns after the specified time-out. The *ReplyBuffer* contains the ICMP responses, if any.

## Parameters

### `IcmpHandle` [in]

An open handle returned by the [ICMPCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile) function.

### `Event` [in, optional]

An event to be signaled whenever an ICMP response arrives. If this parameter is specified, it requires a handle to a valid event object. Use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) or [CreateEventEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventexa) function to create this event object.

For more information on using events, see [Event Objects](https://learn.microsoft.com/windows/desktop/Sync/event-objects).

### `ApcRoutine` [in, optional]

The routine that is called when the calling thread is in an alertable thread and an ICMP reply arrives. **PIO_APC_ROUTINE_DEFINED** must be defined to force the datatype for this parameter to **PIO_APC_ROUTINE** rather than **FARPROC**.

### `ApcContext` [in, optional]

An optional parameter passed to the callback routine specified in the *ApcRoutine* parameter whenever an ICMP response arrives or an error occurs.

### `SourceAddress` [in]

The IPv4 source address on which to issue the echo request. This address is in the form of an [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr) structure.

### `DestinationAddress` [in]

The IPv4 destination address for the echo request. This address is in the form of an [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr) structure.

### `RequestData` [in]

A pointer to a buffer that contains data to send in the request.

### `RequestSize` [in]

The size, in bytes, of the request data buffer pointed to by the *RequestData* parameter.

### `RequestOptions` [in, optional]

A pointer to the IP header options for the request, in the form of an [IP_OPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information) structure. On a 64-bit platform, this parameter is in the form for an [IP_OPTION_INFORMATION32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information32) structure.

This parameter may be **NULL** if no IP header options need to be specified.

### `ReplyBuffer` [out]

A pointer to a buffer to hold any replies to the request. Upon return, the buffer contains an array of
[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply) structures followed by options and data. The buffer must be large enough to hold at least one
**ICMP_ECHO_REPLY** structure plus *RequestSize* bytes of data.

This buffer should also be large enough to also hold 8 more bytes of data (the size of an ICMP error message) plus space for an **IO_STATUS_BLOCK** structure.

### `ReplySize` [in]

The allocated size, in bytes, of the reply buffer. The buffer should be large enough to hold at least one
[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply) structure plus *RequestSize* bytes of data.

This buffer should also be large enough to also hold 8 more bytes of data (the size of an ICMP error message) plus space for an **IO_STATUS_BLOCK** structure.

### `Timeout` [in]

The time, in milliseconds, to wait for replies.

## Return value

When called synchronously, the **IcmpSendEcho2Ex** function returns the number of replies received and stored in *ReplyBuffer*. If the return value is zero, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

When called asynchronously, the **IcmpSendEcho2Ex** function returns ERROR_IO_PENDING to indicate the operation is in progress. The results can be retrieved later when the event specified in the *Event* parameter signals or the callback function in the *ApcRoutine* parameter is called.

If the return value is zero, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

If the function fails, the extended error code returned by [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *IcmpHandle* parameter contains an invalid handle. This error can also be returned if the *ReplySize* parameter specifies a value less than the size of an [ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply) structure. |
| **ERROR_IO_PENDING** | The operation is in progress. This value is returned by a successful asynchronous call to [IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex) and is not an indication of an error. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to complete the operation. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer. |
| **IP_BUF_TOO_SMALL** | The size of the *ReplyBuffer* specified in the *ReplySize* parameter was too small. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **IcmpSendEcho2Ex** function is available on Windows Server 2008 and later.

The **IcmpSendEcho2Ex** function is an enhanced version of the [IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2) function that allows the user to specify the IPv4 source address on which to issue the ICMP request. The **IcmpSendEcho2Ex** function is useful in cases where a computer has multiple network interfaces.

The **IcmpSendEcho2Ex** function is called synchronously if the *ApcRoutine* or *Event* parameters are **NULL**. When called synchronously, the return value contains the number of replies received and stored in *ReplyBuffer* after waiting for the time specified in the *Timeout* parameter. If the return value is zero, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

The **IcmpSendEcho2Ex** function is called asynchronously when either the *ApcRoutine* or *Event* parameters are specified. When called asynchronously, the *ReplyBuffer* and *ReplySize* parameters are required to accept the response. ICMP response data is copied to the *ReplyBuffer* provided and the application is signaled (when the *Event* parameter is specified) or the callback function is called (when the *ApcRoutine* parameter is specified). The application must parse the data pointed to by *ReplyBuffer* parameter using the [IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies) function.

If the *Event* parameter is specified, the **IcmpSendEcho2Ex** function is called asynchronously. The event specified in the *Event* parameter is signaled whenever an ICMP response arrives. Use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function to create this event object.

If the *ApcRoutine* parameter is specified, the **IcmpSendEcho2Ex** function is called asynchronously. The *ApcRoutine* parameter should point to a user-defined callback function. The callback function specified in the *ApcRoutine* parameter is called whenever an ICMP response arrives. The invocation of the callback function specified in the *ApcRoutine* parameter is serialized.

If both the *Event* and *ApcRoutine* parameters are specified, the event specified in the *Event* parameter is signaled whenever an ICMP response arrives, but the callback function specified in the *ApcRoutine* parameter is ignored .

Any application that calls the **IcmpSendEcho2Ex** function asynchronously using the *ApcRoutine* parameter must define **PIO_APC_ROUTINE_DEFINED** to force the datatype for the *ApcRoutine* parameter to **PIO_APC_ROUTINE** rather than **FARPROC**.

**Note** **PIO_APC_ROUTINE_DEFINED** must be defined before the *Icmpapi.h* header file is included.

The callback function pointed to by the *ApcRoutine* must be defined as a function of type **VOID** with the following syntax:

``` syntax
typedef
VOID WINAPI
(*PIO_APC_ROUTINE) (
    IN PVOID ApcContext,
    IN PIO_STATUS_BLOCK IoStatusBlock,
    IN ULONG Reserved
    );
```

The parameters passed to the callback function include the following:

| Parameter | Description |
| --- | --- |
| IN PVOID ApcContext | The *ApcContext* parameter passed to the **IcmpSendEcho2Ex** function. This parameter can be used by the application to identify the **IcmpSendEcho2Ex** request that the callback function is responding to. |
| IN PIO_STATUS_BLOCK IoStatusBlock | A pointer to a **IO_STATUS_BLOCK**. This variable contains the final completion status and information about the operation. The number of bytes actually received in the reply is returned in the **Information** member of the **IO_STATUS_BLOCK** struct.<br><br>The **IO_STATUS_BLOCK** structure is defined in the *Wdm.h* header file. |
| IN ULONG Reserved | This parameter is reserved. |

The callback function specified in the *ApcRoutine* parameter must be implemented in the same process as the application calling the **IcmpSendEcho2Ex** function. If the callback function is in a separate DLL, then the DLL should be loaded before calling the **IcmpSendEcho2Ex** function.

For IPv6, use the [Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile), [Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2), and [Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies) functions.

Note that the include directive for *Iphlpapi.h* header file must be placed before the *Icmpapi.h* header file.

## See also

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[CreateEventEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventexa)

[Event Objects](https://learn.microsoft.com/windows/desktop/Sync/event-objects)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[ICMPCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile)

[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply)

[IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr)

[IP_OPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information)

[IP_OPTION_INFORMATION32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information32)

[Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile)

[Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies)

[Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2)

[IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies)

[IcmpSendEcho](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho)

[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2)