# IWDFDevice::ConfigureRequestDispatching

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **ConfigureRequestDispatching** method configures the queuing of I/O requests of the specified type to the specified I/O queue.

## Parameters

### `pQueue` [in]

A pointer to the [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue) interface for the I/O queue to configure.

### `RequestType` [in]

A [WDF_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type)-typed value that identifies the request type to be queued. The only valid **WDF_REQUEST_TYPE** values are **WdfRequestCreate**, **WdfRequestRead**, **WdfRequestWrite**, and **WdfRequestDeviceIoControl**.

### `Forward` [in]

A BOOL value that specifies whether requests of the specified type are queued. **TRUE** indicates to enable queuing requests; **FALSE** indicates to disable queuing requests.

## Return value

**ConfigureRequestDispatching** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## See also

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[WDF_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type)