# IOCTL_VPCI_INVALIDATE_BLOCK IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The driver for a PCI Express (PCIe) virtual function (VF) issues the [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) IOCTL request in order to be notified of changes to data in one or more VF configuration blocks. The driver is notified of these changes when the IOCTL is completed. Once notified, the driver should assume that any data previously read from the specified VF configuration blocks has become invalid. Therefore, the driver should update its cache by reading the configuration block data again.

The driver issues this IOCTL to the next-lower driver in the driver stack.

**Note** This IOCTL request is issued by the driver of a PCIe VF on a device that supports the single root I/O virtualization (SR-IOV) interface.

When the driver issues the [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) IOCTL, the driver must follow these steps:

[Preparing an I/O Request Packet Structure](https://learn.microsoft.com/)

[Preparing an I/O Stack Location Structure](https://learn.microsoft.com/)

[Issuing the IOCTL Request](https://learn.microsoft.com/)

[IOCTL Request Completion Results](https://learn.microsoft.com/)

For more information about issuing IOCTLs between kernel-mode drivers, see [Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers).

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [XREF-LINK:NTSTATUS Values].

## Remarks

### Preparing an I/O Request Packet Structure

The driver must first allocate or reuse an I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)). You can use the [IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest) routine to specifically allocate an IOCTL IRP. You can also use general-purpose IRP creation and initialization routines, such as [IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp), [IoReuseIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreuseirp), or [IoInitializeIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeirp). For more information about IRP allocation, see [Creating IRPs for Lower-Level Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-irps-for-lower-level-drivers).

The driver must then set the members of the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure as described in the following table.

| [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) member | Value |
| --- | --- |
| **UserBuffer** | **NULL** |
| **UserEvent** | The address of the event object that was initialized in the call to the [KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent) routine.<br><br>**Note** If asynchronous completion of the IOCTL request is not required, this member should be set to **NULL**. For more information, see [Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers). |
| **UserIosb** | The address of a caller-allocated [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure. This structure is updated by the lower driver to indicate the final status of the I/O request. |

### Preparing an I/O Stack Location Structure

The driver calls the [IoGetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetnextirpstacklocation) routine to access the lower driver's I/O stack location. This function returns a pointer to an [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure that contains the parameters for the I/O stack location.

The driver must then set the members in the [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure as described in the following table.

| [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) member | Value |
| --- | --- |
| **MajorFunction** | [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control) |
| **Parameters**.**DeviceIoControl**.**IoControlCode** | [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) |
| **Parameters**.**DeviceIoControl**.**Type3InputBuffer** | A pointer to a [VPCI_INVALIDATE_BLOCK_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-_vpci_invalidate_block_output) structure. The driver formats this structure with the parameters for the [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) I/O request. |
| I**Parameters**.**DeviceIoControl**.**InputBufferLength** | The size, in bytes, of the [VPCI_INVALIDATE_BLOCK_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-_vpci_invalidate_block_output) structure. |
| **Parameters**.**DeviceIoControl**.**OutputBufferLength** | The size, in bytes, of the caller-allocated buffer that will contain the configuration data to be read.<br><br>**Note** This value must be the same as the value of the **BytesRequested** member of the [VPCI_INVALIDATE_BLOCK_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-_vpci_invalidate_block_output) structure. |

### Issuing the IOCTL Request

To issue this IOCTL request, the driver calls the [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) routine to pass the request on to the next-lower driver in the driver stack. The driver sets the parameters of **IoCallDriver** as described in the following table.

| [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) parameter | Value |
| --- | --- |
| *DeviceObject* | The device object of the lower driver. |
| *Irp* | The address of the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) that was previously allocated and initialized. For more information, see [Preparing an I/O Request Packet Structure](https://learn.microsoft.com/). |

### IOCTL Request Completion Results

When the [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) IOCTL request is completed, the members of the caller-allocated [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure are set to the values in the following table.

| Status value | Value |
| --- | --- |
| **Status** | **STATUS_SUCCESS** |
| **Information** | Zero |

When the [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) IOCTL is issued and completed, the VF driver is notified that the PF driver has changed (*invalidated*) data in one or more VF configuration blocks.

**Note** The operating system reserves and manages the resources that are required for the successful completion of this IOCTL.

A VF configuration block is used for backchannel communication between the drivers of the PCIe PF and a VF on a device that supports the SR-IOV interface. VF configuration data can be exchanged between the following drivers:

* The VF driver, which runs in the guest operating system. This operating system runs within a Hyper-V child partition.
* The PF driver, which runs in the management operating system.

  This operating system runs within the Hyper-V parent partition.

Starting with NDIS 6.30, the VF miniport driver should not issue an [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) request. Instead, the following steps are performed in order to handle notifications of invalidated VF configuration block data.

1. In the guest OS, NDIS issues an [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) request.
2. In the management OS, the following steps occur:
   1. The PF miniport driver calls the [NdisMInvalidateConfigBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisminvalidateconfigblock) function to notify NDIS that VF configuration data has changed and is no longer valid. The driver sets the *BlockMask* parameter to a **ULONGLONG** bitmask that specifies which VF configuration blocks have changed. Each bit in the bitmask corresponds to a VF configuration block. If a bit is set to one, the data in the corresponding VF configuration block has changed.
   2. NDIS signals the virtualization stack, which runs in the management OS, about the change in VF configuration block data. The virtualization stack caches the *BlockMask* parameter data.

      **Note** Each time that the PF miniport driver calls [NdisMInvalidateConfigBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisminvalidateconfigblock), the virtualization stack **OR**s the *BlockMask* parameter data with the current value in its cache.
   3. The virtualization stack notifies the virtual PCI (VPCI) driver, which runs in the guest OS, about the invalidation of VF configuration data. The virtualization stack sends the cached *BlockMask* parameter data to the VPCI driver.
3. In the Guest OS, the following steps occur:
   1. The VPCI driver saves the cached *BlockMask* parameter data in the **BlockMask** member of the [VPCI_INVALIDATE_BLOCK_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-_vpci_invalidate_block_output) structure that is associated with the [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) request.
   2. The VPCI driver successfully completes the [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) request. When this happens, NDIS issues an object identifier (OID) request of [OID_SRIOV_VF_INVALIDATE_CONFIG_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-vf-invalidate-config-block) to the VF miniport driver. A pointer to an [NDIS_SRIOV_VF_INVALIDATE_CONFIG_BLOCK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_vf_invalidate_config_block_info) structure is passed along in the OID request. This structure contains the cached *BlockMask* parameter data.

      NDIS also issues another [IOCTL_VPCI_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_invalidate_block) request to handle successive notifications of changes to VF configuration data.
   3. When the VF driver handles the [OID_SRIOV_VF_INVALIDATE_CONFIG_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-vf-invalidate-config-block) request, it reads data from the specified VF configuration blocks.

**Note** The usage of the VF configuration block and the format of its configuration data are defined by the independent hardware vendor (IHV) of the device. The configuration data is used only by the drivers of the PF and VF.

## See also

[IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[VPCI_INVALIDATE_BLOCK_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-_vpci_invalidate_block_output)

[NdisMInvalidateConfigBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisminvalidateconfigblock)

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[OID_SRIOV_VF_INVALIDATE_CONFIG_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-vf-invalidate-config-block)

[NDIS_SRIOV_VF_INVALIDATE_CONFIG_BLOCK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_vf_invalidate_config_block_info)