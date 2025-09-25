# _PCI_EXPRESS_DEVICE_STATUS_REGISTER structure (ntddk.h)

## Description

The PCI_EXPRESS_DEVICE_STATUS_REGISTER structure describes a PCI Express (PCIe) device status register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsUSHORT`

A USHORT representation of the contents of the PCI_EXPRESS_DEVICE_STATUS_REGISTER structure.

### `DUMMYSTRUCTNAME.AuxPowerDetected`

A single bit that indicates that AUX power has been detected.

### `DUMMYSTRUCTNAME.CorrectableErrorDetected`

A single bit that indicates that a correctable error has been detected.

### `DUMMYSTRUCTNAME.FatalErrorDetected`

A single bit that indicates that a non-fatal uncorrectable error has been detected.

### `DUMMYSTRUCTNAME.NonFatalErrorDetected`

A single bit that indicates that a non-fatal uncorrectable error has been detected.

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

### `DUMMYSTRUCTNAME.TransactionsPending`

A single bit that indicates that the device has issued non-posted requests that have not been completed. The device clears this bit when all outstanding non-posted requests have completed or have been terminated by the completion timeout mechanism.

### `DUMMYSTRUCTNAME.UnsupportedRequestDetected`

A single bit that indicates that an unsupported request has been detected.

## Syntax

```cpp
typedef union _PCI_EXPRESS_DEVICE_STATUS_REGISTER {
  struct {
    USHORT CorrectableErrorDetected  :1;
    USHORT NonFatalErrorDetected  :1;
    USHORT FatalErrorDetected  :1;
    USHORT UnsupportedRequestDetected  :1;
    USHORT AuxPowerDetected  :1;
    USHORT TransactionsPending  :1;
    USHORT Rsvd  :10;
  };
  USHORT AsUSHORT;
} PCI_EXPRESS_DEVICE_STATUS_REGISTER, *PPCI_EXPRESS_DEVICE_STATUS_REGISTER;
```

## Remarks

The **PCI_EXPRESS_DEVICE_STATUS_REGISTER** structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_DEVICE_STATUS_REGISTER structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)