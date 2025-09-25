## Description

The PCI_X_CAPABILITY structure reports the contents of the command and status registers of a device that is compliant with the *PCI-X Addendum to the PCI Local Bus Specification*.

## Members

### `Header`

Contains a structure of type [PCI_CAPABILITIES_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_capabilities_header) that identifies the capability and provides a link to the next capability description.

### `Command`

Defines the **Command** union.

### `Command.bits`

Defines the **bits** structure.

### `Command.bits.DataParityErrorRecoveryEnable`

Indicates that the data parity error recovery bit is set in the device's command register, and the device will attempt to recover from data parity errors. For more information about the significance of the value in the parity error recovery bit, see the *PCI Local Bus Specification*.

### `Command.bits.EnableRelaxedOrdering`

Indicates the enable relaxed ordering bit is set in the device's command register. This leaves the device free to adopt a more relaxed transaction ordering policy. For more information about how this bit effects transaction ordering, see the *PCI Local Bus Specification*.

### `Command.bits.MaxMemoryReadByteCount`

Reports the maximum byte count, recorded in the command register, that the device uses when initiating a burst memory read command. For more information about how this bit effects read commands, see the *PCI Local Bus Specification*.

### `Command.bits.MaxOutstandingSplitTransactions`

Reports the maximum number of split transactions, recorded in the command register, that the device can initiate asynchronously. For more information about how this value effects split transactions, see the *PCI Local Bus Specification*.

### `Command.bits.Reserved`

Reserved for future use.

### `Command.AsUSHORT`

Reports the data in the device's command register in the form of an unsigned long integer.

### `Status`

Defines the **Status** union.

### `Status.bits`

Defines the **bits** structure.

### `Status.bits.FunctionNumber`

Indicates the value in the function number field of an address of a type 0 configuration transaction. For more information about the meaning of this number, see the *PCI Local Bus Specification*.

### `Status.bits.DeviceNumber`

Indicates the value in the device number field of the address of a type 0 configuration transaction. For more information about the meaning of this number, see the *PCI Local Bus Specification*.

### `Status.bits.BusNumber`

Indicates the number of the bus segment on which the device is located. For more information about the meaning of this number, see the *PCI Local Bus Specification*.

### `Status.bits.Device64Bit`

Indicates when 1 that the bus is 64 bits wide. When 0 the bus is 32 bits wide. For more information about the meaning of the status register's device 64 bit, see the *PCI Local Bus Specification*.

### `Status.bits.Capable133MHz`

Indicates when 1 that the device's maximum operating frequency is 133 MHz. Indicates when 0 that the device's maximum operating frequency is 66 MHz. For more information about the meaning of status register's capable 133 Mhz bit, see the *PCI Local Bus Specification*.

### `Status.bits.SplitCompletionDiscarded`

Indicates when 1 that the device discarded a split completion transaction because the requester rejected it. A value of 0 indicates that the device has not discarded any split completion transactions since the status register's split completion discarded bit was last cleared. For more information about the status register's split completion discarded bit, see the *PCI Local Bus Specification*.

### `Status.bits.UnexpectedSplitCompletion`

Indicates when 1 that the device has received a split completion transaction with the device's requester ID. Indicates when 0 that the device has not received this kind of transaction. For more information about the meaning of the status register's unexpected split completion bit, see the *PCI Local Bus Specification*.

### `Status.bits.DeviceComplexity`

Indicates when 1 that the device is a bridge device. When 0 the device is not a bridge device. For more information about the meaning of the status register's device complexity bit, see the *PCI Local Bus Specification*.

### `Status.bits.DesignedMaxMemoryReadByteCount`

Reports the maximum byte count, defined in the status register, that the device uses when it initiates a read sequence. For more information about the meaning of this value, see the *PCI Local Bus Specification*.

### `Status.bits.DesignedMaxOutstandingSplitTransactions`

Reports the maximum number of split transactions, defined in the status register, that the device can permit at any one time. For more information about the meaning of this value, see the *PCI Local Bus Specification*.

### `Status.bits.DesignedMaxCumulativeReadSize`

Reports the maximum number of burst memory read transactions, defined in the status register, that the device allows at any one time. For more information about this value, see the *PCI Local Bus Specification*.

### `Status.bits.ReceivedSplitCompletionErrorMessage`

Indicates when 1 that the device has received a split completion error message. Indicates when 0 that the device has not received a split completion error message.

### `Status.bits.CapablePCIX266`

Defines the **ULONG** member **CapablePCIX266**.

### `Status.bits.CapablePCIX533`

Defines the **ULONG** member **CapablePCIX533**.

### `Status.AsULONG`

Reports the data in the device's status register in the form of an unsigned long integer.

## See also

[PCI_CAPABILITIES_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_capabilities_header)