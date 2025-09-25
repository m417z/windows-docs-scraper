# MIB_ICMP structure

## Description

The
**MIB_ICMP** structure contains the Internet Control Message Protocol (ICMP) statistics for a particular computer.

## Members

### `stats`

A
[MIBICMPINFO](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpinfo) structure that contains the ICMP statistics for the computer.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **MIB_ICMP** structure is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetIcmpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-geticmpstatistics)

[MIBICMPINFO](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpinfo)

[MIBICMPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats)

[MIBICMPSTATS_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats_ex_xpsp1)

[MIB_ICMP_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp_ex_xpsp1)