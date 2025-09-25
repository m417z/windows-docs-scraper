# TimeSample structure

## Description

Represents a time sample.

## Members

### `dwSize`

The size of the structure, in bytes.

### `dwRefid`

A reference identifier for the time source, in NTP format (either an IP address or a four character ASCII string that describes the hardware source, such as GPS or WWVB).

### `toOffset`

The difference between local and remote clocks, in (10^-7)s.

### `toDelay`

The total roundtrip delay, in (10^-7)s. This is the time packets spent in transit from the root time source to the client, including root delay. For NTP providers, this means roundtrip delay to the peer, plus the peer's root delay. The hardware providers, this value is probably zero.

### `tpDispersion`

The total measurement error of the clock offset, including root dispersion, in (10^-7)s. This includes errors in reading the local clock, uncertainty in the local clock frequency, and error from filters. For NTP providers, this includes the peer's root dispersion.

### `nSysTickCount`

The value returned by
[GetTimeSysInfo](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-gettimesysinfofunc) with TSI_TickCount.

### `nSysPhaseOffset`

The value returned by
[GetTimeSysInfo](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-gettimesysinfofunc) with TSI_PhaseOffset.

### `nLeapFlags`

A variable that indicates an impending leap second or loss of synchronization. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | No change. |
| 1 | Add leap second. |
| 2 | Subtract leap second. |
| 3 | Not synchronized. |

### `nStratum`

The number of network hops separating this computer from the root source. Hardware providers should return zero. NTP providers should return the stratum of the peer that provided the sample.

### `dwTSFlags`

The information about the time source.

| Value | Meaning |
| --- | --- |
| **TSF_Authenticated** | The sample has been cryptographically authenticated. |
| **TSF_Hardware** | The sample is from a hardware device such as a GPS or radio receiver. |

### `wszUniqueName`

The name that uniquely identifies the source of the sample. For network providers, the name should include the protocol and IP addresses. For hardware devices, the name should include the device name and communication port.

## See also

[GetTimeSysInfoFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-gettimesysinfofunc)

[TpcGetSamplesArgs](https://learn.microsoft.com/windows/desktop/api/timeprov/ns-timeprov-tpcgetsamplesargs)