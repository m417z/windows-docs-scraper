# WDF_REQUEST_SEND_OPTIONS_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_SEND_OPTIONS_INIT** function initializes a driver's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure.

## Parameters

### `Options` [out]

A pointer to a caller-supplied [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure.

### `Flags` [in]

A bitwise OR of [WDF_REQUEST_SEND_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_send_options_flags)-typed flags.

## Remarks

The **WDF_REQUEST_SEND_OPTIONS_INIT** function zeros the specified [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure, sets the structure's **Size** member, and sets the **Flag** member to the specified *Flags* value.

#### Examples

The following code example initializes a [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure and then calls [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend).

```cpp
WDF_REQUEST_SEND_OPTIONS options;
BOOLEAN ret;

WDF_REQUEST_SEND_OPTIONS_INIT(
                              &options,
                              WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET
                              );

ret = WdfRequestSend(
                     Request,
                     Target,
                     &options
                     );
```

## See also

[WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options)

[WDF_REQUEST_SEND_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_send_options_flags)

[WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_send_options_set_timeout)