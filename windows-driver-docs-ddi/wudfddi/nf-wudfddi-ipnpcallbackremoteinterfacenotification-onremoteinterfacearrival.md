# IPnpCallbackRemoteInterfaceNotification::OnRemoteInterfaceArrival

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A driver's **OnRemoteInterfaceArrival** event callback function informs the driver when a [device interface](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers) is available.

## Parameters

### `pWdfRemoteInterfaceInit` [in]

A pointer to the [IWDFRemoteInterfaceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremoteinterfaceinitialize) interface that identifies the device interface that has arrived.

## Remarks

A UMDF-based driver can register its optional **OnRemoteInterfaceArrival** event callback function by calling [IWDFDevice2::RegisterRemoteInterfaceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-registerremoteinterfacenotification).

The driver can use methods of the [IWDFRemoteInterfaceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremoteinterfaceinitialize) interface to determine which device interface has arrived.

Before the driver can send I/O requests to the device interface, the driver must do the following:

1. Call [IWDFDevice2::CreateRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremoteinterface) to create a remote interface object.
2. Call [IWDFDevice2::CreateRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremotetarget) to create a remote target object.
3. Call [IWDFRemoteTarget::OpenRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openremoteinterface) to connect the interface object to the remote target object and open the remote target for I/O operations.

For more information about using remote interface objects to access device interfaces, see [Using Device Interfaces in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers)

## See also

[IPnpCallbackRemoteInterfaceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackremoteinterfacenotification)

[IWDFDevice2::CreateRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremoteinterface)

[IWDFDevice2::CreateRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremotetarget)

[IWDFRemoteInterfaceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremoteinterfaceinitialize)

[IWDFRemoteTarget::OpenRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openremoteinterface)