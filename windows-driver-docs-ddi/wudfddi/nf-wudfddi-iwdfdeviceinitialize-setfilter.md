# IWDFDeviceInitialize::SetFilter

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetFilter** method sets the property that enables a device as a filter device.

## Remarks

A filter driver calls **SetFilter** to mark itself as a filter. When you tell the framework that your driver is a filter, the framework:

* Sends I/O requests for which the filter has not registered a callback to the next logical driver in the stack. For example, your filter driver provides an [IQueueCallbackDeviceIoControl::OnDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdeviceiocontrol-ondeviceiocontrol) method, but not [IQueueCallbackRead::OnRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackread-onread) or [IQueueCallbackWrite::OnWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackwrite-onwrite). As a result, your filter driver receives only device I/O control requests.
* Automatically forwards file create, cleanup, and close requests so your driver does not need to call the [IWDFDeviceInitialize::AutoForwardCreateCleanupClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-autoforwardcreatecleanupclose) method.

A driver typically calls **SetFilter** from its [IDriverEntry::OnDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-idriverentry-ondeviceadd) method.

#### Examples

For a code example of how to use the **SetFilter** method, see [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice).

## See also

[IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)