# EVT_SERCX_FILECLOSE callback function

## Description

The *EvtSerCxFileClose* event callback function notifies the serial controller driver that the file object that represents the serial controller device has been released.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

## Remarks

This function should remove the serial controller device from the state in which it is ready to receive and transmit data. This function should disable interrupts if interrupts are enabled. Any memory that is allocated only for the lifetime of the file object should be deallocated either in this function or in the [EvtSerCxFileCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_filecleanup) function.

If the serial controller driver implements an *EvtSerCxFileCleanup* function, the serial framework extension (SerCx) calls this function before it calls the *EvtSerCxFileClose* function. SerCx calls the *EvtSerCxFileCleanup* function when a client closes the last handle to the file object that represents the serial controller device. After this call, the driver receives no new requests for I/O operations. SerCx calls the *EvtSerCxFileClose* function when the file object is released, which occurs only after all outstanding I/O requests are either completed or canceled.

To register an *EvtSerCxFileClose* callback function, the driver must call the [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method.

For more information, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

#### Examples

The function type for this callback is declared in Sercx.h, as follows.

```cpp
typedef VOID
  EVT_SERCX_FILECLOSE(
    __in WDFDEVICE Device
    );
```

To define an *EvtSerCxFileClose* callback function that is named `MyEvtSerCxFileClose`, you must first provide a function declaration that [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as follows.

```cpp
EVT_SERCX_FILECLOSE MyEvtSerCxFileClose;
```

Then, implement your callback function as follows.

```cpp
VOID
  MyEvtSerCxFileClose(
    __in WDFDEVICE Device
    )
{ ... }
```

For more information about SDV requirements for function declarations, see [Declaring Functions Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).

## See also

[EvtSerCxFileCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_filecleanup)

[SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize)