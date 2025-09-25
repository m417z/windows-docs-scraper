# _WDF_DEVICE_IO_TYPE enumeration (wudfddi_types.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_DEVICE_IO_TYPE** enumeration is used to specify a method for [accessing data buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

## Constants

### `WdfDeviceIoUndefined`

Reserved for system use.

### `WdfDeviceIoNeither`

Reserved for system use.

### `WdfDeviceIoBuffered`

UMDF and the driver use [buffered I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) to access data buffers.

### `WdfDeviceIoDirect`

UMDF and the driver use [direct I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) to access data buffers.

### `WdfDeviceIoBufferedOrDirect`

UMDF and the driver can use either buffered I/O or direct I/O to access data buffers.

### `WdfDeviceIoMaximum`

Reserved for system use.

## Remarks

The **WDF_DEVICE_IO_TYPE** enumeration is used as input to [IWDFDeviceInitialize2::SetIoTypePreference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize2-setiotypepreference) and as output from [IWDFIoRequest2::GetEffectiveIoType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-geteffectiveiotype).

You should use the following guidelines when choosing an I/O type for your driver:

* Buffered I/O provides the best security and reliability, because applications and drivers access separate copies of the data. In addition, buffered I/O provides the best performance if most of the data transfers are relatively small (typically two memory pages or less).
* Direct I/O provides the best performance if most I/O requests transfer large amounts of data. However, applications and drivers access a single copy of the data. Therefore, the driver must copy application-specified parameters to local driver memory before it validates the parameters to ensure that the application does not modify the parameters after validation. If the driver must validate large amounts of application data, buffered I/O might be a better choice because the driver does not have to copy the data before validating it.
* Typically, a filter driver that can reside in several driver stacks and performs little processing of application data can support both buffered I/O and direct I/O and therefore can specify **WdfDeviceIoBufferedOrDirect**. However, if the driver validates application-specified parameters it must copy them first when direct I/O is used.

For more information about accessing an I/O request's data buffers, see [Accessing Data Buffers in UMDF-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

For the KMDF version of this enumeration, see [WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type).

## See also

[IWDFDeviceInitialize2::SetIoTypePreference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize2-setiotypepreference)

[IWDFIoRequest2::GetEffectiveIoType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-geteffectiveiotype)

[WDF_DEVICE_IO_BUFFER_RETRIEVAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_device_io_buffer_retrieval)