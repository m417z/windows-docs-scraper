# EVT_SERCX2_CONTROL callback function

## Description

The *EvtSerCx2Control* event callback function is called by version 2 of the serial framework extension (SerCx2) to handle a serial I/O control request.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller. The serial controller driver created this object in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. For more information, see [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice).

### `Request` [in]

A WDFREQUEST handle to the framework request object that represents the serial I/O control request.

### `OutputBufferLength` [in]

The length, in bytes, of the output buffer for the serial I/O control request specified by the *Request* parameter.

### `InputBufferLength` [in]

The length, in bytes, of the input buffer for the serial I/O control request specified by the *Request* parameter.

### `IoControlCode` [in]

Specifies the I/O control code (IOCTL) from the serial I/O control request specified by the *Request* parameter. The IOCTLs for serial I/O control requests are defined in the Ntddser.h header file. For more information, see Remarks.

## Return value

The *EvtSerCx2Control* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code.

## Remarks

Your serial controller driver must implement this function. The driver registers the function in the call to the [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) method that finishes the initialization of the framework device object for the serial controller.

The *EvtSerCx2Control* function lets your driver handle certain serial I/O control requests that SerCx2 cannot handle. SerCx2 handles all processing for a subset of the serial IOCTLs that are defined in the Ntddser.h header file. However, SerCx2 relies on the driver to handle serial I/O control requests to perform hardware-dependent operations.

When SerCx2 receives a serial I/O control request that can be handled only by the serial controller driver, SerCx2 calls the *EvtSerCx2Control* function to hand off the I/O control request to the driver. The driver is responsible for completing this request. A driver that does not implement support for a particular I/O control request should complete this I/O control request with the STATUS_NOT_SUPPORTED error status code.

To complete the I/O control request, the driver typically calls the [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) method and supplies, as input parameters, the *Request* parameter value and a status value to indicate whether the request was successful. This status value is written to the status block of the request.

The *EvtSerCx2Control* function's return value should always match the status value that this function writes to the status block of the I/O control request. The current implementation of SerCx2 ignores this return value.

SerCx2 calls the *EvtSerCx2Control* function to handle the IOCTLs shown in the following table. The column on the right side of the table indicates whether the *EvtSerCx2Control* function is required to implement support for a particular IOCTL.

| I/O control request name | Required or optional |
| --- | --- |
| [IOCTL_SERIAL_CLR_DTR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_clr_dtr) | Optional |
| [IOCTL_SERIAL_CLR_RTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_clr_rts) | Required |
| [IOCTL_SERIAL_GET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_baud_rate) | Required |
| [IOCTL_SERIAL_GET_COMMSTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_commstatus) | Required |
| [IOCTL_SERIAL_GET_DTRRTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_dtrrts) | Required |
| [IOCTL_SERIAL_GET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_handflow) | Required |
| [IOCTL_SERIAL_GET_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_line_control) | Required |
| [IOCTL_SERIAL_GET_MODEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_modem_control) | Required |
| [IOCTL_SERIAL_GET_MODEMSTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_modemstatus) | Required |
| [IOCTL_SERIAL_GET_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_properties) | Required |
| [IOCTL_SERIAL_SET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_baud_rate) | Required |
| [IOCTL_SERIAL_SET_BREAK_OFF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_break_off) | Required |
| [IOCTL_SERIAL_SET_BREAK_ON](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_break_on) | Required |
| [IOCTL_SERIAL_SET_DTR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_dtr) | Optional |
| [IOCTL_SERIAL_SET_FIFO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_fifo_control) | Optional |
| [IOCTL_SERIAL_SET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_handflow) | Required |
| [IOCTL_SERIAL_SET_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_line_control) | Required |
| [IOCTL_SERIAL_SET_MODEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_modem_control) | Required |
| [IOCTL_SERIAL_SET_RTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_rts) | Required |

The preceding table lists all of the serial IOCTLs that SerCx2 presents to the *EvtSerCx2Control* function. For any IOCTL not in this list, SerCx2 either handles the IOCTL, or immediately fails the IOCTL and sets the request status to STATUS_NOT_SUPPORTED. SerCx2 handles [IOCTL_SERIAL_APPLY_DEFAULT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_apply_default_configuration) requests, but calls the [EvtSerCx2ApplyConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_apply_config) event callback function during the processing of such a request. SerCx2 handles [IOCTL_SERIAL_PURGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_purge) requests, but might call the [EvtSerCx2PurgeFifos](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_purge_fifos) event callback function during the processing of such a request. SerCx does preliminary processing of [IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask) requests, but calls the [EvtSerCx2SetWaitMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_set_wait_mask) event callback function, if it is implemented, to finish handling such a request. For more information about SerCx2 support for serial IOCTLs, see [Serial I/O Request Interface](https://learn.microsoft.com/previous-versions/dn265347(v=vs.85)).

#### IOCTL_SERIAL_CLR_DTR and IOCTL_SERIAL_SET_DTR

If the *EvtSerCx2Control* function in your serial controller driver supports the **IOCTL_SERIAL_SET_DTR** request, this function should also support the **IOCTL_SERIAL_CLR_DTR** request, and vice versa. If your driver does not support these two requests, the driver's handler for the **IOCTL_SERIAL_GET_DTRRTS** request should set the SERIAL_DTR_STATE flag bit in the output value for this request to zero.

#### IOCTL_SERIAL_GET_DTRRTS

The *EvtSerCx2Control* function in your serial controller driver must support the **IOCTL_SERIAL_GET_DTRRTS** request, but the driver's handler for this request is required to support only the SERIAL_RTS_STATE flag bit in the output value for this request. As an option, the driver can additionally support the SERIAL_DTR_STATE flag bit. If the SERIAL_DTR_STATE flag bit is not supported, set this bit to zero.

#### IOCTL_SERIAL_GET_COMMSTATUS

The *EvtSerCx2Control* function in your serial controller driver must support the **IOCTL_SERIAL_GET_COMMSTATUS** request, but the driver's handler for this request is required to support only the following members of the [SERIAL_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_status) structure used by this request:

* **Errors**
* **HoldReasons**

As an option, the driver can additionally support any of the other members of this structure. Set all unsupported members to zero.

#### IOCTL_SERIAL_GET_PROPERTIES

The *EvtSerCx2Control* function in your serial controller driver must support the **IOCTL_SERIAL_GET_PROPERTIES** request. The driver's handler for this request should set the **MaxBaud** member of the [SERIAL_COMMPROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_commprop) structure used by this request to the maximum supported baud rate, expressed in bits per second (bps). For example, if the serial controller supports a maximum baud rate of 115,200 bps, the driver sets **MaxBaud** = 115200.

#### IOCTL_SERIAL_GET_MODEMSTATUS

The *EvtSerCx2Control* function in your serial controller driver must support the **IOCTL_SERIAL_GET_MODEMSTATUS** request. The driver's handler for this request should set the request's output value to the raw modem status register value read from the serial controller hardware.

#### IOCTL_SERIAL_GET_HANDFLOW and IOCTL_SERIAL_SET_HANDFLOW

The *EvtSerCx2Control* function in your serial controller driver must support the **IOCTL_SERIAL_GET_HANDFLOW** and **IOCTL_SERIAL_SET_HANDFLOW** requests, but is required to support only a subset of the flag bits that are defined for these requests. Flag bits are defined for the **ControlHandShake** and **FlowReplace** members of the [SERIAL_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_handflow) structure that is used by these requests.

Your driver must support the following flag bit in the **ControlHandshake** member:

* SERIAL_CTS_HANDSHAKE

As an option, a driver can support any of the other flag bits that are defined for the **ControlHandshake** member.

Your driver must support the following flag bits in the **FlowReplace** member:

* SERIAL_RTS_CONTROL
* SERIAL_RTS_HANDSHAKE

As an option, a driver can support any of the other flag bits that are defined for the **FlowReplace** member. However, these other flag bits are rarely, if ever, needed, and Microsoft recommends against supporting them.

A driver that does not support a particular flag bit in the **ControlHandShake** or **FlowReplace** member should set this flag bit to zero in the output value for the **IOCTL_SERIAL_GET_HANDFLOW** request. If an **IOCTL_SERIAL_SET_HANDFLOW** request specifies a **ControlHandshake** or **FlowReplace** flag bit that the driver does not support, the *EvtSerCx2Control* function should fail the request and return STATUS_INVALID_PARAMETER.

As an option, a driver can support the **XonLimit** and **XoffLimit** members of the **SERIAL_HANDFLOW** structure. However, these members are rarely, if ever, needed, and Microsoft recommends against supporting them. A driver that does not support the **XonLimit** and **XoffLimit** members should set these members to zero in the output value for the **IOCTL_SERIAL_GET_HANDFLOW** request. If an **IOCTL_SERIAL_SET_HANDFLOW** request specifies a nonzero **XonLimit** or **XoffLimit** member and the driver does not support these members, the *EvtSerCx2Control* function should fail the request and return STATUS_NOT_IMPLEMENTED.

#### Examples

To define an *EvtSerCx2Control* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2Control* callback function that is named `MyControl`, use the **EVT_SERCX2_CONTROL** function type, as shown in this code example:

```cpp
EVT_SERCX2_CONTROL  MyControl;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MyControl(
    WDFDEVICE  Device,
    WDFREQUEST  Request,
    size_t  OutputBufferLength,
    size_t  InputBufferLength,
    ULONG  IoControlCode
    )
  {...}
```

The **EVT_SERCX2_CONTROL** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_CONTROL** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[EvtSerCx2ApplyConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_apply_config)

[EvtSerCx2PurgeFifos](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_purge_fifos)

[EvtSerCx2SetWaitMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_set_wait_mask)

[SERIAL_COMMPROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_commprop)

[SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports)

[SERIAL_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_handflow)

[SERIAL_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_status)

[SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice)