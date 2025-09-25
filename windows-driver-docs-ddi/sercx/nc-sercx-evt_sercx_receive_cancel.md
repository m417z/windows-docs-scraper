# EVT_SERCX_RECEIVE_CANCEL callback function

## Description

The *EvtSerCxReceiveCancel* event callback function notifies the serial controller driver that the pending receive request is canceled.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

## Remarks

The serial framework extension (SerCx) calls this function to inform the serial controller driver that the current receive request has been canceled. If the driver has an outstanding receive operation in progress, the driver should cancel this operation and call the [SerCxProgressReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogressreceive) method to report the cancellation. In the **SerCxProgressReceive** call, set *BytesReceived* to the number of bytes received before the operation was canceled, and set *ReceiveStatus* to **SerCxStatusCancelled**.

To register an *EvtSerCxReceiveCancel* callback function, the driver must call the [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method.

#### Examples

The function type for this callback is declared in Sercx.h, as follows.

```cpp
typedef VOID
  EVT_SERCX_RECEIVE_CANCEL(
    __in WDFDEVICE Device
    );
```

To define an *EvtSerCxReceiveCancel* callback function that is named `MyEvtSerCxReceiveCancel`, you must first provide a function declaration that [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as follows.

```cpp
EVT_SERCX_RECEIVE_CANCEL MyEvtSerCxReceiveCancel;
```

Then, implement your callback function as follows.

```cpp
VOID
  MyEvtSerCxReceiveCancel(
    __in WDFDEVICE Device
    )
{ ... }
```

For more information about SDV requirements for function declarations, see [Declaring Functions Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).

## See also

[SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize)

[SerCxProgressReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogressreceive)