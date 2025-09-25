# WdfDeviceSetAlignmentRequirement function

## Description

[Applies to KMDF only]

The **WdfDeviceSetAlignmentRequirement** method registers the driver's preferred address alignment for the data buffers that the device uses during memory transfer operations.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `AlignmentRequirement` [in]

The hardware-dependent alignment requirement for a data buffer. This value must be one less than the alignment boundary. For example, you can specify 15 for a 16-byte alignment boundary and 31 for a 32-byte alignment boundary. You can also use one of the FILE_*Xxxx*_ALIGNMENT constants that are defined in *Wdm.h*, for example:

```
//
// Define alignment requirement values
//
#define FILE_BYTE_ALIGNMENT             0x00000000
#define FILE_WORD_ALIGNMENT             0x00000001
#define FILE_LONG_ALIGNMENT             0x00000003
#define FILE_QUAD_ALIGNMENT             0x00000007
#define FILE_OCTA_ALIGNMENT             0x0000000f
#define FILE_32_BYTE_ALIGNMENT          0x0000001f
#define FILE_64_BYTE_ALIGNMENT          0x0000003f
#define FILE_128_BYTE_ALIGNMENT         0x0000007f
#define FILE_256_BYTE_ALIGNMENT         0x000000ff
#define FILE_512_BYTE_ALIGNMENT         0x000001ff
```

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

A driver that uses direct I/O can call **WdfDeviceSetAlignmentRequirement** to register a preferred alignment requirement. The alignment applies to I/O requests that go through the I/O Manager, and not those sent to your driver from another driver that calls [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver).

Because the I/O manager does not always use the requested alignment, the driver should be prepared for unaligned buffers.

The driver can call [WdfDeviceGetAlignmentRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetalignmentrequirement) to obtain the current value for the device's alignment requirement.

The I/O manager sets an alignment requirement value for the device when the driver calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about a device's alignment requirement value and when a driver must change the value, see [Initializing a Device Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/initializing-a-device-object) in the WDM documentation.

If your driver specifies an alignment requirement that is greater that the computer's page size (PAGE_SIZE), the logical addresses that the [WdfCommonBufferGetAlignedLogicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedlogicaladdress) method returns are always aligned to the specified alignment requirement, but the virtual addresses that the [WdfCommonBufferGetAlignedVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedvirtualaddress) method returns might not be aligned to the alignment requirement.

If your driver specifies an alignment requirement that is less than the computer's page size, all logical and virtual addresses are aligned to the specified alignment requirement.

For more information about calling **WdfDeviceSetAlignmentRequirement**, see [Enabling DMA Transactions](https://learn.microsoft.com/windows-hardware/drivers/wdf/enabling-dma-transactions) and [Using Common Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-common-buffers).

#### Examples

The following code example is from the [AMCC5933](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. This example checks a device's current alignment requirement and sets the alignment requirement to a new value, if necessary. Note that the exact alignment value is dependent on the hardware.

```cpp
ULONG alignReq;

alignReq = WdfDeviceGetAlignmentRequirement(device);
if (alignReq < AMCC5933_ALIGNMENT__32BITS) {
//
// Set the S5933 alignment requirement to a new value.
//
WdfDeviceSetAlignmentRequirement(
                                 device,
                                 AMCC5933_ALIGNMENT__32BITS
                                 );
}
```

## See also

[WdfCommonBufferGetAlignedLogicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedlogicaladdress)

[WdfCommonBufferGetAlignedVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedvirtualaddress)

[WdfDeviceGetAlignmentRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetalignmentrequirement)