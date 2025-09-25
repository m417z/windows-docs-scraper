# EVT_SERCX_TRANSMIT callback function

## Description

The *EvtSerCxTransmit* event callback function prepares the serial controller device (UART) to do a write (transmit) operation.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `Length` [in]

The number of bytes to be transmitted. The controller driver can use this value as a hint to decide whether to use PIO or DMA to perform the data transfer.

## Return value

The *EvtSerCxTransmit* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code.

## Remarks

The serial framework extension (SerCx) calls this function to configure the serial controller hardware to transmit data. If necessary, the *EvtSerCxTransmit* function can enable interrupts.

The *EvtSerCxTransmit* function does not necessarily write the output data to the transmit FIFO buffer. Depending on the serial controller hardware or the type of transfer, this function might set up a DMA operation to write the data, or it might schedule a transmit/receive DPC function to write the data. The serial controller driver implements this DPC function to transmit data to the serial controller and to receive data from the controller. During the DPC, the DPC function determines whether data is available to be transmitted and, if so, uses PIO to transfer the data to the transmit FIFO in the serial controller.

If the transmit FIFO in the serial controller is full or nearly full, but the FIFO's low-water-mark interrupt is enabled, the *EvtSerCxTransmit* function can simply return. Later, the controller driver's ISR can schedule the transmit/receive DPC function to run, and this function can transfer more output data to the transmit FIFO.

To register an *EvtSerCxTransmit* callback function, the controller driver calls the [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method during the [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback.

#### Examples

The function type for this callback is declared in Sercx.h, as follows.

```cpp
typedef NTSTATUS
  EVT_SERCX_TRANSMIT(
    __in WDFDEVICE Device
    );
```

To define an *EvtSerCxTransmit* callback function that is named `MyEvtSerCxTransmit`, you must first provide a function declaration that [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as follows.

```cpp
EVT_SERCX_TRANSMIT MyEvtSerCxTransmit;
```

Then, implement your callback function as follows.

```cpp
NTSTATUS
  MyEvtSerCxTransmit(
    __in WDFDEVICE Device
    )
{ ... }
```

For more information about SDV requirements for function declarations, see [Declaring Functions Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize)

[WdfDpcEnqueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpcenqueue)