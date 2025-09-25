# IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX IOCTL

## Description

The **IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX** request retrieves information about a USB port and the device that is attached to the port, if there is one.

Client drivers must send this IOCTL at an IRQL of PASSIVE_LEVEL.

**IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX** is a user-mode I/O control request. This request targets the USB hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

Both input and output buffers point to a caller-allocated [USB_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex) structure.
On input, the **ConnectionIndex** member of this structure must contain a number greater than or equal to 1 that indicates the number of the port whose connection information is to be reported. The hub driver returns connection information in the remaining members of **USB_NODE_CONNECTION_INFORMATION_EX**.
The IRP, the **AssociatedIrp.SystemBuffer** member points to the **USB_NODE_CONNECTION_INFORMATION_EX** structure.

On output, the [USB_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex) structure receives information about the indicated connection from the USB hub driver.

### Input/output buffer length

The size of a [USB_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex) structure.

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## Remarks

Here is an example that shows how to get the speed of the hub port by sending this request.

The function specifies the symbolic link to hub device and port index to query. On return, pPortSpeed indicates:
- Port speed
- SPEED_PATHERROR: if unable to open path.
- SPEED_IOCTLERROR: Hub IOCTL failed.

```
void GetPortSpeed(const WCHAR *Path, ULONG PortIndex, UCHAR *pPortSpeed)

{
    if (Path == NULL) { return; }

    HANDLE handle = CreateFile(
                            Path,
                            GENERIC_WRITE | GENERIC_READ,
                            FILE_SHARE_WRITE | FILE_SHARE_READ,
                            NULL,
                            OPEN_EXISTING,
                            NULL,
                            NULL
                        );

    if (handle == INVALID_HANDLE_VALUE)
    {
      *pPortSpeed = SPEED_PATHERROR;
      return;
    }

    PUSB_NODE_CONNECTION_INFORMATION_EX ConnectionInfo =
                    (PUSB_NODE_CONNECTION_INFORMATION_EX)
                    malloc(sizeof(USB_NODE_CONNECTION_INFORMATION_EX));

    ConnectionInfo->ConnectionIndex = PortIndex;

    ULONG bytes = 0;
    BOOL success = DeviceIoControl(handle,
                              IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX,
                              ConnectionInfo,
                              sizeof(USB_NODE_CONNECTION_INFORMATION_EX),
                              ConnectionInfo,
                              sizeof(USB_NODE_CONNECTION_INFORMATION_EX),
                              &bytes,
                              NULL);

    CloseHandle(handle);

    if (success == FALSE)
    {
      *pPortSpeed = SPEED_IOCTLERROR;
    }
    else
    {
      *pPortSpeed = (UCHAR)ConnectionInfo->Speed;
    }

    free(ConnectionInfo);
}

```

## See also

[USB_NODE_CONNECTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information)

[USB_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex)