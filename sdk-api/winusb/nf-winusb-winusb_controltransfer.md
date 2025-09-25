# WinUsb_ControlTransfer function

## Description

The **WinUsb_ControlTransfer** function transmits control data over a default control endpoint.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to an interface in the selected configuration.

To specify the recipient of a control request as the entire device or the first interface, use the handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). For all other interfaces, obtain the handle to the target interface by calling [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface), and then call **WinUsb_ControlTransfer** by specifying the obtained interface handle.

### `SetupPacket` [in]

The 8-byte setup packet of type [WINUSB_SETUP_PACKET](https://learn.microsoft.com/windows/desktop/api/winusb/ns-winusb-winusb_setup_packet).

### `Buffer` [out]

A caller-allocated buffer that contains the data to transfer. The length of this buffer must not exceed 4KB.

### `BufferLength` [in]

The number of bytes to transfer, not including the setup packet. This number must be less than or equal to the size, in bytes, of *Buffer*.

### `LengthTransferred` [out, optional]

A pointer to a ULONG variable that receives the actual number of transferred bytes. If the application does not expect any data to be transferred during the
data phase (*BufferLength* is zero), *LengthTransferred* can be **NULL**.

### `Overlapped` [in, optional]

An optional pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure, which is used for asynchronous operations. If this parameter is specified, **WinUsb_ControlTransfer** immediately returns, and the event is signaled when the operation is complete. If *Overlapped* is not supplied, the **WinUsb_ControlTransfer** function transfers data synchronously.

## Return value

**WinUsb_ControlTransfer** returns **TRUE** if the operation succeeds. Otherwise, this routine returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |
| **ERROR_NOT_ENOUGH_MEMORY** | Indicates that there is insufficient memory to perform the operation. |

## Remarks

A control request is always sent by the host to the default endpoint of a USB device but the recipient of the request can be the entire device, an interface, or an endpoint in the selected alternate setting. In the **WinUsb_ControlTransfer** call, the application must indicate the recipient through two parameters: *InterfaceHandle* and *SetupPacket*.

If the recipient of a control request is the entire device, the first interface, or any endpoint in that interface, the application must use the handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). If the recipient is any other interface or its endpoint, then the application must obtain the WinUSB handle that is associated with the target interface by calling [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface), and then call **WinUsb_ControlTransfer** by specifying the obtained interface handle.

As per Section 9.3 of the official USB specification, the setup token of a control transfer contains information about the request. For a WinUSB application, that setup token is described by using the [WINUSB_SETUP_PACKET](https://learn.microsoft.com/windows/desktop/api/winusb/ns-winusb-winusb_setup_packet) structure.

Within the setup token, **bmRequestType** and **wIndex** fields are used to indicate the recipient of the request. Those fields correspond to **RequestType** and **Index** members of [WINUSB_SETUP_PACKET](https://learn.microsoft.com/windows/desktop/api/winusb/ns-winusb-winusb_setup_packet), respectively.

The lowest two bits of **RequestType** indicate the recipient of the request. The recipient can be the device, an interface, endpoint, or other (for vendor request). Depending on the recipient, the lower byte of **Index** indicates the device-defined index of the recipient. The value of **Index** depends on the type of request. For example, for standard control requests, the value is 0, or indicates the interface or endpoint number. For certain types of standard requests, such as a GET_DESCRIPTOR request to obtain a string descriptor, the **Index** value indicates the Language ID.

If the recipient is the device, the application must set **RequestType** and **Index** values. The lowest two bits of **RequestType** value must be 0. The lower byte of **Index** value depends on the type of request. The *InterfaceHandle* must be the WinUSB handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize).

If the recipient of the request is an interface, the application must set the lowest two bits of **RequestType** to 0x01. The application is not required to set the lower byte of **Index** for any type of request. For standard, class, and vendor requests, Winusb.sys sets the value to the interface number of the target interface. The *InterfaceHandle* must be associated with the target interface. The application can obtain that handle by calling [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

If the recipient is an endpoint, the application must set the lowest two bits of **RequestType** to 0x02 and lower byte of Index to the endpoint address. In this case, *InterfaceHandle* is associated with the interface that contains the endpoint. The application can obtain that handle by calling [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

## See also

[WINUSB_SETUP_PACKET](https://learn.microsoft.com/windows/desktop/api/winusb/ns-winusb-winusb_setup_packet)

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)