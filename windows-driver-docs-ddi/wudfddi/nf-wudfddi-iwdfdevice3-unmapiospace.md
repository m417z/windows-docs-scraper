# IWDFDevice3::UnmapIoSpace

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **UnmapIoSpace** method unmaps a specified range of physical addresses previously mapped by [MapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-mapiospace) method.

## Parameters

### `PseudoBaseAddress` [in]

Pointer to the pseudo base address obtained from a previous call to [MapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-mapiospace) method to which the physical address range was mapped.

### `NumberOfBytes` [in]

Specifies the number of bytes that were mapped.

## Remarks

If a driver calls [MapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-mapiospace) in [OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onpreparehardware) callback. It calls **UnmapIoSpace** in its [OnReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onreleasehardware) callback.

For an example, see [Finding and Mapping Hardware Resources in a UMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/finding-and-mapping-hardware-resources-in-umdf-1-x-drivers).

#### Examples

See example code in [IWDFDevice3::MapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-mapiospace).

## See also

[IWDFDevice3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice3)