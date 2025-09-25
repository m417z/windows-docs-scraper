# GetRTTAndHopCount function

## Description

The
**GetRTTAndHopCount** function determines the round-trip time (RTT) and hop count to the specified destination.

## Parameters

### `DestIpAddress` [in]

IP address of the destination for which to determine the RTT and hop count, in the form of an [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr) structure.

### `HopCount` [out]

Pointer to a **ULONG** variable. This variable receives the hop count to the destination specified by the *DestIpAddress* parameter.

### `MaxHops` [in]

Maximum number of hops to search for the destination. If the number of hops to the destination exceeds this number, the function terminates the search and returns **FALSE**.

### `RTT` [out]

Round-trip time, in milliseconds, to the destination specified by *DestIpAddress*.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. Call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain the error code for the failure.

## Remarks

For information about the **IPAddr** data type, see
[Windows Data Types](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types). To convert an IP address between dotted decimal notation and **IPAddr** format, use the
[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr) and
[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions.

#### Examples

The following example retrieves and prints the round trip time and hop count to the destination IP address 127.0.0.1.

```cpp
UINT ip = inet_addr("127.0.0.1");
ULONG hopCount = 0;
ULONG RTT = 0;

if(GetRTTAndHopCount(ip, &hopCount, 30, &RTT) == TRUE) {
  printf("Hops: %ld\n", hopCount);
  printf("RTT: %ld\n", RTT);
}
else {
  printf("Error: %ld\n", GetLastError());
}

```

## See also

[GetBestInterface](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestinterface)

[GetBestRoute](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestroute)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr)