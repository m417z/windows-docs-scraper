# MIB_UDPSTATS structure

## Description

The
**MIB_UDPSTATS** structure contains statistics for the User Datagram Protocol (UDP) running on the local computer.

## Members

### `dwInDatagrams`

The number of datagrams received.

### `dwNoPorts`

The number of datagrams received that were discarded because the port specified was invalid.

### `dwInErrors`

The number of erroneous datagrams received. This number does not include the value contained by the **dwNoPorts** member.

### `dwOutDatagrams`

The number of datagrams transmitted.

### `dwNumAddrs`

The number of entries in the UDP listener table.

## Remarks

The
[GetUdpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatistics) function returns a pointer to a **MIB_UDPSTATS** structure.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Udpmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Udpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Udpmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetTcpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatistics)

[GetUdpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatistics)

[MIB_UDPROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow)