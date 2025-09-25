# EVT_SERCX_PURGE callback function

## Description

The *EvtSerCxPurge* event callback function is called by the serial framework extension (SerCx) to purge the serial controller's hardware buffers.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `PurgeMask` [in]

A set of flags that describe the hardware buffers that are to be purged. Currently, no flags are defined for purge operations that are performed by the serial controller. For more information, see Remarks.

## Return value

The *EvtSerCxPurge* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code.

## Remarks

The serial controller driver implements this callback function. SerCx calls this function when a client (application or peripheral driver) sends an [IOCTL_SERIAL_PURGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_purge) control request that requires hardware buffers managed by the serial controller to be purged.

SerCx performs the purge operations that are designated by the flags listed in the following table.

| Flag bit | Meaning |
| --- | --- |
| SERIAL_PURGE_RXABORT | Purge all read requests. |
| SERIAL_PURGE_RXCLEAR | Purge the input buffer, if one exists. Any receive data in this buffer is discarded. |
| SERIAL_PURGE_TXABORT | Purge all write requests. |
| SERIAL_PURGE_TXCLEAR | Purge the output buffer, if one exists. Any transmit data in this buffer is discarded. |

The *EvtSerCxPurge* function will never receive a purge request that contains any of the flags in this table. The SERIAL_PURGE_*XXX* flags are defined in the Ntddser.h header file.

Currently, no SERIAL_PURGE_*XXX* flags are defined to designate purge operations that are performed by the serial controller driver, and the serial controller driver should perform no purge operations in response to a *EvtSerCxPurge* call.

If the **IOCTL_SERIAL_PURGE** control request requires pending read or write requests to be canceled, SerCx cancels these requests before it calls the *EvtSerCxPurge* function.

To register an *EvtSerCxPurge* callback function, the controller driver calls the [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method during the [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback.

#### Examples

The function type for this callback is declared in Sercx.h, as follows.

```cpp
typedef NTSTATUS
  EVT_SERCX_PURGE(
    __in WDFDEVICE Device,
    __in ULONG PurgeMask
    );
```

To define an *EvtSerCxPurge* callback function that is named `MyEvtSerCxPurge`, you must first provide a function declaration that [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as follows.

```cpp
EVT_SERCX_PURGE MyEvtSerCxPurge;
```

Then, implement your callback function as follows.

```cpp
NTSTATUS
  MyEvtSerCxPurge(
    __in WDFDEVICE Device,
    __in ULONG PurgeMask
    )
{ ... }
```

For more information about SDV requirements for function declarations, see [Declaring Functions Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[IOCTL_SERIAL_PURGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_purge)

[SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize)