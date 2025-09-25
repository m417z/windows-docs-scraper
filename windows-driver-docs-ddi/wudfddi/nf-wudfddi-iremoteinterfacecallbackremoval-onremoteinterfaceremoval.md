# IRemoteInterfaceCallbackRemoval::OnRemoteInterfaceRemoval

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A UMDF-based driver's **OnRemoteInterfaceRemoval** event callback function notifies the driver that it cannot use a [device interface](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers) because the interface has been removed.

## Parameters

### `pWdfRemoteInterface` [in]

A pointer to the [IWDFRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremoteinterface) interface of a remote interface object that represents a device interface. The driver obtains this pointer when it calls [IWDFDevice2::CreateRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremoteinterface).

## Remarks

A driver's **OnRemoteInterfaceRemoval** event callback function must do whatever driver-specific tasks are necessary to handle removal of the device interface. In addition, the callback must delete the remote interface object that [IWDFDevice2::CreateRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremoteinterface) created and call the interface's **Release** function if it has previously called the interface's **AddRef** function.

If the driver does not provide this callback function, the framework deletes the remote interface object that [IWDFDevice2::CreateRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremoteinterface) created.

For more information about a driver's **OnRemoteInterfaceRemoval** event callback function, see [Using Device Interfaces in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

## See also

[IPnpCallbackRemoteInterfaceNotification::OnRemoteInterfaceArrival](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackremoteinterfacenotification-onremoteinterfacearrival)

[IRemoteInterfaceCallbackEvent::OnRemoteInterfaceEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iremoteinterfacecallbackevent-onremoteinterfaceevent)

[IRemoteInterfaceCallbackRemoval](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iremoteinterfacecallbackremoval)