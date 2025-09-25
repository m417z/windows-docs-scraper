# IWDFDevice3::GetHardwareRegisterMappedAddress

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A driver calls **GetHardwareRegisterMappedAddress** to get the user-mode mapped address of the memory resource it earlier mapped using [MapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-mapiospace).

## Parameters

### `PseudoBaseAddress` [in]

A pointer to the pseudo base address returned by a previous call to [MapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-mapiospace).

## Return value

User-mode base address of the resources mapped earlier using [MapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-mapiospace).

## Remarks

After the driver calls **GetHardwareRegisterMappedAddress**, it can access the user-mode address directly to read and write to the register.

**Note** This is not the recommended approach for accessing registers because it prevents UMDF from doing any validation on the access.

For more information, see [Reading and Writing to Device Registers in UMDF 1.x Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/reading-and-writing-to-device-registers-in-umdf-1-x-drivers).

If you do use **GetHardwareRegisterMappedAddress**, you must set the **UmdfRegisterAccessMode** INF directive to **RegisterAccessUsingUserModeMapping**. For more information about UMDF INF directives, see [Specifying WDF Directives in INF Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-wdf-directives-in-inf-files).

## See also

[IWDFDevice3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice3)