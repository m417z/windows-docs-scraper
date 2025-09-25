# WDF_REQUEST_REUSE_PARAMS_SET_NEW_IRP function

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_REUSE_PARAMS_SET_NEW_IRP** function sets a new IRP in a driver's [WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params) structure.

## Parameters

### `Params` [in, out]

A pointer to a caller-supplied [WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params) structure.

### `NewIrp` [in]

A pointer to a caller-supplied [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure.

## Remarks

If a driver's call to [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse) specifies a new IRP structure, the driver must first call [WDF_REQUEST_REUSE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_reuse_params_init) and then call **WDF_REQUEST_REUSE_PARAMS_SET_NEW_IRP** to initialize a WDF_REQUEST_REUSE_PARAMS structure.

The **WDF_REQUEST_REUSE_PARAMS_SET_NEW_IRP** function sets the structure's **NewIrp** member to the specified IRP pointer. It also sets the **WDF_REQUEST_REUSE_SET_NEW_IRP** flag in the structure's **Flag** member.

#### Examples

The following code example initializes a [WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params) structure, provides a new IRP structure for the I/O request, and then calls [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse).

```cpp
WDF_REQUEST_REUSE_PARAMS  params;
NTSTATUS  status;
PIRP  myIrp;
...
WDF_REQUEST_REUSE_PARAMS_INIT(
                              &params,
                              WDF_REQUEST_REUSE_NO_FLAGS,
                              STATUS_SUCCESS
                              );
WDF_REQUEST_REUSE_PARAMS_SET_NEW_IRP(
                                     &params,
                                     myIrp
                                     );
status = WdfRequestReuse(
                         Request,
                         &params
                         );
...
```

## See also

[WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params)

[WDF_REQUEST_REUSE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_reuse_params_init)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)