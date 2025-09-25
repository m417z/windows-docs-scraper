# EVT_SERCX_CONTROL callback function

## Description

The *EvtSerCxControl* event callback function handles an I/O control request that has an I/O control code (IOCTL) that the serial framework extension (SerCx) supports.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `Request` [in]

A WDFREQUEST handle to the framework request object that represents the I/O control request.

### `OutputBufferLength` [in]

Specifies the length, in bytes, of the output buffer for the I/O control request specified by the *Request* parameter.

### `InputBufferLength` [in]

Specifies the length, in bytes, of the input buffer for the I/O control request specified by the *Request* parameter.

### `IoControlCode` [in]

Specifies the IOCTL from the I/O control request specified by the *Request* parameter.

## Return value

The *EvtSerCxControl* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code. For more information, see the following Remarks section.

## Remarks

The serial controller driver is required to implement this callback function. SerCx calls this function to hand off an I/O control request to the controller driver for processing. Before this function returns, it must complete the request either by performing the requested operation or by returning an error status. A driver that does not implement support for a particular request should return the STATUS_NOT_IMPLEMENTED error status for this request.

Typically, the *EvtSerCxControl* function should synchronize to the controller driver's ISR before this function changes the settings in the hardware registers of the serial controller.

The *EvtSerCxControl* function's return value must match the status value that this function writes to the status block of the I/O control request. SerCx uses the return value to track the state of the controller driver and the serial controller hardware.

The following is a list of the IOCTLs that this callback function must be prepared to handle:

[IOCTL_SERIAL_CLEAR_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_clear_stats)
[IOCTL_SERIAL_CLR_DTR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_clr_dtr)
[IOCTL_SERIAL_CLR_RTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_clr_rts)
[IOCTL_SERIAL_GET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_baud_rate)
[IOCTL_SERIAL_GET_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_chars)
[IOCTL_SERIAL_GET_COMMSTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_commstatus)
[IOCTL_SERIAL_GET_DTRRTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_dtrrts)
[IOCTL_SERIAL_GET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_handflow)
[IOCTL_SERIAL_IMMEDIATE_CHAR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_immediate_char)
[IOCTL_SERIAL_GET_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_line_control)
[IOCTL_SERIAL_GET_MODEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_modem_control)
[IOCTL_SERIAL_GET_MODEMSTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_modemstatus)
[IOCTL_SERIAL_GET_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_properties)
[IOCTL_SERIAL_GET_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_stats)
[IOCTL_SERIAL_LSRMST_INSERT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_lsrmst_insert)
[IOCTL_SERIAL_SET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_baud_rate)
[IOCTL_SERIAL_SET_BREAK_OFF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_break_off)
[IOCTL_SERIAL_SET_BREAK_ON](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_break_on)
[IOCTL_SERIAL_SET_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_chars)
[IOCTL_SERIAL_SET_DTR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_dtr)
[IOCTL_SERIAL_SET_FIFO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_fifo_control)
[IOCTL_SERIAL_SET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_handflow)
[IOCTL_SERIAL_SET_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_line_control)
[IOCTL_SERIAL_SET_MODEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_modem_control)
[IOCTL_SERIAL_SET_RTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_rts)
[IOCTL_SERIAL_SET_XOFF](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_xoff)
[IOCTL_SERIAL_SET_XON](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_xon)
[IOCTL_SERIAL_XOFF_COUNTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_xoff_counter)
To register an *EvtSerCxControl* callback function, the controller driver calls the [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method during the [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback.

#### Examples

The function type for this callback is declared in Sercx.h, as follows.

```cpp
typedef NTSTATUS
  EVT_SERCX_CONTROL(
    __in WDFREQUEST Request,
    __in size_t OutputBufferLength,
    __in size_t InputBufferLength,
    __in ULONG IoControlCode
    );
```

To define an *EvtSerCxControl* callback function that is named `MyEvtSerCxControl`, you must first provide a function declaration that [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as follows.

```cpp
EVT_SERCX_CONTROL MyEvtSerCxControl;
```

Then, implement your callback function as follows.

```cpp
NTSTATUS
  MyEvtSerCxControl(
    __in WDFREQUEST Request,
    __in size_t OutputBufferLength,
    __in size_t InputBufferLength,
    __in ULONG IoControlCode
    )
{ ... }
```

For more information about SDV requirements for function declarations, see [Declaring Functions Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize)