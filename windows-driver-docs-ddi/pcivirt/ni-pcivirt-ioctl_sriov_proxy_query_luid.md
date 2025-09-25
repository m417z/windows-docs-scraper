# IOCTL_SRIOV_PROXY_QUERY_LUID IOCTL

## Major Code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

## Description

This request supplies the local unique
identifier of the SR_IOV device implementing the interface.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

### Input buffer

**NULL**. No input buffer is required for this operation.

### Input buffer length

Zero.

### Output buffer

A pointer to a [SRIOV_PROXY_QUERY_LUID_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_proxy_query_luid_output) structure that is filled with the identifier.

### Output buffer length

The size of the [SRIOV_PROXY_QUERY_LUID_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_proxy_query_luid_output) structure

### Input/output buffer

Not used with this operation; set this parameter to **NULL**.

### Input/output buffer length

Not used with this operation; set this parameter to zero.

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This IOCTL request is sent by the virtualization stack to the PCI Express SR-IOV Physical Function (PF) driver that exposes GUID_DEVINTERFACE_VIRTUALIZABLE_DEVICE.

This IOCTL request originates in the user mode and is handled by the physical function (PF) driver in order to supply the local unique
identifier of the physical device. This request is only required for SR-IOV devices doing direct assignment.

Before sending this request, the user mode application must obtain a handle to the PCI Express SR-IOV device by querying for GUID_DEVINTERFACE_VIRTUALIZABLE_DEVICE.

In this example, the PF driver generates a unique identifier by calling [ZwAllocateLocallyUniqueId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwallocatelocallyuniqueid) and stores it in the device context.

```cpp
    case IOCTL_SRIOV_PROXY_QUERY_LUID:

        status = WdfRequestRetrieveOutputBuffer(Request,
                                                sizeof(LUID),
                                                &luid,
                                                NULL);
        if (!NT_SUCCESS(status))
        {
            break;
        }

        RtlCopyMemory(luid, &deviceContext->Luid, sizeof(LUID));
        WdfRequestSetInformation(Request, sizeof(LUID));
        status = STATUS_SUCCESS;
        break;

```

## See also

- [SRIOV_PROXY_QUERY_LUID_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_proxy_query_luid_output)