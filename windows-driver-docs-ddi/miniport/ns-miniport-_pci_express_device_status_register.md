## Description

The **PCI_EXPRESS_DEVICE_STATUS_REGISTER** union describes a PCI Express (PCIe) device status register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.CorrectableErrorDetected`

A single bit that indicates that a correctable error has been detected.

### `DUMMYSTRUCTNAME.NonFatalErrorDetected`

A single bit that indicates that a non-fatal uncorrectable error has been detected.

### `DUMMYSTRUCTNAME.FatalErrorDetected`

A single bit that indicates that a non-fatal uncorrectable error has been detected.

### `DUMMYSTRUCTNAME.UnsupportedRequestDetected`

A single bit that indicates that an unsupported request has been detected.

### `DUMMYSTRUCTNAME.AuxPowerDetected`

A single bit that indicates that AUX power has been detected.

### `DUMMYSTRUCTNAME.TransactionsPending`

A single bit that indicates that the device has issued non-posted requests that have not been completed. The device clears this bit when all outstanding non-posted requests have completed or have been terminated by the completion timeout mechanism.

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

### `AsUSHORT`

A **USHORT** representation of the contents of the **PCI_EXPRESS_DEVICE_STATUS_REGISTER** structure.

## Remarks

The **PCI_EXPRESS_DEVICE_STATUS_REGISTER** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_DEVICE_STATUS_REGISTER** structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)