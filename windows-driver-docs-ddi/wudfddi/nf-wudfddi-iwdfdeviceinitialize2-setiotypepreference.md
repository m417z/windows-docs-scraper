# IWDFDeviceInitialize2::SetIoTypePreference

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetIoTypePreference** method specifies your preferences for how UMDF and the driver access the data buffers of a device's I/O requests.

## Parameters

### `RetrievalMode` [in]

A [WDF_DEVICE_IO_BUFFER_RETRIEVAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_device_io_buffer_retrieval)-typed value that specifies the buffer retrieval mode that you prefer UMDF to use to make an I/O request's buffers available to the driver.

### `ReadWritePreference` [in]

A [WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)-typed value that specifies the buffer access method that you prefer UMDF to use for the data buffers of read and write requests.

### `IoControlPreference` [in]

A WDF_DEVICE_IO_TYPE-typed value that specifies the buffer access method that you prefer UMDF to use for the data buffers of device I/O control requests.

## Remarks

If a driver calls **SetIoTypePreference** for a device, it must do so from its [IDriverEntry::OnDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-idriverentry-ondeviceadd) callback function, before the driver calls [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice).

If the driver does not call **SetIoTypePreference**, UMDF sets the *RetrievalMode* parameter to **WdfDeviceIoBufferRetrievalCopyImmediately** and it sets the buffer access method to **WdfDeviceIoBuffered** for read, write, and device I/O control requests.

UMDF might not use the preferences that the driver specifies when it calls **SetIoTypePreference**. For more information about how UMDF chooses a retrieval mode and buffer access method, see [Specifying a Buffer Retrieval Mode](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) and [How UMDF Chooses a Buffer Access Method for an I/O Request](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

A driver cannot set the buffer access method to **WdfDeviceIoDirect** or **WdfDeviceIoBufferedOrDirect** unless it also sets the *RetrievalMode* parameter to **WdfDeviceIoBufferRetrievalDeferred**.

For more information about accessing an I/O request's data buffers, see [Accessing Data Buffers in UMDF-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

The following code example shows a segment of a driver's [IDriverEntry::OnDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-idriverentry-ondeviceadd) callback function. The segment obtains the [IWDFDeviceInitialize2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize2) interface and then calls **SetIoTypePreference**.

```
HRESULT
 CMyDriver::OnDeviceAdd(
    __in IWDFDriver *FxWdfDriver,
    __in IWDFDeviceInitialize *FxDeviceInit
    )
{
...
    //
    // Declare an IWDFDeviceInitialize2 interface pointer and obtain the
    // IWDFDeviceInitialize2 interface from the IWDFDeviceInitialize interface.
    //
    CComQIPtr<IWDFDeviceInitialize2> di2 = FxDeviceInit;

    //
    // For this device, set the retrieval mode to deferred, set
    // the access method to buffered for read and write requests,
    // and set the access mode to direct for device I/O control requests.
    //
    di2->SetIoTypePreference(WdfDeviceIoBufferRetrievalDeferred,
                             WdfDeviceIoBuffered,
                             WdfDeviceIoDirect);
...
}
```

## See also

[IWDFDeviceInitialize2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize2)

[IWDFIoRequest2::GetEffectiveIoType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-geteffectiveiotype)

[WDF_DEVICE_IO_BUFFER_RETRIEVAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_device_io_buffer_retrieval)

[WDF_DEVICE_IO_TYPE (UMDF)](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_device_io_type)

[WdfDeviceInitSetIoType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotype)

[WdfDeviceInitSetIoTypeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotypeex)