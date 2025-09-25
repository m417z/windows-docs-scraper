# MIBICMPINFO structure

## Description

The
**MIBICMPINFO** structure contains Internet Control Message Protocol (ICMP) statistics for a particular computer.

## Members

### `icmpInStats`

An
[MIBICMPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats) structure that contains the statistics for incoming ICMP messages.

### `icmpOutStats`

An
[MIBICMPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats) structure that contains the statistics for outgoing ICMP messages.

## Remarks

Two
[MIBICMPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats) structures are required to hold all the ICMP statistics for a given computer. One
**MIBICMPSTATS** structure contains the statistics for incoming ICMP messages. The other contains the statistics for outgoing ICMP messages. For this reason, the
**MIBICMPINFO** structure contains two
**MIBICMPSTATS** structures.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **MIBICMPINFO** structure is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIBICMPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats)

[MIBICMPSTATS_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats_ex_xpsp1)

[MIB_ICMP](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp)

[MIB_ICMP_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp_ex_xpsp1)