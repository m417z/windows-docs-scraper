# WDF_MEMORY_DESCRIPTOR_INIT_HANDLE function

## Description

[Applies to KMDF and UMDF]

The **WDF_MEMORY_DESCRIPTOR_INIT_HANDLE** function initializes a [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure so that it describes a specified framework memory object.

## Parameters

### `Descriptor` [out]

A pointer to a [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure.

### `Memory` [in]

A handle to a framework memory object.

### `Offsets` [in, optional]

A pointer to a [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure. This parameter is optional and can be **NULL**.

## Remarks

The **WDF_MEMORY_DESCRIPTOR_INIT_HANDLE** function zeros the specified [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure and sets the structure's **Type** member to **WdfMemoryDescriptorTypeHandle**. Then it sets the structure's **u.HandleType.Memory** and **u.HandleType.Offsets** members to the values that the *Memory* and *Offsets* parameters specify, respectively.

#### Examples

The following code example obtains a handle to a framework memory object that represents an I/O request's input buffer. The example uses the memory object handle to initialize a [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure. Then, the example initializes a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure and sends a USB control transfer request to an I/O target.

```cpp
WDFMEMORY  memory;
WDF_MEMORY_DESCRIPTOR  memDesc;
WDF_USB_CONTROL_SETUP_PACKET  controlSetupPacket;
NTSTATUS  status;

status = WdfRequestRetrieveInputMemory(
                                       Request,
                                       &memory
                                       );
if (!NT_SUCCESS(status)) {
    break;
}
WDF_MEMORY_DESCRIPTOR_INIT_HANDLE(
                                  &memDesc,
                                  memory,
                                  NULL
                                  );

WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR(
                                         &controlSetupPacket,
                                         BmRequestHostToDevice,
                                         BmRequestToDevice,
                                         USBFX2LK_SET_BARGRAPH_DISPLAY,
                                         0,
                                         0
                                         );

status = WdfUsbTargetDeviceSendControlTransferSynchronously(
                                  pDevContext->UsbDevice,
                                  NULL,
                                  NULL,
                                  &controlSetupPacket,
                                  &memDesc,
                                  (PULONG)&bytesTransferred
                                  );
```

## See also

[WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset)

[WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor)

[WDF_MEMORY_DESCRIPTOR_INIT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdf_memory_descriptor_init_buffer)

[WDF_MEMORY_DESCRIPTOR_INIT_MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdf_memory_descriptor_init_mdl)