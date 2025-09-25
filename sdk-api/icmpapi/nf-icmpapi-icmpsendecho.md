# IcmpSendEcho function

## Description

The
**IcmpSendEcho** function sends an IPv4 ICMP echo request and returns any echo response replies. The call returns when the time-out has expired or the reply buffer is filled.

## Parameters

### `IcmpHandle` [in]

The open handle returned by the [IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile) function.

### `DestinationAddress` [in]

The IPv4 destination address of the echo request, in the form of an [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr) structure.

### `RequestData` [in]

A pointer to a buffer that contains data to send in the request.

### `RequestSize` [in]

The size, in bytes, of the request data buffer pointed to by the *RequestData* parameter.

### `RequestOptions` [in, optional]

A pointer to the IP header options for the request, in the form of an [IP_OPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information) structure. On a 64-bit platform, this parameter is in the form for an [IP_OPTION_INFORMATION32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information32) structure.

This parameter may be **NULL** if no IP header options need to be specified.

### `ReplyBuffer` [out]

A buffer to hold any replies to the echo request. Upon return, the buffer contains an array of
[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply) structures followed by the options and data for the replies. The buffer should be large enough to hold at least one
**ICMP_ECHO_REPLY** structure plus *RequestSize* bytes of data.

### `ReplySize` [in]

The allocated size, in bytes, of the reply buffer. The buffer should be large enough to hold at least one
[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply) structure plus *RequestSize* bytes of data.

This buffer should also be large enough to also hold 8 more bytes of data (the size of an ICMP error message).

### `Timeout` [in]

The time, in milliseconds, to wait for replies.

## Return value

The
**IcmpSendEcho** function returns the number of
[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply) structures stored in the *ReplyBuffer*. The status of each reply is contained in the structure. If the return value is zero, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for additional error information.

If the function fails, the extended error code returned by [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The data area passed to a system call is too small. This error is returned if the *ReplySize* parameter indicates that the buffer pointed to by the *ReplyBuffer* parameter is too small. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *IcmpHandle* parameter contains an invalid handle. This error can also be returned if the *ReplySize* parameter specifies a value less than the size of an [ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply) structure. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to complete the operation. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer. |
| **IP_BUF_TOO_SMALL** | The size of the *ReplyBuffer* specified in the *ReplySize* parameter was too small. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **IcmpSendEcho** function send an ICMP echo request to the specified address and returns the number of replies received and stored in *ReplyBuffer*. The **IcmpSendEcho** function is a synchronous function and returns after waiting for the time specified in the *Timeout* parameter for a response. If the return value is zero, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

The [IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2) and [IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex) functions are enhanced version of **IcmpSendEcho** that support asynchronous operation. The **IcmpSendEcho2Ex** function also allows the source IP address to be specified. This feature is useful on computers with multiple network interfaces.

For IPv6, use the [Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile), [Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2), and [Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies) functions.

The **IcmpSendEcho** function is exported from the *Icmp.dll* on Windows 2000. The **IcmpSendEcho** function is exported from the *Iphlpapi.dll* on Windows XP and later. Windows version checking is not recommended to use this function. Applications requiring portability with this function across Windows 2000, Windows XP, Windows Server 2003 and later Windows versions should not statically link to either the *Icmp.lib* or the *Iphlpapi.lib* file. Instead, the application should check for the presence of **IcmpSendEcho** in the *Iphlpapi.dll* with calls to [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Failing that, the application should check for the presence of **IcmpSendEcho** in the *Icmp.dll* with calls to **LoadLibrary** and **GetProcAddress**.

Note that the include directive for *Iphlpapi.h* header file must be placed before the *Icmpapi.h* header file.

#### Examples

The following example sends an ICMP echo request to the IP address specified on the command line and prints the information received from the first response.

```cpp
#include <winsock2.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#include <stdio.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

int __cdecl main(int argc, char **argv)  {

    // Declare and initialize variables

    HANDLE hIcmpFile;
    unsigned long ipaddr = INADDR_NONE;
    DWORD dwRetVal = 0;
    char SendData[32] = "Data Buffer";
    LPVOID ReplyBuffer = NULL;
    DWORD ReplySize = 0;

    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s IP address\n", argv[0]);
        return 1;
    }

    ipaddr = inet_addr(argv[1]);
    if (ipaddr == INADDR_NONE) {
        printf("usage: %s IP address\n", argv[0]);
        return 1;
    }

    hIcmpFile = IcmpCreateFile();
    if (hIcmpFile == INVALID_HANDLE_VALUE) {
        printf("\tUnable to open handle.\n");
        printf("IcmpCreatefile returned error: %ld\n", GetLastError() );
        return 1;
    }

    ReplySize = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
    ReplyBuffer = (VOID*) malloc(ReplySize);
    if (ReplyBuffer == NULL) {
        printf("\tUnable to allocate memory\n");
        return 1;
    }

    dwRetVal = IcmpSendEcho(hIcmpFile, ipaddr, SendData, sizeof(SendData),
        NULL, ReplyBuffer, ReplySize, 1000);
    if (dwRetVal != 0) {
        PICMP_ECHO_REPLY pEchoReply = (PICMP_ECHO_REPLY)ReplyBuffer;
        struct in_addr ReplyAddr;
        ReplyAddr.S_un.S_addr = pEchoReply->Address;
        printf("\tSent icmp message to %s\n", argv[1]);
        if (dwRetVal > 1) {
            printf("\tReceived %ld icmp message responses\n", dwRetVal);
            printf("\tInformation from the first response:\n");
        }
        else {
            printf("\tReceived %ld icmp message response\n", dwRetVal);
            printf("\tInformation from this response:\n");
        }
        printf("\t  Received from %s\n", inet_ntoa( ReplyAddr ) );
        printf("\t  Status = %ld\n",
            pEchoReply->Status);
        printf("\t  Roundtrip time = %ld milliseconds\n",
            pEchoReply->RoundTripTime);
    }
    else {
        printf("\tCall to IcmpSendEcho failed.\n");
        printf("\tIcmpSendEcho returned error: %ld\n", GetLastError() );
        return 1;
    }
    return 0;
}

```

## See also

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply)

[IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr)

[IP_OPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information)

[IP_OPTION_INFORMATION32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information32)

[Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile)

[Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies)

[Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2)

[IcmpCloseHandle](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpclosehandle)

[IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile)

[IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies)

[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2)

[IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex)