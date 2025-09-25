# _PCI_EXPRESS_SEC_AER_CAPABILITIES structure (wdm.h)

## Description

The PCI_EXPRESS_SEC_AER_CAPABILITIES structure describes a PCI Express (PCIe) secondary error capabilities and control register of a PCIe advanced error reporting capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_SEC_AER_CAPABILITIES structure.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `DUMMYSTRUCTNAME.SecondaryUncorrectableFirstErrorPtr`

The bit position of the first error that was reported in the PCIe secondary uncorrectable error status register.

## Syntax

```cpp
typedef union _PCI_EXPRESS_SEC_AER_CAPABILITIES {
  struct {
    ULONG SecondaryUncorrectableFirstErrorPtr  :5;
    ULONG Reserved  :27;
  };
  ULONG  AsULONG;
} PCI_EXPRESS_SEC_AER_CAPABILITIES, *PPCI_EXPRESS_SEC_AER_CAPABILITIES;
```

## Remarks

The PCI_EXPRESS_SEC_AER_CAPABILITIES structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_SEC_AER_CAPABILITIES structure is contained in the [PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability) structure.

## See also

[PCI_EXPRESS_BRIDGE_AER_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_bridge_aer_capability)