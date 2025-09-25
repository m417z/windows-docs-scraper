# IWDFIoQueue::RetrieveNextRequestByFileObject

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

The **RetrieveNextRequestByFileObject** method retrieves from an I/O queue the next I/O request whose file object matches the specified file object.

## Parameters

### `pFile` [in]

A pointer to the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface for the file object that is used to retrieve the next I/O request whose file object matches this supplied file object.

### `ppRequest` [out]

A pointer to a buffer that receives a pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface for the next request object whose file object matches the supplied file object, or receives **NULL** if the queue is empty or if the next request is not found.

## Return value

**RetrieveNextRequestByFileObject** returns one of the following values:

| Return code | Description |
|--|--|
| **S_OK** | The next I/O request was successfully retrieved from the I/O queue. |
| **HRESULT_FROM_NT(STATUS_WDF_PAUSED)** | The queue is not dispatching requests. This situation occurs if the device undergoes a power state transition and all of the queues are stopped from dispatching requests or if the driver explicitly called IWDFIoQueue::Stop to stop dispatching requests. This situation can also occur if the driver attempts to remove a request from a manual queue that is power managed and that is powered down or if the queue is paused. |
| **HRESULT_FROM_WIN32(ERROR_NO_MORE_ITEMS)** | No requests were in the queue. |
| **HRESULT_FROM_NT(STATUS_INVALID_DEVICE_STATE)** | The call was made to retrieve the request from a parallel queue. |

**RetrieveNextRequestByFileObject** might also return other HRESULT values.

## Remarks

If a driver configures an I/O queue for manual dispatching of I/O requests, the driver can call the **RetrieveNextRequestByFileObject** method to obtain the next request whose file object matches the supplied file object from the queue. For more information about manually dispatching I/O requests, see [Configuring Dispatch Mode for an I/O Queue](https://learn.microsoft.com/windows-hardware/drivers/wdf/configuring-dispatch-mode-for-an-i-o-queue).

If multiple I/O requests whose file objects match the file object that the *pFile* parameter points to exist in the I/O queue, the first I/O request is returned.

### Examples

For a code example of how to use the **RetrieveNextRequestByFileObject** method, see [IWDFIoQueue::RetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-retrievenextrequest).

## See also

- [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile)
- [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)
- [IWDFIoQueue::RetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-retrievenextrequest)
- [IWDFIoQueue::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-stop)
- [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)