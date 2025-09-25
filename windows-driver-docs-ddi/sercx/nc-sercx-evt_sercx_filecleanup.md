# EVT_SERCX_FILECLEANUP callback function

## Description

The *EvtSerCxFileCleanup* event callback function notifies the serial controller driver that a client has closed the last handle to the file object that represents the serial controller device.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

## Remarks

This function can deallocate certain system resources that the driver previously allocated for the lifetime of the file object. In conjunction with the [EvtSerCxFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_fileclose) function, the *EvtSerCxFileCleanup* function should remove the serial controller device from the state in which it is ready to receive and transmit data. The *EvtSerCxFileCleanup* function should focus specifically on clean-up tasks, such as deallocating memory.

If the serial controller driver previously allocated memory only for the lifetime of the file object that is now closed, the driver should deallocate this memory in either the *EvtSerCxFileCleanup* or *EvtSerCxFileClose* function.

Typically, interrupts should be disabled only after the file object is released. Thus, the *EvtSerCxFileClose* function, and not the *EvtSerCxFileCleanup* function, should disable the interrupts.

SerCx calls a driver's *EvtSerCxFileCleanup* function after the last handle to the file object is closed. Because of outstanding I/O requests, this object might not yet be released. After this call, the driver receives no new requests for I/O operations.

SerCx calls a driver's *EvtSerCxFileClose* function after it calls the driver's *EvtSerCxFileCleanup* function. SerCx calls the *EvtSerCxFileClose* function after the file object is released, which occurs only when all outstanding I/O requests are either completed or canceled.

The *EvtSerCxFileCleanup* function is optional. If a serial controller driver does not implement this function, the driver's *EvtSerCxFileClose* function must handle all clean-up tasks that are required after the last file handle is closed.

To register an *EvtSerCxFileCleanup* callback function, the driver must call the [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method.

For more information, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

#### Examples

The function type for this callback is declared in Sercx.h, as follows.

```cpp
typedef VOID
  EVT_SERCX_FILECLEANUP(
    __in WDFDEVICE Device
    );
```

To define an *EvtSerCxFileCleanup* callback function that is named `MyEvtSerCxFileCleanup`, you must first provide a function declaration that [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as follows.

```cpp
EVT_SERCX_FILECLEANUP MyEvtSerCxFileCleanup;
```

Then, implement your callback function as follows.

```cpp
VOID
  MyEvtSerCxFileCleanup(
    __in WDFDEVICE Device
    )
{ ... }
```

For more information about SDV requirements for function declarations, see [Declaring Functions Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).

## See also

[EvtSerCxFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_fileclose)

[SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize)