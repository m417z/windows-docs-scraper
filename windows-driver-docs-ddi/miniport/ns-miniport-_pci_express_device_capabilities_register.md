## Description

The **PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER** union describes a PCI Express (PCIe) device capabilities register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.MaxPayloadSizeSupported`

The maximum payload size that is supported by the device. Possible values are:

**MaxPayload128Bytes**
128 byte maximum payload size

**MaxPayload256Bytes**
256 byte maximum payload size

**MaxPayload512Bytes**
512 byte maximum payload size

**MaxPayload1024Bytes**
1024 byte maximum payload size

**MaxPayload2048Bytes**
2048 byte maximum payload size

**MaxPayload4096Bytes**
4096 byte maximum payload size

### `DUMMYSTRUCTNAME.PhantomFunctionsSupported`

A value that indicates the support of unused function numbers (phantom functions) to extend the number of outstanding transactions that are allowed for the device. Possible values are:

**0**
No function number bits are used for phantom functions. The device can implement functions for all eight function numbers.

**1**
The most significant bit in the function number is used for phantom functions. The device can implement functions for function numbers 0 to 3.

**2**
The two most significant bits in the function number are used for phantom functions. The device can implement functions for function numbers 0 and 1.

**3**
All three bits in the function number are used for phantom functions. The device implements only a single function for function number 0.

### `DUMMYSTRUCTNAME.ExtendedTagSupported`

A single bit that specifies the maximum supported size of the Tag field in a PCIe transaction descriptor when the device is a requester. If this bit is clear, a 5-bit Tag field is supported. If this bit is set, an 8-bit Tag field is supported.

### `DUMMYSTRUCTNAME.L0sAcceptableLatency`

The maximum acceptable total latency that the device can withstand due to a transition from the L0s state to the L0 state. Possible values are:

**L0s_Below64ns**
64 nanoseconds

**L0s_64ns_128ns**
128 nanoseconds

**L0s_128ns_256ns**
256 nanoseconds

**L0s_256ns_512ns**
512 nanoseconds

**L0s_512ns_1us**
1 microsecond

**L0s_1us_2us**
2 microseconds

**L0s_2us_4us**
4 microseconds

**L0s_Above4us**
No limit

### `DUMMYSTRUCTNAME.L1AcceptableLatency`

The maximum acceptable total latency that the device can withstand due to a transition from the L1 state to the L0 state. Possible values are:

**L1_Below1us**
1 microsecond

**L1_1us_2us**
2 microseconds

**L1_2us_4us**
4 microseconds

**L1_4us_8us**
8 microseconds

**L1_8us_16us**
16 microseconds

**L1_16us_32us**
32 microseconds

**L1_32us_64us**
64 microseconds

**L1_Above64us**
No limit

### `DUMMYSTRUCTNAME.Undefined`

Reserved.

### `DUMMYSTRUCTNAME.RoleBasedErrorReporting`

A single bit that indicates that the device implements role-based error reporting.

### `DUMMYSTRUCTNAME.Rsvd1`

Reserved.

### `DUMMYSTRUCTNAME.CapturedSlotPowerLimit`

The maximum amount of power that can be supplied by the slot. This value is used in combination with the value of the **CapturedSlotPowerLimitScale** member to compute the power in watts.

### `DUMMYSTRUCTNAME.CapturedSlotPowerLimitScale`

The scale used for the value contained in the **CapturedSlotPowerLimit** member to compute the maximum power, in watts, that can be supplied by the slot. Possible values are:

**0**
Multiply the value in the **CapturedSlotPowerLimit** member by 1.0.

**1**
Multiply the value in the **CapturedSlotPowerLimit** member by 0.1.

**2**
Multiply the value in the **CapturedSlotPowerLimit** member by 0.01.

**3**
Multiply the value in the **CapturedSlotPowerLimit** member by 0.001.

### `DUMMYSTRUCTNAME.FunctionLevelResetCapability`

Defines the **ULONG** member **FunctionLevelResetCapability**.

### `DUMMYSTRUCTNAME.Rsvd2`

Reserved.

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER structure.

## Remarks

The PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)