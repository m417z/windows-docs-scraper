# WdfDeviceGetHardwareRegisterMappedAddress function

## Description

[Applies to UMDF only]

A driver calls **WdfDeviceGetHardwareRegisterMappedAddress** to get the user-mode mapped address of the memory resource it mapped previously using [WdfDeviceMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicemapiospace).

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PseudoBaseAddress` [in]

The address of a location that receives a pointer to the pseudo base address.

## Return value

User-mode base address of the resources mapped earlier using [WdfDeviceMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicemapiospace).

## Remarks

This function is the UMDF version 2 equivalent of [IWDFDevice3::GetHardwareRegisterMappedAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-gethardwareregistermappedaddress).

After the driver calls **WdfDeviceGetHardwareRegisterMappedAddress**, it can access the user-mode address directly to read and write to the register.

**Note** This is not the recommended approach for accessing registers because it prevents UMDF from doing any validation on the access.

If you do use **WdfDeviceGetHardwareRegisterMappedAddress**, you must set the **UmdfRegisterAccessMode** INF directive to **RegisterAccessUsingUserModeMapping**. For more information about UMDF INF directives, see [Specifying WDF Directives in INF Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-wdf-directives-in-inf-files).

## See also

[IWDFDevice3::GetHardwareRegisterMappedAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-gethardwareregistermappedaddress)

[WdfDeviceMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicemapiospace)