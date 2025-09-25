## Description

Describes a cross timestamp retrieved from a network adapter. A cross timestamp refers to a set of network interface card (NIC) hardware timestamp and system timestamp(s) obtained very close to one another.

To retrieve a cross timestamp, call the [**CaptureInterfaceHardwareCrossTimestamp**](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-captureinterfacehardwarecrosstimestamp) function. That function returns the timestamp from the network adapter in the form of an **INTERFACE_HARDWARE_CROSSTIMESTAMP** object.

For more info, and code examples, see [Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping).

## Members

### `SystemTimestamp1`

Type: **[ULONG64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The network adapter driver fills this with a system timestamp whose value corresponds to a value returned by [**QueryPerformanceCounter**](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter) (QPC).

*SystemTimestamp1* is obtained before *HardwareClockTimestamp*; while *SystemTimestamp2* is taken after *HardwareClockTimestamp*. The timestamp values are obtained as closely as possible to each other.

### `HardwareClockTimestamp`

Type: **[ULONG64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The network adapter driver fills this with a value obtained from its network interface card (NIC) hardware clock.

### `SystemTimestamp2`

Type: **[ULONG64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The network adapter driver fills this with a system timestamp whose value corresponds to a value returned by [**QueryPerformanceCounter**](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter) (QPC).

*SystemTimestamp1* is obtained before *HardwareClockTimestamp*; while *SystemTimestamp2* is taken after *HardwareClockTimestamp*. The timestamp values are obtained as closely as possible to each other.

## See also

[Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping)