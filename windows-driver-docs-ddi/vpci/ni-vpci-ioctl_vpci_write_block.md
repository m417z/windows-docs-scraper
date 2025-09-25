# IOCTL_VPCI_WRITE_BLOCK IOCTL

## Major Code:

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

The driver for a PCI Express (PCIe) virtual function (VF) issues an [IOCTL_VPCI_WRITE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_write_block)
I/O control code (IOCTL) in order to write data to a VF configuration block. The driver issues this IOCTL to the next-lower driver in the driver stack.

**Note** This IOCTL request is issued by the driver of a PCIe VF on a device that supports the single root I/O virtualization (SR-IOV) interface.

When the driver issues the [IOCTL_VPCI_WRITE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_write_block) IOCTL, the driver must follow these steps:

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

| IRP member | Value |
| --- | --- |
| **UserBuffer** | **NULL** |
| **UserEvent** | The address of the event object that was initialized in the call to the [KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent) routine.<br><br>**Note** If asynchronous completion of the IOCTL request is not required, this member should be set to **NULL**. For more information, see [Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers). |
| **UserIosb** | The address of a caller-allocated [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure. This structure is updated by the lower driver to indicate the final status of the I/O request. |

### Preparing an I/O Stack Location Structure

The driver calls the [IoGetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetnextirpstacklocation) routine to access the lower driver's I/O stack location. This function returns a pointer to an [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure that contains the parameters for the I/O stack location.

The driver must then set the members in the [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure as described in the following table:

| IO_STACK_LOCATION member | Value |
| --- | --- |
| **MajorFunction** | [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control) |
| **Parameters.DeviceIoControl.IoControlCode** | [IOCTL_VPCI_WRITE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_write_block) |
| **Parameters.DeviceIoControl.Type3InputBuffer** | A pointer to a [VPCI_WRITE_BLOCK_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-_vpci_write_block_input) structure. The driver formats this structure with the parameters for the [IOCTL_VPCI_WRITE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_write_block) I/O request. |
| I**Parameters.DeviceIoControl.InputBufferLength** | The size, in bytes, of the [VPCI_WRITE_BLOCK_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-_vpci_write_block_input) structure. |
| **Parameters.DeviceIoControl.OutputBufferLength** | Zero |

### Issuing the IOCTL Request

To issue this IOCTL request, the driver calls the [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) routine to pass the request on to the next-lower driver in the driver stack. The driver sets the parameters of **IoCallDriver** as described in the following table.

| IoCallDriver parameter | Value |
| --- | --- |
| *DeviceObject* | The device object of the lower driver. |
| *Irp* | The address of the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) that was previously allocated and initialized. For more information, see [Preparing an I/O Request Packet (IRP) Structure](https://learn.microsoft.com/). |

### IOCTL Request Completion Results

When the [IOCTL_VPCI_WRITE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_write_block) IOCTL request is completed, the **Status** member of the caller-allocated [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure is set to one of the values in the following table.:

| Status value | Description |
| --- | --- |
| **STATUS_SUCCESS** | The IOCTL completed successfully. |
| **STATUS_PENDING** | The IOCTL has not completed. The driver must call the [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject) routine in order to put the current thread into a wait state. The driver sets the *Object* parameter to the address of an event object that was initialized in the call to the [KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent) routine.<br><br>The event is signaled when the IOCTL request is completed. Once the event is signaled, the thread resumes execution. |
| **STATUS_BUFFER_TOO_SMALL** | The **Parameters.DeviceIoControl.InputBufferLength** member was set to a value less than the size, in bytes, of the [VPCI_WRITE_BLOCK_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-_vpci_write_block_input) structure. |

If the request completed successfully, the
**Information** member of the [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure is set to the number of bytes written. Otherwise, the
**Information** member is set to zero.

When the [IOCTL_VPCI_WRITE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_write_block) IOCTL is issued, the driver of the PCIe physical function (PF) is notified to write the data to the specified VF configuration block.

**Note** The operating system reserves and manages the resources that are required for the successful completion of this IOCTL.

A VF configuration block is used for backchannel communication between the drivers of the PCIe PF and a VF on a device that supports the SR-IOV interface. The PF driver allocates a configuration block for each VF within unused blocks of the device's PCI configuration space.

As soon as the VF configuration block is allocated, VF configuration data can be exchanged in a protected manner between the following drivers:

* The VF driver, which runs in the guest operating system. This operating system runs within a Hyper-V child partition.
* The PF driver, which runs in the management operating system.

  This operating system runs within the Hyper-V parent partition.

The usage of the VF configuration block and the format of its configuration data are defined by the independent hardware vendor (IHV) of the device. The configuration data is used only by the drivers of the PF and VF.

**Note** The [IOCTL_VPCI_WRITE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ni-vpci-ioctl_vpci_write_block) IOCTL offers an asynchronous alternative to the [WriteVfConfigBlock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh451609(v=vs.85)) routine.

## See also

[IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

[WriteVfConfigBlock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh451609(v=vs.85))

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[VPCI_WRITE_BLOCK_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vpci/ns-vpci-_vpci_write_block_input)

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)