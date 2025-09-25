# EVT_SERCX_TRANSMIT_CANCEL callback function

## Description

The *EvtSerCxTransmitCancel* event callback function notifies the serial controller driver that the pending transmit request is canceled.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

## Remarks

The serial framework extension (SerCx) calls this function to inform the serial controller driver that the current transmit request has been canceled. If the driver has an outstanding transmit operation in progress, the driver should cancel this operation and call the [SerCxProgressTransmit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogresstransmit) method to report the cancellation. In the **SerCxProgressTransmit** call, set *BytesTransmitted* to the number of bytes transmitted before the operation was canceled, and set *TransmitStatus* to **SerCxStatusCancelled**.

To register an *EvtSerCxTransmitCancel* callback function, the driver must call the [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method.

#### Examples

The function type for this callback is declared in Sercx.h, as follows.

```cpp
typedef VOID
  EVT_SERCX_TRANSMIT_CANCEL(
    __in WDFDEVICE Device
    );
```

To define an *EvtSerCxTransmitCancel* callback function that is named `MyEvtSerCxTransmitCancel`, you must first provide a function declaration that [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as follows.

```cpp
EVT_SERCX_TRANSMIT_CANCEL MyEvtSerCxTransmitCancel;
```

Then, implement your callback function as follows.

```cpp
VOID
  MyEvtSerCxTransmitCancel(
    __in WDFDEVICE Device
    )
{ ... }
```

For more information about SDV requirements for function declarations, see [Declaring Functions Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).