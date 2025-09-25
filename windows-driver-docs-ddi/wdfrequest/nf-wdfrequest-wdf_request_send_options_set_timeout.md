# WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT function

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT** function sets a time-out value in a driver's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure.

## Parameters

### `Options` [in, out]

A pointer to the driver's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure.

### `Timeout` [in]

An absolute or relative time-out value. For more information, see the **Timeout** member of the [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure.

## Remarks

To set a time-out value, your driver must call **WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT** after it calls [WDF_REQUEST_SEND_OPTIONS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_send_options_init).

The **WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT** function stores the specified timeout value in the specified [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure's **Timeout** member. It also sets the **WDF_REQUEST_SEND_OPTION_TIMEOUT** flag in the structure's **Flags** member.

#### Examples

The following code example initializes a [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure and sets a time-out value for the structure. (The example calls [WDF_REL_TIMEOUT_IN_SEC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcore/nf-wdfcore-wdf_rel_timeout_in_sec) to specify a relative time-out value of 10 seconds.) The example then uses the **WDF_REQUEST_SEND_OPTIONS** structure as input to [WdfUsbTargetPipeWriteSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipewritesynchronously).

```cpp
WDF_REQUEST_SEND_OPTIONS  syncReqOptions;

WDF_REQUEST_SEND_OPTIONS_INIT(
                              &syncReqOptions,
                              0
                              );
WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT(
                                     &syncReqOptions,
                                     WDF_REL_TIMEOUT_IN_SEC(10)
                                     );
status = WdfUsbTargetPipeWriteSynchronously(
                                            pipeHandle,
                                            NULL,
                                            &syncReqOptions,
                                            &writeBufDesc,
                                            NULL
                                            );
```

## See also

[WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options)

[WDF_REQUEST_SEND_OPTIONS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_send_options_init)