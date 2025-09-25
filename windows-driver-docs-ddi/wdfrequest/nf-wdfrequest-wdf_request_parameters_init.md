# WDF_REQUEST_PARAMETERS_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_PARAMETERS_INIT** function initializes a [WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters) structure.

## Parameters

### `Parameters` [out]

A pointer to a caller-supplied [WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters) structure.

## Remarks

Drivers must call **WDF_REQUEST_PARAMETERS_INIT** to initialize a [WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters) structure before calling [WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters).

The **WDF_REQUEST_PARAMETERS_INIT** function zeros the specified [WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters) structure and sets the structure's **Size** member.

#### Examples

The following code example initializes a [WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters) structure and then calls [WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters).

```cpp
VOID
MyEvtIoDefault(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request
    )
{
    WDF_REQUEST_PARAMETERS  params;

    WDF_REQUEST_PARAMETERS_INIT(&params);

    WdfRequestGetParameters(
                            Request,
                            &params
                            );
...
}
```

## See also

[WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters)

[WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters)