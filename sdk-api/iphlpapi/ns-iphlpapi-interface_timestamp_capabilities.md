## Description

Describes the exact timestamp capabilities that a network adapter supports.

To retrieve the supported timestamp capabilities of a network adapter, call the [**GetInterfaceSupportedTimestampCapabilities**](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-getinterfacesupportedtimestampcapabilities) function. That function returns the supported timestamping capabilities in the form of an **INTERFACE_TIMESTAMP_CAPABILITIES** object.

For more info, and code examples, see [Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping).

## Members

### `HardwareClockFrequencyHz`

Type: **[ULONG64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Contains the frequency of the network adapter's hardware clock, rounded off to the nearest integer in Hertz units. Note this is the nominal frequency, and the actual frequency might not be the same as this. This data could be used to display the nominal clock frequency to end users for informational purposes. It's possible for *HardwareClockFrequencyHz* to contain the value 0.

### `SupportsCrossTimestamp`

Type: **[BOOLEAN](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A value of **TRUE** indicates that the network adapter driver is capable of generating a hardware cross timestamp. A cross timestamp refers to a set of network interface card (NIC) hardware timestamp and system timestamp(s) obtained very close to one another. A value of **FALSE** indicates that this capability doesn't exist.

### `HardwareCapabilities`

Type: **[INTERFACE_HARDWARE_TIMESTAMP_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/iphlpapi/ns-iphlpapi-interface_hardware_timestamp_capabilities)**

Describes the timestamping capabilities of the network interface card's (NIC's) hardware. Having both hardware and software timestamps enabled together isn't supported.

### `SoftwareCapabilities`

Type: **[INTERFACE_SOFTWARE_TIMESTAMP_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/iphlpapi/ns-iphlpapi-interface_software_timestamp_capabilities)**

Describes the software timestamping capabilities of a network interface card's (NIC's) miniport driver. Having both hardware and software timestamps enabled together isn't supported.

## See also

[Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping)