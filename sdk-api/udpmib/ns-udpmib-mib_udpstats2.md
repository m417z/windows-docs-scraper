# MIB_UDPSTATS2 structure

## Description

The
**MIB_UDPSTATS2** structure contains statistics for the User Datagram Protocol (UDP) running on the local computer. This structure is different from [MIB_UDPSTATS](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udpstats) structure in that it uses 64-bit counters, rather than 32-bit counters.

## Members

### `dw64InDatagrams`

The number of datagrams received.

### `dwNoPorts`

The number of datagrams received that were discarded because the port specified was invalid.

### `dwInErrors`

The number of erroneous datagrams received. This number does not include the value contained by the **dwNoPorts** member.

### `dw64OutDatagrams`

The number of datagrams transmitted.

### `dwNumAddrs`

The number of entries in the UDP listener table.

## Remarks

The
[GetUdpStatisticsEx2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatisticsex2) function returns a pointer to a **MIB_UDPSTATS2** structure.

## See also

[GetTcpStatisticsEx2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatisticsex2)

[GetUdpStatisticsEx2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatisticsex2)

[MIB_UDPROW](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udprow)