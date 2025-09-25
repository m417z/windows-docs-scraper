# WDF_REQUEST_REUSE_PARAMS_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_REUSE_PARAMS_INIT** function initializes a driver's [WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params) structure.

## Parameters

### `Params` [out]

A pointer to a caller-supplied [WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params) structure.

### `Flags` [in]

[WDF_REQUEST_REUSE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_reuse_flags)-typed flags.

### `Status` [in]

An NTSTATUS value that the framework assigns to the request.

## Remarks

Before a driver calls the [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse) method, it must call **WDF_REQUEST_REUSE_PARAMS_INIT** to initialize a [WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params) structure.

The **WDF_REQUEST_REUSE_PARAMS_INIT** function zeros the specified [WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params) structure and sets the structures **Size** member. It also sets the structure's **Flags** and **Status** members to the specified values.

For a code example that uses **WDF_REQUEST_REUSE_PARAMS_INIT**, see [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse).

## See also

[WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params)

[WDF_REQUEST_REUSE_PARAMS_SET_NEW_IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_reuse_params_set_new_irp)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)