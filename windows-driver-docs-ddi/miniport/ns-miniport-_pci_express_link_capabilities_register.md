## Description

The **PCI_EXPRESS_LINK_CAPABILITIES_REGISTER** union describes a PCI Express (PCIe) link capabilities register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.MaximumLinkSpeed`

The maximum link speed of the PCIe link. The only valid value is:

**1**
2.5 gigabits per second

All other values are reserved.

### `DUMMYSTRUCTNAME.MaximumLinkWidth`

The maximum link width (number of lanes) implemented by the component. Possible values are:

**1**
x1 (1 lane)

**2**
x2 (2 lanes)

**4**
x4 (4 lanes)

**8**
x8 (8 lanes)

**12**
x12 (12 lanes)

**16**
x16 (16 lanes)

**32**
x32 (32 lanes)

All other values are reserved.

### `DUMMYSTRUCTNAME.ActiveStatePMSupport`

The level of active state power management supported on the PCIe link. Possible values are:

**L0sEntrySupport**
L0s is supported.

**L0sAndL1EntrySupport**
L0s and L1 are supported.

All other values are reserved.

### `DUMMYSTRUCTNAME.L0sExitLatency`

The L0s exit latency for the PCIe link. This value indicates the length of time this port requires to complete a transition from L0s to L0.

**L0s_Below64ns**
Less than 64 nanoseconds

**L0s_64ns_128ns**
64 nanoseconds to 128 nanoseconds

**L0s_128ns_256ns**
128 nanoseconds to 256 nanoseconds

**L0s_256ns_512ns**
256 nanoseconds to 512 nanoseconds

**L0s_512ns_1us**
512 nanoseconds to 1 microsecond

**L0s_1us_2us**
1 microsecond to 2 microseconds

**L0s_2us_4us**
2 microseconds to 4 microseconds

**L0s_Above4us**
More than 4 microseconds

### `DUMMYSTRUCTNAME.L1ExitLatency`

The L1 exit latency for the PCIe link. This value indicates the length of time this port requires to complete a transition from L1 to L0.

**L1_Below1us**
Less than 1 microsecond

**L1_1us_2us**
1 microsecond to 2 microseconds

**L1_2us_4us**
2 microseconds to 4 microseconds

**L1_4us_8us**
4 microseconds to 8 microseconds

**L1_8us_16us**
8 microseconds to 16 microseconds

**L1_16us_32us**
16 microseconds to 32 microseconds

**L1_32us_64us**
32 microseconds to 64 microseconds

**L1_Above64us**
More than 64 microseconds

This value is ignored if the **ActiveStatePMSupport** member is not set to **L0sAndL1EntrySupport**.

### `DUMMYSTRUCTNAME.ClockPowerManagement`

A single bit that indicates that the component supports clock power management.

### `DUMMYSTRUCTNAME.SurpriseDownErrorReportingCapable`

A single bit that indicates that the component supports the optional capability of detecting and reporting a surprise-down error condition. This bit only applies to downstream ports.

### `DUMMYSTRUCTNAME.DataLinkLayerActiveReportingCapable`

A single bit that indicates that the component supports the optional capability of reporting the data link active state of the data link control and management state machine. This bit only applies to downstream ports. Hot-plug capable downstream ports must support this capability.

### `DUMMYSTRUCTNAME.LinkBandwidthNotificationCapability`

Defines the **ULONG** member **LinkBandwidthNotificationCapability**.

### `DUMMYSTRUCTNAME.AspmOptionalityCompliance`

Defines the **ULONG** member **AspmOptionalityCompliance**.

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

### `DUMMYSTRUCTNAME.PortNumber`

The PCIe port number for the PCIe link.

### `AsULONG`

A **ULONG** representation of the contents of the **PCI_EXPRESS_LINK_CAPABILITIES_REGISTER** structure.

## Remarks

The **PCI_EXPRESS_LINK_CAPABILITIES_REGISTER** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_LINK_CAPABILITIES_REGISTER** structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)