# _PCI_EXPRESS_SLOT_STATUS_REGISTER structure (ntddk.h)

## Description

The PCI_EXPRESS_SLOT_STATUS_REGISTER structure describes a PCI Express (PCIe) slot status register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsUSHORT`

A USHORT representation of the contents of the PCI_EXPRESS_SLOT_STATUS_REGISTER structure.

### `DUMMYSTRUCTNAME.AttentionButtonPressed`

A single bit that indicates that the attention button for the slot is being pressed.

### `DUMMYSTRUCTNAME.CommandCompleted`

A single bit that indicates that a command has been completed by the slot's hot-plug controller.

### `DUMMYSTRUCTNAME.DataLinkStateChanged`

A single bit that indicates that the data link layer active bit of the PCIe link status register of the PCIe capability structure has changed.

### `DUMMYSTRUCTNAME.ElectromechanicalLockEngaged`

A single bit that indicates if the slot's electromechanical interlock is engaged.

### `DUMMYSTRUCTNAME.MRLSensorChanged`

A single bit that indicates that the state of the slot's manually operated retention latch (MRL) sensor has changed.

### `DUMMYSTRUCTNAME.MRLSensorState`

The slot's manually operated retention latch (MRL) sensor state. Possible values are:

#### MRLClosed

The MRL is closed.

#### MRLOpen

The MRL is open.

### `DUMMYSTRUCTNAME.PowerFaultDetected`

A single bit that indicates that a power fault at the slot has been detected.

### `DUMMYSTRUCTNAME.PresenceDetectChanged`

A single bit that indicates that the card presence detection state for the slot has changed.

### `DUMMYSTRUCTNAME.PresenceDetectState`

The slot's card presence detection state. Possible values are:

#### SlotEmpty

The slot is empty.

#### CardPresent

A card is present in the slot.

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

## Syntax

```cpp
typedef union _PCI_EXPRESS_SLOT_STATUS_REGISTER {
  struct {
    USHORT AttentionButtonPressed  :1;
    USHORT PowerFaultDetected  :1;
    USHORT MRLSensorChanged  :1;
    USHORT PresenceDetectChanged  :1;
    USHORT CommandCompleted  :1;
    USHORT MRLSensorState  :1;
    USHORT PresenceDetectState  :1;
    USHORT ElectromechanicalLockEngaged  :1;
    USHORT DataLinkStateChanged  :1;
    USHORT Rsvd  :7;
  };
  USHORT AsUSHORT;
} PCI_EXPRESS_SLOT_STATUS_REGISTER, *PPCI_EXPRESS_SLOT_STATUS_REGISTER;
```

## Remarks

The PCI_EXPRESS_SLOT_STATUS_REGISTER structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_SLOT_STATUS_REGISTER structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)