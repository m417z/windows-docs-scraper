# EVT_SERCX_FILEOPEN callback function

## Description

The *EvtSerCxFileOpen* event callback function notifies the serial controller driver that a client opened a file handle on the serial controller device and that a file object has been created to represent the device.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

## Return value

The *EvtSerCxFileOpen* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code.

## Remarks

The serial framework extension (SerCx) calls this function to prepare the serial controller hardware to accept requests for I/O operations. This function should configure the controller in a state in which it is ready to receive and transmit data. If interrupts are required, this function should enable interrupts. In addition, this function should allocate any memory that is required only during the lifetime of the file object. For example, this function can allocate an interrupt data buffer.

To register an *EvtSerCxFileOpen* callback function, the driver must call the [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method.

For more information, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

#### Examples

The function type for this callback is declared in Sercx.h, as follows.

```cpp
typedef NTSTATUS
  EVT_SERCX_FILEOPEN(
    __in WDFDEVICE Device
    );
```

To define an *EvtSerCxFileOpen* callback function that is named `MyEvtSerCxFileOpen`, you must first provide a function declaration that [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as follows.

```cpp
EVT_SERCX_FILEOPEN MyEvtSerCxFileOpen;
```

Then, implement your callback function as follows.

```cpp
NTSTATUS
  MyEvtSerCxFileOpen(
    __in WDFDEVICE Device
    )
{ ... }
```

For more information about SDV requirements for function declarations, see [Declaring Functions Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).

## See also

[SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize)