# IQueueCallbackIoResume::OnIoResume

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnIoResume** method resumes the processing of the specified I/O request from the specified queue.

## Parameters

### `pWdfQueue` [in]

A pointer to the [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue) interface for the I/O queue object that processing of the I/O request is resumed from.

### `pWdfRequest` [in]

A pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface that represents the framework request object that is resumed.

## Remarks

A driver registers the [IQueueCallbackIoResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackioresume) interface when the driver calls the [IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue) method to create an I/O queue or to configure the default I/O queue.

## See also

[IQueueCallbackIoResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackioresume)

[IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue)

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)