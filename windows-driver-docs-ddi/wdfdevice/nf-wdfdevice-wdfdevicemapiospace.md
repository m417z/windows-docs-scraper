# WdfDeviceMapIoSpace function

## Description

[Applies to UMDF only]

The **WdfDeviceMapIoSpace** function maps the given physical address range to system address space and returns a pseudo base address.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PhysicalAddress` [in]

Specifies the starting 64-bit physical address of the I/O range to be mapped.

### `NumberOfBytes` [in]

Specifies a value greater than zero, indicating the number of bytes to be mapped.

### `CacheType` [in]

Specifies a [MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) value, which indicates the cache attribute to use to map the physical address range. The MEMORY_CACHING_TYPE enumeration type is defined in Wdfdevice.h.

### `PseudoBaseAddress` [out]

The address of a location that receives a pointer to the pseudo base address.

## Return value

If the operation succeeds, the function returns STATUS_SUCCESS.

The function might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

This function is the UMDF version 2 equivalent of [IWDFDevice3::MapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-mapiospace).

A driver must call this function during device start-up if it receives translated resources of type **CmResourceTypeMemory** in a [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure. **WdfDeviceMapIoSpace** maps the physical address returned in the resource list to a framework-managed address referred to as the pseudo base address.

 The driver can then use the pseudo base address to access device registers with WDF_READ_REGISTER_*Xxx* and WDF_WRITE_REGISTER_*Xxx* functions.

A driver that calls **WdfDeviceMapIoSpace** must set the **UmdfDirectHardwareAccess** INF directive to **AllowDirectHardwareAccess**.

 If the driver sets the **UmdfRegisterAccessMode** INF directive to **RegisterAccessUsingUserModeMapping**, calling **WdfDeviceMapIoSpace** also maps the given physical address range to a user-mode base address range that the driver can subsequently access by calling [WdfDeviceGetHardwareRegisterMappedAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegethardwareregistermappedaddress).

 For more information about INF directives that UMDF drivers can use, see [Specifying WDF Directives in INF Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-wdf-directives-in-inf-files).

For more information about parsing hardware resources starting in UMDF version 2, see [Handling Hardware Resources in a UMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/finding-and-mapping-hardware-resources).

The PHYSICAL_ADDRESS type is defined in Wudfwdm.h, as follows:

```
typedef LARGE_INTEGER PHYSICAL_ADDRESS;
```

For an example that shows how a driver finds and maps memory-mapped register resources, see [Reading and Writing to Device Registers](https://learn.microsoft.com/windows-hardware/drivers/wdf/reading-and-writing-to-device-registers).

## See also

[IWDFDevice3::MapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-mapiospace)

[WdfDeviceUnmapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceunmapiospace)