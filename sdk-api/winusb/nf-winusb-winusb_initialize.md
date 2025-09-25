# WinUsb_Initialize function

## Description

The **WinUsb_Initialize** function creates a WinUSB handle for the device specified by a file handle.

## Parameters

### `DeviceHandle` [in]

The handle to the device that **CreateFile** returned. WinUSB uses overlapped I/O, so FILE_FLAG_OVERLAPPED must be specified in the *dwFlagsAndAttributes* parameter of **CreateFile** call for *DeviceHandle* to have the characteristics necessary for **WinUsb_Initialize** to function properly.

### `InterfaceHandle` [out]

Receives an opaque handle to the first (default) interface on the device. This handle is required by other WinUSB routines that perform operations on the default interface. To release the handle, call the [WinUSB_Free](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_free) function.

## Return value

**WinUsb_Initialize** returns **TRUE** if the operation succeeds. Otherwise, this routine returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** or an invalid handle in the *DeviceHandle* parameter; FILE_FLAG_OVERLAPPED was not set in the file handle. |
| **ERROR_NOT_ENOUGH_MEMORY** | Indicates that there is insufficient memory to perform the operation. |
| **ERROR_BAD_DEVICE** | Indicates that the default interface descriptor could not be found for the device. |

## Remarks

When **WinUsb_Initialize** is called,
the policy settings of the interface are reset to the default values.

The **WinUsb_Initialize** call queries the underlying USB stack for various descriptors and allocates enough memory to store the retrieved descriptor data.

**WinUsb_Initialize** first retrieves the device descriptor and then gets the associated configuration descriptor. From the configuration descriptor, the call derives the associated interface descriptors and stores them in an array. The interfaces in the array are identified by zero-based indexes. An index value of 0 indicates the first interface (the default interface), a value of 1 indicates the second associated interface, and so on.
**WinUsb_Initialize** parses the default interface descriptor for the endpoint descriptors and caches information such as the associated pipes or state specific data.
The handle received in the *InterfaceHandle* parameter is a pointer to the memory block allocated for the first interface in the array.

If an application wants to use another interface on the device, it must call [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface), specify the index of the interface, and retrieve a handle to the memory block allocated for the specified interface.

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUSB_Free](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_free)