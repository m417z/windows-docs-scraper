# STORAGE_ADAPTER_DESCRIPTOR structure

## Description

The **STORAGE_ADAPTER_DESCRIPTOR** structure is used in conjunction with the [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request to retrieve the storage adapter descriptor data for a device.

## Members

### `Version`

Contains the version of the structure **STORAGE_ADAPTER_DESCRIPTOR**. The value of this member will change as members are added to the structure.

### `Size`

Specifies the total size of the descriptor, in bytes.

### `MaximumTransferLength`

Specifies the maximum number of bytes the host bus adapter (HBA) can transfer in a single operation.

### `MaximumPhysicalPages`

Specifies the maximum number of discontinuous physical pages the HBA can manage in a single transfer (in other words, the extent of its scatter/gather support).

### `AlignmentMask`

Specifies the HBA's alignment requirements for transfers. A storage class driver sets the **AlignmentRequirement** field in its device objects to this value. The alignment mask indicates alignment restrictions for buffers required by the HBA for transfer operations. The valid mask values are 0 (byte aligned), 1 (word aligned), 3 (DWORD aligned), and 7 (double DWORD aligned).

### `AdapterUsesPio`

Indicates when **TRUE** that the HBA uses Programmed Input/Output (PIO) and requires the use of system-space virtual addresses mapped to physical memory for data buffers. When **FALSE**, the HBA does not use PIO.

### `AdapterScansDown`

Indicates when **TRUE** that the HBA scans down for BIOS devices, that is, the HBA begins scanning with the highest device number rather than the lowest. When **FALSE**, the HBA begins scanning with the lowest device number. This member is reserved for legacy miniport drivers.

### `CommandQueueing`

Indicates when **TRUE** that the HBA supports SCSI-tagged queuing and/or per-logical-unit internal queues, or the non-SCSI equivalent. When **FALSE**, the HBA neither supports SCSI-tagged queuing nor per-logical-unit internal queues.

### `AcceleratedTransfer`

Indicates when **TRUE** that the HBA supports synchronous transfers as a way of speeding up I/O. When **FALSE**, the HBA does not support synchronous transfers as a way of speeding up I/O.

### `BusType`

Specifies a value of type [**STORAGE_BUS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_bus_type) that indicates the type of bus to which the device is connected.

### `BusMajorVersion`

Specifies the major version number, if any, of the HBA.

### `BusMinorVersion`

Specifies the minor version number, if any, of the HBA.

### `SrbType`

Specifies the SCSI request block (SRB) type used by the HBA. This member is valid starting with Windows 8.

| Value | Meaning |
| ----- | ------- |
| SRB_TYPE_SCSI_REQUEST_BLOCK | The HBA uses SCSI request blocks. |
| SRB_TYPE_STORAGE_REQUEST_BLOCK | The HBA uses extended SCSI request blocks. |

### `AddressType`

Specifies the address type of the HBA. This member is valid starting with Windows 8.

| Value | Meaning |
| ----- | ------- |
| STORAGE_ADDRESS_TYPE_BTL8 | The HBA uses 8-bit bus, target, and LUN addressing. |

## Remarks

Storage class drivers issue a device-control request with the I/O control code [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) to retrieve this structure, which contains configuration information from the HBA for data transfer operations. The structure can be retrieved either from the device object for the bus or from a functional device object (FDO), which forwards the request to the underlying bus.

If excessive protocol errors occur on an HBA that supports synchronous transfers (**AcceleratedTransfer** is **TRUE**), the storage class driver can disable synchronous transfers by setting SRB_FLAGS_DISABLE_SYNCH_TRANSFER in SRBs.

## See also

[**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**IoBuildDeviceIoControlRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[**STORAGE_ADAPTER_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_adapter_descriptor)

[**STORAGE_BUS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_bus_type)

[**STORAGE_DESCRIPTOR_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_descriptor_header)

[**STORAGE_DEVICE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor)

[**STORAGE_DEVICE_ID_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_id_descriptor)