# MIB_ICMP_EX_XPSP1 structure

## Description

The
**MIB_ICMP_EX** structure contains the extended Internet Control Message Protocol (ICMP) statistics for a particular computer.

## Members

### `icmpInStats`

Specifies an [MIBICMPSTATS_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats_ex_xpsp1) structure that contains the extended statistics for incoming ICMP messages.

### `icmpOutStats`

Specifies an [MIBICMPSTATS_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats_ex_xpsp1) structure that contains the extended statistics for outgoing ICMP messages.

## Remarks

Two
[MIBICMPSTATS_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats_ex_xpsp1) structures are required to hold all the extended ICMP statistics for a given computer. One
**MIBICMPSTATS_EX** structure contains the extended statistics for incoming ICMP messages. The other contains the extended statistics for outgoing ICMP messages. For this reason, the
**MIB_ICMP_EX** structure contains two
**MIBICMPSTATS_EX** structures.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **MIB_ICMP_EX** structure is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetIcmpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-geticmpstatistics)

[MIBICMPINFO](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpinfo)

[MIBICMPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats)

[MIBICMPSTATS_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats_ex_xpsp1)

[MIB_ICMP](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp)