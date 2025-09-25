# IWDFDevice::GetDefaultIoQueue

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetDefaultIoQueue** method retrieves the interface of the default I/O queue for a device.

## Parameters

### `ppWdfIoQueue` [out]

A pointer to a variable that receives a pointer to the [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue) interface for the default I/O queue object.

## Remarks

For more information about queue objects, see [Framework I/O Queue Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-i-o-queue-object).

## See also

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)