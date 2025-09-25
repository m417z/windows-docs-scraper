# WinUsb_GetAssociatedInterface function

## Description

The **WinUsb_GetAssociatedInterface** function retrieves a handle for an associated interface. This is a synchronous operation.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to the first (default) interface on the device, which is returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize).

### `AssociatedInterfaceIndex` [in]

An index that specifies the associated interface to retrieve. A value of 0 indicates the first associated interface, a value of 1 indicates the second associated interface, and so on.

### `AssociatedInterfaceHandle` [out]

A handle for the associated interface. Callers must pass this interface handle to [WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist) exposed by Winusb.dll. To close this handle, call [WinUsb_Free](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_free).

## Return value

**WinUsb_GetAssociatedInterface** returns **TRUE** if the operation succeeds. Otherwise, this routine returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

| Return code | Description |
| --- | --- |
| **ERROR_ALREADY_EXISTS** | [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface) has already returned a handle for the interface that *AssociatedInterfaceIndex* specifies. |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |
| **ERROR_INVALID_PARAMETER** | The passed *AssociatedInterfaceIndex* value failed an integer overflow check. |
| **ERROR_NO_MORE_ITEMS** | An interface does not exist for the specified *AssociatedInterfaceIndex* value*.* |
| **ERROR_NOT_ENOUGH_MEMORY** | Indicates that there is insufficient memory to perform the operation. |

## Remarks

The **WinUsb_GetAssociatedInterface** routine retrieves an opaque handle.

The *first associated interface* is the interface that immediately follows the interface whose handle the [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize) routine retrieves.

The handle that **WinUsb_GetAssociatedInterface** returns must be released by calling [WinUsb_Free](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_free).

Callers of **WinUsb_GetAssociatedInterface** can retrieve only one handle for each interface. If a caller attempts to retrieve more than one handle for the same interface, the routine will fail with an error of ERROR_ALREADY_EXISTS.

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)