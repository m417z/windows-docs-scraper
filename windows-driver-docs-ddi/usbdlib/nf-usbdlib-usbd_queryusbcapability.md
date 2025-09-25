# USBD_QueryUsbCapability function

## Description

The **USBD_QueryUsbCapability** routine is called by a WDM client driver to determine whether the underlying USB driver stack and the host controller hardware support a specific capability. **Note for Windows Driver Framework (WDF) Drivers:** If your client driver is a WDF-based driver, then you must call the [WdfUsbTargetDeviceQueryUsbCapability](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicequeryusbcapability) method instead of **USBD_QueryUsbCapability**.

## Parameters

### `USBDHandle` [in]

USBD handle that is retrieved by the client driver in a previous call to the [USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle) routine.

### `CapabilityType` [in]

Pointer to a GUID that represents the capability for which the client driver wants to retrieve information. The possible *PGUID* values are as follows:

* GUID_USB_CAPABILITY_CHAINED_MDLS
* GUID_USB_CAPABILITY_STATIC_STREAMS
* GUID_USB_CAPABILITY_SELECTIVE_SUSPEND
* GUID_USB_CAPABILITY_FUNCTION_SUSPEND
* GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE
* GUID_USB_CAPABILITY_DEVICE_CONNECTION_SUPER_SPEED_COMPATIBLE
* GUID_USB_CAPABILITY_TIME_SYNC

### `OutputBufferLength` [in]

Length, in bytes, of the buffer pointed to by *OutputBuffer*.

### `OutputBuffer` [in, out]

Pointer to a caller-allocated buffer. Certain capability requests return additional information in an output buffer. For those requests, you must allocate the buffer and provide a pointer to the buffer in the *OutputBuffer* parameter. Currently, only the static-streams capability request requires an output buffer of the type USHORT. The buffer is filled by **USBD_QueryUsbCapability** with the maximum number of streams supported per endpoint.

Other capability requests do not require an output buffer. For those requests, you must set *OutputBuffer* to NULL and *OutputBufferLength* to 0.

### `ResultLength` [out, optional]

Pointer to a ULONG variable that receives the actual number of bytes in the buffer pointed to by *OutputBuffer*. The caller can pass NULL in *ResultLength*. If *ResultLength* is not NULL, the received value is less than or equal to the *OutputBufferLength* value.

## Return value

The **USBD_QueryUsbCapability** routine returns an NT status code.

Possible values include, but are not limited to, the status codes listed in the following table.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The request was successful and the specified capability is supported. |
| **STATUS_INVALID_PARAMETER** | The caller passed an invalid parameter value.<br><br>* *USBDHandle* or *CapabilityType* is NULL.<br>* *OutputBuffer* is NULL but *OutputBufferLength* indicates a nonzero value. Conversely, the caller provided an output buffer but the buffer length is 0. |
| **STATUS_NOT_IMPLEMENTED** | The specified capability is not supported by the underlying USB driver stack. |
| **STATUS_NOT_SUPPORTED** | The specified capability is not supported either by the host controller hardware or the USB driver stack. |

## Remarks

Windows 8 includes a new USB driver stack to support USB 3.0 devices. The new USB driver stack provides several new capabilities defined such as, stream support and chained MDLs that can be used by a client driver.

A client driver can determine the version of the underlying USB driver stack by calling the [IsInterfaceVersionSupported](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isinterfaceversionsupported) routine.

The client driver can use the new capabilities *only if* the underlying USB driver stack *and* hardware support them. For example, in order to send I/O requests to a particular stream associated with a bulk endpoint, the underlying USB driver stack, the endpoint, and the host controller hardware must support the static streams capability. The client driver *must not* call [IsInterfaceVersionSupported](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isinterfaceversionsupported) and assume the capabilities of the driver stack. Instead, the client driver *must* always call **USBD_QueryUsbCapability** to determine whether the USB driver stack and hardware support a particular capability.

The following table describes the USB-specific capabilities that a client driver can query through a **USBD_QueryUsbCapability** call.

| Capability GUID | Description |
| --- | --- |
| GUID_USB_CAPABILITY_CHAINED_MDLS | If the USB driver stack supports chained MDLs, the client driver can provide the transfer data as a chain of MDLs that reference segmented buffers in physical memory. For more information, see [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl). Chained MDLs preclude the need for allocating and copying memory to create virtually contiguous buffers and therefore make I/O transfers more efficient. For more information, see [How to Send Chained MDLs](https://learn.microsoft.com/windows-hardware/drivers/ddi/). |
| GUID_USB_CAPABILITY_STATIC_STREAMS | If supported, the client driver can send I/O requests to streams in a bulk endpoint.<br><br>For the static streams query request, the client driver is required to provide an output buffer (USHORT). After the call completes and if the static streams capability is supported, the output buffer receives the maximum number of supported streams by the host controller. <br><br>The output buffer value does not indicate the maximum number of streams supported by the bulk endpoint in the device. To determine that number, the client driver must inspect the endpoint companion descriptor.<br><br>The USB driver stack in Windows 8 supports up to 255 streams. <br><br>If static streams are supported, the client driver can send I/O requests to the first stream (also called the *default stream*) by using the pipe handle obtained through a select-configuration request. For other streams in the endpoint, the client driver must open those streams and obtain pipe handles for them in order to send I/O requests. For more information about opening streams, see [How to Open and Close Static Streams in a USB Bulk Endpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/). |
| GUID_USB_CAPABILITY_FUNCTION_SUSPEND | This capability determines whether the underlying USB driver stack supports USB Function Suspend and Remote Wake-Up features. If supported, the driver stack can process a resume signal (for remote wake-up) from an individual function in a USB 3.0 composite device. Based on that signal, an individual function driver can exit the low-power state of its function.<br><br>The capability is intended to be used by a composite driver: the driver that is loaded as the function device object (FDO) in the device stack for the composite device. By default, the Microsoft-provided USB Generic Parent Driver (Usbccgp.sys) is loaded as the FDO. <br><br>If your driver replaces Usbccgp.sys, the driver must be able to request remote wake-up and propagate the resume signal from the USB driver stack. Before implementing that logic, the driver must determine the USB driver stack's support for the function suspend capability by calling **USBD_QueryUsbCapability**. Usbccgp.sys in Windows 8 implements function suspend.<br><br>For a code example and more information about function suspend, see [How to Implement Function Suspend in a Composite Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/). |
| GUID_USB_CAPABILITY_SELECTIVE_SUSPEND | Determines whether the underlying USB driver stack supports selective suspend.<br><br>For information about selective suspend, see [USB Selective Suspend](https://learn.microsoft.com/windows-hardware/drivers/ddi/). |
| GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE | Determines whether the bus is operating at high-speed or higher. |
| GUID_USB_CAPABILITY_DEVICE_CONNECTION_SUPER_SPEED_COMPATIBLE | Determines whether the bus is operating at SuperSpeed or higher. |
| GUID_USB_CAPABILITY_TIME_SYNC | Determines whether the frame number and QPC association feature is supported on the controller. |

#### Examples

The code snippet shows how to call **USBD_QueryUsbCapability** to determine the capabilities of the underlying USB driver stack.

```cpp

/*++

Routine Description:
This helper routine queries the underlying USB driver stack
for specific capabilities. This code snippet assumes that
USBD handle was retrieved by the client driver in a
previous call to the USBD_CreateHandle routine.

Parameters:

fdo: Pointer to the device object that is the current top
of the stack as reported by IoAttachDeviceToDeviceStack.

Return Value: VOID
--*/

VOID QueryUsbDriverStackCaps (PDEVICE_OBJECT fdo)
{
    NTSTATUS ntStatus = STATUS_SUCCESS;
    PDEVICE_EXTENSION deviceExtension;

    deviceExtension = (PDEVICE_EXTENSION)fdo->DeviceExtension;

    if (!deviceExtension->UsbdHandle)
    {
        return;
    }

    // Check if the underlying USB driver stack
    // supports USB 3.0 devices.

    if (!USBD_IsInterfaceVersionSupported(
        deviceExtension->UsbdHandle,
        USBD_INTERFACE_VERSION_602))
    {
        KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "Old USB stack loaded.\n" ));
    }
    else
    {
        // Call USBD_QueryUsbCapability to determine
        // function suspend support.
        KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "New USB stack loaded.\n" ));
        ntStatus = USBD_QueryUsbCapability ( deviceExtension->UsbdHandle,
            (GUID*)&GUID_USB_CAPABILITY_FUNCTION_SUSPEND,
            0,
            NULL,
            NULL);

        if (NT_SUCCESS(ntStatus))
        {
            deviceExtension->FunctionSuspendSupported = TRUE;
            KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "Function suspend supported.\n" ));
        }
        else
        {
            deviceExtension->FunctionSuspendSupported  = FALSE;
            ntStatus = STATUS_SUCCESS;
            KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "Function suspend not supported.\n" ));
        }
    }

    // Call USBD_QueryUsbCapability to determine
    // chained MDL support.

    ntStatus = USBD_QueryUsbCapability(
        deviceExtension->UsbdHandle,
        (GUID*)&GUID_USB_CAPABILITY_CHAINED_MDLS,
        0,
        NULL,
        NULL);

    if (NT_SUCCESS(ntStatus))
    {
        deviceExtension->ChainedMDLSupport = TRUE;
        KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "Chained MDLs supported.\n" ));
    }
    else
    {
        deviceExtension->ChainedMDLSupport = FALSE;
        ntStatus = STATUS_SUCCESS;
        KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "Chained MDLs not supported.\n" ));
    }

    // Call USBD_QueryUsbCapability to determine
    // stream support.

    ntStatus = USBD_QueryUsbCapability (deviceExtension->UsbdHandle,
        (GUID*)&GUID_USB_CAPABILITY_STATIC_STREAMS,
        sizeof(ULONG),
        (PUCHAR) &deviceExtension->MaxSupportedStreams,
        NULL);

    if (!NT_SUCCESS(ntStatus))
    {
        deviceExtension->MaxSupportedStreams = 0;
        ntStatus = STATUS_SUCCESS;
        KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "Static streams not supported.\n" ));
    }

    // Call USBD_QueryUsbCapability to determine
    // selective suspend support.

    ntStatus = USBD_QueryUsbCapability (deviceExtension->UsbdHandle,
        (GUID*)&GUID_USB_CAPABILITY_SELECTIVE_SUSPEND,
        0,
        NULL,
        NULL);

    if (!NT_SUCCESS(ntStatus))
    {
        ntStatus = STATUS_SUCCESS;
        KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "Selective suspend not supported.\n" ));
    }
    else
    {
        KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "Selective suspend supported.\n" ));
    }

    // Call USBD_QueryUsbCapability to determine
    // device speed.
    ntStatus = USBD_QueryUsbCapability (deviceExtension->UsbdHandle,
        (GUID*)&GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE,
        0,
        NULL,
        NULL);

    if (!NT_SUCCESS(ntStatus))
    {
        ntStatus = STATUS_SUCCESS;
        KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "The device is operating at full speed or lower.\n The device can operate at high speed or higher." ));
    }
    else
    {
        KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "The device is operating at high speed or higher.\n" ));
    }

    // Call USBD_QueryUsbCapability to determine
    // device speed.
    ntStatus = USBD_QueryUsbCapability (deviceExtension->UsbdHandle,
        (GUID*)&GUID_USB_CAPABILITY_DEVICE_CONNECTION_SUPER_SPEED_COMPATIBLE,
        0,
        NULL,
        NULL);

    if (!NT_SUCCESS(ntStatus))
    {
        ntStatus = STATUS_SUCCESS;
        KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "The device is operating at high speed or lower.\n The device can operate at Superspeed or higher." ));
    }
    else
    {
        KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "The device is operating at SuperSpeed or higher.\n" ));
    }

    return;

}

```

## See also

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)