# _PCI_EXPRESS_DEVICE_CONTROL_REGISTER structure (ntddk.h)

## Description

The PCI_EXPRESS_DEVICE_CONTROL_REGISTER structure describes a PCI Express (PCIe) device control register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME2`

### `AsUSHORT`

A USHORT representation of the contents of the **PCI_EXPRESS_DEVICE_CONTROL_REGISTER** structure.

### `DUMMYSTRUCTNAME.AuxPowerEnable`

A single bit that indicates that the device is enabled to draw AUX power independent of power management events (PME) AUX power.

### `DUMMYSTRUCTNAME.BridgeConfigRetryEnable`

Reserved.

### `DUMMYSTRUCTNAME.CorrectableErrorEnable`

A single bit that indicates that reporting of correctable errors is enabled for the device.

### `DUMMYSTRUCTNAME.EnableRelaxedOrder`

A single bit that indicates that the device is permitted to set the relaxed ordering bit in the attributes field for any transactions that it initiates that do not require strong write ordering.

### `DUMMYSTRUCTNAME.ExtendedTagEnable`

A single bit that indicates that the device is enabled to use an 8-bit Tag field in a PCIe transaction descriptor when the device is a requester. This bit can be set only if the PCIe device capabilities register of the PCIe capability structure indicates that the extended tag size is supported.

### `DUMMYSTRUCTNAME.FatalErrorEnable`

A single bit that indicates that reporting of non-fatal uncorrectable errors is enabled for the device.

### `DUMMYSTRUCTNAME.MaxPayloadSize`

The maximum payload size for the device. Possible values are:

#### MaxPayload128Bytes

128 byte maximum payload size

#### MaxPayload256Bytes

256 byte maximum payload size

#### MaxPayload512Bytes

512 byte maximum payload size

#### MaxPayload1024Bytes

1024 byte maximum payload size

#### MaxPayload2048Bytes

2048 byte maximum payload size

#### MaxPayload4096Bytes

4096 byte maximum payload size

This value must not exceed the maximum payload size that is specified in the PCIe device capabilities register of the PCIe capability structure.

### `DUMMYSTRUCTNAME.MaxReadRequestSize`

The maximum read request size for the device as a requester. Possible values are:

#### MaxPayload128Bytes

128 byte maximum read request size

#### MaxPayload256Bytes

256 byte maximum read request size

#### MaxPayload512Bytes

512 byte maximum read request size

#### MaxPayload1024Bytes

1024 byte maximum read request size

#### MaxPayload2048Bytes

2048 byte maximum read request size

#### MaxPayload4096Bytes

4096 byte maximum read request size

### `DUMMYSTRUCTNAME.NoSnoopEnable`

A single bit that indicates that the device is permitted to set the No Snoop bit in the Requester Attributes field of transactions that it initiates that do not require hardware enforced cache coherency.

### `DUMMYSTRUCTNAME.NonFatalErrorEnable`

A single bit that indicates that reporting of non-fatal uncorrectable errors is enabled for the device.

### `DUMMYSTRUCTNAME.PhantomFunctionsEnable`

A single bit that indicates that the device is enabled to use unused function numbers (phantom functions) to extend the number of outstanding transactions that are allowed for the device. This bit can be set only if the PCIe device capabilities register of the PCIe capability structure indicates that phantom functions are supported.

### `DUMMYSTRUCTNAME.UnsupportedRequestErrorEnable`

A single bit that indicates that reporting of unsupported requests is enabled for the device.

### `DUMMYSTRUCTNAME2.InitiateFunctionLevelReset`

## Syntax

```cpp
typedef union _PCI_EXPRESS_DEVICE_CONTROL_REGISTER {
  struct {
    USHORT CorrectableErrorEnable  :1;
    USHORT NonFatalErrorEnable  :1;
    USHORT FatalErrorEnable  :1;
    USHORT UnsupportedRequestErrorEnable  :1;
    USHORT EnableRelaxedOrder  :1;
    USHORT MaxPayloadSize  :3;
    USHORT ExtendedTagEnable  :1;
    USHORT PhantomFunctionsEnable  :1;
    USHORT AuxPowerEnable  :1;
    USHORT NoSnoopEnable  :1;
    USHORT MaxReadRequestSize  :3;
    USHORT BridgeConfigRetryEnable  :1;
  };
  USHORT AsUSHORT;
} PCI_EXPRESS_DEVICE_CONTROL_REGISTER, *PPCI_EXPRESS_DEVICE_CONTROL_REGISTER;
```

## Remarks

The PCI_EXPRESS_DEVICE_CONTROL_REGISTER structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_DEVICE_CONTROL_REGISTER structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)