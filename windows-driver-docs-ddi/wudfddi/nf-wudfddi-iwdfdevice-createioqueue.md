# IWDFDevice::CreateIoQueue

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateIoQueue** method configures the default I/O queue that is associated with a device or creates a secondary I/O queue for the device.

## Parameters

### `pCallbackInterface` [in, optional]

A pointer to the **IUnknown** interface that the framework uses to determine the event callback functions that the driver subscribes to on the queue. These are the functions that the framework calls when the relevant events occur.

 For UMDF versions 1.9 and later, this parameter is required for I/O queues that use the sequential or parallel [dispatching method](https://learn.microsoft.com/windows-hardware/drivers/wdf/configuring-dispatch-mode-for-an-i-o-queue), and it is optional (can be **NULL**) for I/O queues that use the manual dispatching method. For UMDF versions earlier than 1.9, this parameter is required for all dispatching methods.

### `bDefaultQueue` [in]

A BOOL value that specifies whether to configure the default I/O queue or create a secondary I/O queue for the device. **TRUE** indicates to configure the default I/O queue; **FALSE** indicates to create a secondary I/O queue.

### `DispatchType` [in]

A [WDF_IO_QUEUE_DISPATCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_dispatch_type)-typed value that identifies how the driver must receive requests from the I/O queue.

### `bPowerManaged` [in]

A BOOL value that specifies whether the I/O queue is power managed. **TRUE** indicates the framework automatically coordinates dispatching for the I/O queue with Plug and Play (PnP) and the power state of the device; **FALSE** indicates no automatically coordinated dispatching.

### `bAllowZeroLengthRequests` [in]

A BOOL value that specifies whether the framework puts zero-length I/O requests directly in the I/O queue for the driver to handle. **TRUE** indicates that the driver should receive read and write requests that have zero-length buffers--that is, the framework automatically puts these request types directly in the I/O queue for the driver. **FALSE** indicates that the framework completes zero-length I/O requests instead of putting them in the I/O queue.

### `ppIoQueue` [out]

A pointer to a variable that receives a pointer to the [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue) interface for the newly created I/O queue object or the default I/O queue object.

## Return value

**CreateIoQueue** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The I/O queue was successfully created. |
| **HRESULT_FROM_WIN32(ERROR_BAD_CONFIGURATION)** | The I/O queue is configured in one of the following ways:<br><br>* The *DispatchType* parameter specifies a nonmanual queue and none of the I/O queue callback interfaces that are specified in the Remarks section are supported through the *pCallbackInterface* parameter.<br>* The *DispatchType* parameter specifies a manual queue and one or more of the I/O queue callback interfaces that are specified in the Remarks section are supported through the *pCallbackInterface* parameter.<br><br>For more information about these configurations, see the Remarks section. |

**CreateIoQueue** might also return other HRESULT values.

## Remarks

The **IUnknown** interface that the driver supplies for the *pCallbackInterface* parameter can support several queue callback functions. The framework calls the **QueryInterface** method on the supplied **IUnknown** interface multiple times to retrieve the interface methods that the driver supports. When applications perform actions that are related to the methods of the supported interfaces (such as, an I/O read request), the framework calls the methods (such as, the [IQueueCallbackRead::OnRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackread-onread) method) to notify the driver. The framework calls **QueryInterface** for the following interfaces:

[IQueueCallbackCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackcreate)

[IQueueCallbackDefaultIoHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackdefaultiohandler)

[IQueueCallbackDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackdeviceiocontrol)

[IQueueCallbackRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackread)

[IQueueCallbackWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackwrite)

When the driver passes either **WdfIoQueueDispatchSequential** or **WdfIoQueueDispatchParallel** for the *DispatchType* parameter of **CreateIoQueue** to create a nonmanual queue, **CreateIoQueue** can return S_OK only if the driver's queue callback object implements at least one of the preceding interfaces and indicates support of such interfaces through the **IUnknown** interface that *pCallbackInterface* points to.

When the driver passes **WdfIoQueueDispatchManual** for *DispatchType* to create a manual queue, **CreateIoQueue** can return S_OK only if the driver's queue callback object does not implement or indicate support of any of the preceding callback interfaces. For more information about the driver's callback objects, see [Creating Callback Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-callback-objects).

**Note** The driver cannot use the same callback object for a manual queue that the driver uses for a sequential or parallel queue. That is, if the driver passes a particular pointer to an **IUnknown** interface in a call to **CreateIoQueue** to create a manual queue, the driver cannot later pass the identical pointer to **IUnknown** in a call to **CreateIoQueue** to create a sequential or parallel queue.

For more information about configuring dispatch mode, see [Configuring Dispatch Mode for an I/O Queue](https://learn.microsoft.com/windows-hardware/drivers/wdf/configuring-dispatch-mode-for-an-i-o-queue).

The framework also calls **QueryInterface** on the supplied **IUnknown** interface to determine if the driver supports any of the following interfaces:

[IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup)

[IQueueCallbackIoResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackioresume)

[IQueueCallbackIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackiostop)

The framework also calls **QueryInterface** on the supplied **IUnknown** interface to determine if the driver supports the [IQueueCallbackStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackstatechange) interface. The driver's queue callback object can optionally implement and indicate support of **IQueueCallbackStateChange** only for a manual queue. The driver's queue callback object must not implement and indicate support of **IQueueCallbackStateChange** for a sequential or parallel queue.

#### Examples

For a code example of how to use the **CreateIoQueue** method, see [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice).

## See also

[IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup)

[IQueueCallbackCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackcreate)

[IQueueCallbackDefaultIoHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackdefaultiohandler)

[IQueueCallbackDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackdeviceiocontrol)

[IQueueCallbackIoResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackioresume)

[IQueueCallbackIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackiostop)

[IQueueCallbackRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackread)

[IQueueCallbackStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackstatechange)

[IQueueCallbackWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackwrite)

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[WDF_IO_QUEUE_DISPATCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_dispatch_type)