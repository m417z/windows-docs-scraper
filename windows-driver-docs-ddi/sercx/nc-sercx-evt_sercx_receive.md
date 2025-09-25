# EVT_SERCX_RECEIVE callback function

## Description

The *EvtSerCxReceive* event callback function prepares the serial controller device (UART) to do a read (receive) operation.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `Length` [in]

The number of bytes to be received. The controller driver can use this value as a hint to decide whether to use PIO or DMA to perform the data transfer.

## Return value

The *EvtSerCxReceive* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code.

## Remarks

The serial framework extension (SerCx) calls this function to configure the controller hardware to receive data. If necessary, the *EvtSerCxReceive* function can enable interrupts.

The *EvtSerCxReceive* function does not necessarily read the input data from the receive FIFO buffer. Depending on the serial controller hardware or the type of transfer, this function might set up a DMA operation to read the data, or it might schedule a transmit/receive DPC function to read the data. The serial controller driver implements this DPC function to receive data from the controller and to transmit data to the serial controller. During the DPC, the DPC function determines whether data is available to be received and, if so, uses PIO to read the data from the receive FIFO in the serial controller.

If the receive FIFO in the serial controller is empty or nearly empty, but the FIFO's high-water-mark interrupt is enabled, the DPC routine can simply return. Later, the controller driver's ISR can schedule the DPC routine to run, and this routine can read more data from the receive FIFO.

To register an *EvtSerCxReceive* callback function, the controller driver calls the [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method during the [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback.

#### Examples

The function type for this callback is declared in Sercx.h, as follows.

```cpp
typedef NTSTATUS
  EVT_SERCX_RECEIVE(
    __in WDFDEVICE Device
    );
```

To define an *EvtSerCxReceive* callback function that is named `MyEvtSerCxReceive`, you must first provide a function declaration that [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as follows.

```cpp
EVT_SERCX_RECEIVE MyEvtSerCxReceive;
```

Then, implement your callback function as follows.

```cpp
NTSTATUS
  MyEvtSerCxReceive(
    __in WDFDEVICE Device
    )
{ ... }
```

For more information about SDV requirements for function declarations, see [Declaring Functions Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize)

[WdfDpcEnqueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpcenqueue)