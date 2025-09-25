# IWDFDevice::GetDefaultIoTarget

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetDefaultIoTarget** method retrieves the interface of the default I/O target for a device instance.

## Parameters

### `ppWdfIoTarget` [out]

A pointer to a variable that receives a pointer to the [IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget) interface for the default I/O target object.

## Remarks

For more information, see [Initializing a General I/O Target in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/initializing-a-general-i-o-target-in-umdf).

## See also

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget)