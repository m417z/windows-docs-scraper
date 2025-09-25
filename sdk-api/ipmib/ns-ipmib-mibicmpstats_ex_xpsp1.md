# MIBICMPSTATS_EX_XPSP1 structure

## Description

The
**MIBICMPSTATS_EX** structure contains extended statistics for either incoming or outgoing Internet Control Message Protocol (ICMP) messages on a particular computer.

## Members

### `dwMsgs`

Type: **DWORD**

Specifies the number of messages received or sent.

### `dwErrors`

Type: **DWORD**

 The number of errors received or sent.

### `rgdwTypeCount`

Type: **DWORD[256]**

The type count.

## Remarks

Two
**MIBICMPSTATS_EX** structures are required to hold all the extended ICMP statistics for a given computer. One
**MIBICMPSTATS_EX** structure contains the extended statistics for incoming ICMP messages. The other contains the extended statistics for outgoing ICMP messages. For this reason, the
[MIB_ICMP_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp_ex_xpsp1) structure contains two
**MIBICMPSTATS_EX** structures.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **MIBICMPSTATS_EX** structure is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIBICMPINFO](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpinfo)

[MIBICMPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mibicmpstats)

[MIB_ICMP](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp)

[MIB_ICMP_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp_ex_xpsp1)