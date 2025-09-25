# IWDFUsbTargetPipe2::ConfigureContinuousReader

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **ConfigureContinuousReader** method configures the framework to continuously read from a USB pipe.

## Parameters

### `TransferLength` [in]

The maximum length, in bytes, of data that can be received from the device.

### `HeaderLength` [in]

An offset, in bytes, into the buffer that receives data from the device. The framework will store data from the device in a read buffer, beginning at the offset value. In other words, this space precedes the *TransferLength*-sized space in which the framework stores data from the device.

### `TrailerLength` [in]

The length, in bytes, of a trailing buffer space. This space follows the *TransferLength*-sized space in which the framework stores data from the device.

### `NumPendingReads` [in]

The number of read requests that the framework will queue to receive data from the I/O target. If this value is zero, the framework uses a default number of read requests. If the specified value is greater than the permitted maximum value, the framework uses the permitted maximum value. For more information about the *NumPendingReads* parameter, see the following Remarks section.

### `pMemoryCleanupCallbackInterface` [in, optional]

A pointer to a driver-supplied **IUnkown** interface that the framework uses to access an optional [IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup) callback function. The framework calls the callback function when it deallocates the read buffer that it creates to handle the continuous read operation. This parameter is optional and can be **NULL**.

### `pOnCompletion` [in]

A pointer to a driver-supplied [IUsbTargetPipeContinuousReaderCallbackReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iusbtargetpipecontinuousreadercallbackreadcomplete) interface that provides an [OnReaderCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadcomplete-onreadercompletion) callback function.

### `pCompletionContext` [in, optional]

An untyped pointer to driver-defined context information that the framework passes to the driver's [IUsbTargetPipeContinuousReaderCallbackReadComplete::OnReaderCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadcomplete-onreadercompletion) callback function.

### `pOnFailure` [in, optional]

A pointer to a driver-supplied [IUsbTargetPipeContinuousReaderCallbackReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iusbtargetpipecontinuousreadercallbackreadersfailed) interface that provides an [OnReaderFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadersfailed-onreaderfailure) callback function.

## Return value

**ConfigureContinuousReader** returns S_OK if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_NT (STATUS_INVALID_DEVICE_STATE)** | The driver has already configured a continuous reader for the USB pipe.<br><br>The USB pipe is not set up for bulk or interrupt input transfers. |
| **E_OUTOFMEMORY** | The framework's attempt to allocate a buffer failed. |
| **ERROR_ARITHMETIC_OVERFLOW** | The *TransferLength*, *HeaderLength*, or *TrailerLength* parameter specified a size that was too large or otherwise invalid. |

This method might return one of the other values that Winerror.h contains.

## Remarks

You can configure a continuous reader for a bulk pipe or an interrupt pipe. The pipe must have an input endpoint.

After calling **ConfigureContinuousReader** to configure a continuous reader, your driver must call [IWDFIoTargetStateManagement::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-start) to start the reader. To stop the reader, the driver must call [IWDFIoTargetStateManagement::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-stop).

Typically, a driver calls **ConfigureContinuousReader** from within its [IPnpCallbackHardware::OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware-onpreparehardware) callback function. The driver should call [IWDFIoTargetStateManagement::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-start) from within its [IPnpCallback::OnD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0entry) callback function and should call [IWDFIoTargetStateManagement::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-stop) from within its [IPnpCallback::OnD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0exit) callback function.

Each time the pipe's I/O target successfully completes a read request, the framework calls the driver's [IUsbTargetPipeContinuousReaderCallbackReadComplete::OnReaderCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadcomplete-onreadercompletion) callback function. If the I/O target reports a failure while processing a request, the framework calls the driver's [IUsbTargetPipeContinuousReaderCallbackReadersFailed::OnReaderFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadersfailed-onreaderfailure) callback function after all read requests have been completed. (Therefore, the **OnReaderCompletion** callback function will not be called while the **OnReaderFailure** callback function is executing.)

Use the following guidelines to choose a value for the *NumPendingReads* parameter:

* Set *NumPendingReads* to zero if you want your driver to use the framework's default value.

  The default value is greater than one and provides reasonably good performance for many devices on many processor configurations.
* Set *NumPendingReads* to one if it is important that your driver receive data buffers in the exact order in which the device delivers the data.

  If the framework queues more than one read request, the driver might not receive the data buffers in same the order in which the device delivers the data.
* Set *NumPendingReads* to a number that meets the performance requirements for your device, based on thorough performance measurements.

  First, test your device with the default value (0) for *NumPendingReads*. Your tests should include various hardware configurations, including different types and numbers of processors, and different USB host controllers and USB configurations. You can then experiment with higher values, using the same tests. A driver that might require a higher value is one for a device that has a high interrupt rate, where data can be lost if interrupts are not serviced rapidly.

A *NumPendingReads* value that is too large can slow down a system's performance. You should use the lowest value that meets your performance requirements. Typically, values that are higher than three or four do not improve data throughput. But higher values might reduce latency, or the chance of missing data, on a high-frequency pipe.

After a driver has called **ConfigureContinuousReader**, the driver cannot use [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) to send I/O requests to the pipe unless the driver's [IUsbTargetPipeContinuousReaderCallbackReadersFailed::OnReaderFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadersfailed-onreaderfailure) callback function is called and returns **FALSE**.

For more information about the **ConfigureContinuousReader** method and USB I/O targets, see [Reading from a UMDF-USB Pipe](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes-in-umdf-1-x-drivers).

#### Examples

The following code example configures a continuous reader. In this example, the maximum buffer size is the size of a driver-defined buffer. The header and trailer buffer offsets are set to zero, and the number of pending read operations is set to two. The example uses the target pipe's interface pointer for the *pCompletionContext* parameter, so the [OnReaderCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadcomplete-onreadercompletion) callback function can determine the pipe on which the read operation was completed.

```
HRESULT hr, hrQI;
IUsbTargetPipeContinuousReaderCallbackReadComplete *pOnCompletionCallback = NULL;
IUsbTargetPipeContinuousReaderCallbackReadersFailed *pOnFailureCallback= NULL;
IWDFUsbTargetPipe2 * pIUsbInterruptPipe2;

//
// Obtain interfaces.
//
hrQI = this->QueryInterface(IID_PPV_ARGS(&pOnCompletionCallback));
if (!SUCCEEDED(hrQI)) goto Error;
hrQI = this->QueryInterface(IID_PPV_ARGS(&pOnFailureCallback));
if (!SUCCEEDED(hrQI)) goto Error;
hrQI = m_pIUsbInterruptPipe->QueryInterface(IID_PPV_ARGS(&pIUsbInterruptPipe2));
if (!SUCCEEDED(hrQI)) goto Error;

//
// Configure the reader.
//
hr = pIUsbInterruptPipe2->ConfigureContinuousReader(
                                                    sizeof(m_MyBuffer),
                                                    0,
                                                    0,
                                                    2,
                                                    NULL,
                                                    pOnCompletionCallback,
                                                    m_pIUsbTargetPipe,
                                                    pOnFailureCallback
                                                    );
...
```

## See also

[IPnpCallback::OnD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0entry)

[IPnpCallback::OnD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0exit)

[IPnpCallbackHardware::OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware-onpreparehardware)

[IUsbTargetPipeContinuousReaderCallbackReadComplete::OnReaderCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadcomplete-onreadercompletion)

[IUsbTargetPipeContinuousReaderCallbackReadersFailed::OnReaderFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadersfailed-onreaderfailure)

[IWDFIoTargetStateManagement::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-start)

[IWDFIoTargetStateManagement::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-stop)

[IWDFUsbTargetPipe2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetpipe2)