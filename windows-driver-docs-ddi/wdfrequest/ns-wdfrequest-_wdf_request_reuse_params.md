# _WDF_REQUEST_REUSE_PARAMS structure

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_REUSE_PARAMS** structure specifies information that is associated with a reused I/O request.

## Members

### `Size`

The size, in bytes, of this structure.

### `Flags`

A bitwise OR of one or more [WDF_REQUEST_REUSE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_reuse_flags)-typed flags.

### `Status`

An NTSTATUS value that the framework assigns to the request.

### `NewIrp`

A pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure. This member's value is optional and can be **NULL**.

## Remarks

The **WDF_REQUEST_REUSE_PARAMS** structure is used as input to [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse).

To initialize this structure, the driver must call [WDF_REQUEST_REUSE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_reuse_params_init). To set a **NewIrp** value in the structure, the driver must call [WDF_REQUEST_REUSE_PARAMS_SET_NEW_IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_reuse_params_set_new_irp) after calling **WDF_REQUEST_REUSE_PARAMS_INIT**.

If a lower driver needs to access the **Status** value, it can find it in the **Irp->IoStatus.Status** field.

You can set a **NewIrp** value only if the I/O request that you supply to [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse) was created by calling [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) or [WdfRequestCreateFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreatefromirp).

## See also

[WDF_REQUEST_REUSE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_reuse_flags)

[WDF_REQUEST_REUSE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_reuse_params_init)

[WDF_REQUEST_REUSE_PARAMS_SET_NEW_IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_reuse_params_set_new_irp)

[WdfRequestCreateFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreatefromirp)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)