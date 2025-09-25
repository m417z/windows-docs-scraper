# inet_addr function

## Description

The
**inet_addr** function converts a string containing an IPv4 dotted-decimal address into a proper address for the
[IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure.

## Parameters

### `cp`

TBD

#### - a [in]

A **NULL**-terminated character string representing a number expressed in the Internet standard ".'' (dotted) notation.

## Return value

If no error occurs,
the **inet_addr** function returns an unsigned long value containing a suitable binary representation of the Internet address given.

If the string in the *cp* parameter does not contain a legitimate Internet address, for example if a portion of an "a.b.c.d" address exceeds 255, then
**inet_addr** returns the value **INADDR_NONE**.

On Windows Server 2003and later if the string in the *cp* parameter is an empty string, then
**inet_addr** returns the value **INADDR_NONE**. If **NULL** is passed in the *cp* parameter, then
**inet_addr** returns the value **INADDR_NONE**.

On Windows XPand earlier if the string in the *cp* parameter is an empty string, then
**inet_addr** returns the value **INADDR_ANY**. If **NULL** is passed in the *cp* parameter, then
**inet_addr** returns the value **INADDR_NONE**.

## Remarks

The
**inet_addr** function interprets the character string specified by the *cp* parameter. This string represents a numeric Internet address expressed in the Internet standard ".'' notation. The value returned is a number suitable for use as an Internet address. All Internet addresses are returned in IP's network order (bytes ordered from left to right). If you pass in " " (a space) to the
**inet_addr** function,
**inet_addr** returns zero.

On Windows Vista and later, the [RtlIpv4StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressa) function can be used to convert a string representation of an IPv4 address to a binary IPv4 address represented as an [IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure. On Windows Vista and later, the [RtlIpv6StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressa) function can be used to convert a string representation of an IPv6 address to a binary IPv6 address represented as an **IN6_ADDR** structure.

### Internet Addresses

Values specified using the ".'' notation take one of the following forms:

a.b.c.d a.b.c a.b a

When four parts are specified, each is interpreted as a byte of data and assigned, from left to right, to the 4 bytes of an Internet address. When an Internet address is viewed as a 32-bit integer quantity on the Intel architecture, the bytes referred to above appear as "d.c.b.a''. That is, the bytes on an Intel processor are ordered from right to left.

The parts that make up an address in "." notation can be decimal, octal or hexadecimal as specified in the C language. Numbers that start with "0x" or "0X" imply hexadecimal. Numbers that start with "0" imply octal. All other numbers are interpreted as decimal.

| Internet address value | Meaning |
| --- | --- |
| "4.3.2.16" | Decimal |
| "004.003.002.020" | Octal |
| "0x4.0x3.0x2.0x10" | Hexadecimal |
| "4.003.002.0x10" | Mix |

The **inet_addr** function supports the decimal, octal, hexadecimal, and mixed notations for the string passed in the *cp* parameter.

**Note** The following notations are only used by Berkeley software, and nowhere else on the Internet. For compatibility with Berkeley software, the **inet_addr** function also supports the additional notations specified below.

When a three-part address is specified, the last part is interpreted as a 16-bit quantity and placed in the right-most 2 bytes of the network address. This makes the three-part address format convenient for specifying Class B network addresses as "128.net.host''

When a two-part address is specified, the last part is interpreted as a 24-bit quantity and placed in the right-most 3 bytes of the network address. This makes the two-part address format convenient for specifying Class A network addresses as "net.host''.

When only one part is given, the value is stored directly in the network address without any byte rearrangement.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

#### Examples

The following code example shows how to use the **inet_addr** function.

```cpp
#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <stdio.h>
#include <windows.h>

// need link with Ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int __cdecl main(int argc, char **argv)
{

    //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData;
    int iResult;

    unsigned long ulAddr = INADDR_NONE;

    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s <IPv4 address>\n", argv[0]);
        printf("  inetaddr converts a string containing an\n");
        printf("  IPv4 address in one of the supported formats\n");
        printf("  to a unsigned long representing an IN_ADDR\n");
        printf("      %s 192.168.16.34\n", argv[0]);
        return 1;
    }
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

//--------------------------------
// Call inet_addr(). If the call succeeds,
// the result variable will hold a IN_ADDR
    ulAddr = inet_addr(argv[1]);
    if ( ulAddr == INADDR_NONE ) {
        printf("inet_addr failed and returned INADDR_NONE\n");
        WSACleanup();
        return 1;
    }

    if (ulAddr == INADDR_ANY) {
        printf("inet_addr failed and returned INADDR_ANY\n");
        WSACleanup();
        return 1;
    }

    printf("inet_addr returned success\n");

    // Here we could implement code to retrieve each address and
    // print out the hex bytes
    // for(i=0, ptr= (Char*) &ulAddr; i < 4; i++, ptr++) {

    WSACleanup();
    return 0;
}

```

## See also

**IN6_ADDR**

[IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)

[InetNtop](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw)

[RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa)

[RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw)

[RtlIpv4StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressa)

[RtlIpv4StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressexw)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[RtlIpv6StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressa)

[RtlIpv6StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressexw)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)