# IRemoteInterfaceCallbackEvent::OnRemoteInterfaceEvent

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A UMDF-based driver's **OnRemoteInterfaceEvent** event callback function handles device events that are associated with a [device interface](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

## Parameters

### `pWdfRemoteInterface` [in]

A pointer to the [IWDFRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremoteinterface) interface of a remote interface object that represents a device interface. The driver obtains this pointer when it calls [IWDFDevice2::CreateRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremoteinterface).

### `EventGuid` [in]

A GUID that identifies the event type. Event GUIDs are defined by the components that support such GUIDs. Some [device interface classes](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) provide event GUIDs, and some driver provide custom events.

### `pbData` [in, optional]

A pointer to a buffer that contains event-specific data. Typically, components that define event GUIDs also define event-specific structures for event buffers.

### `cbDataSize` [in]

The size, in bytes, of the buffer that *pbData* points to.

### `NameBufferOffset` [in]

An offset, in bytes, from the beginning of the buffer that *pbData* points to. Bytes from 0 to *NameBufferOffset*-1 of the buffer contain binary data. Bytes from *NameBufferOffset* to the end of the buffer contain Unicode string data.

## Remarks

A driver's **OnRemoteInterfaceEvent** event callback function handles all device events except arrival and removal events. Such events can originate from a UMDF-based driver's call to [IWDFDevice::PostEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-postevent) or from a kernel-mode driver's call to [IoReportTargetDeviceChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreporttargetdevicechange) or [IoReportTargetDeviceChangeAsynchronous](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreporttargetdevicechangeasynchronous).

The framework begins calling the **OnRemoteInterfaceEvent** event callback function after the driver calls [IWDFRemoteTarget::OpenRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openremoteinterface) and continues to call the callback function until the device interface's [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf) is closed.

For more information about a driver's **OnRemoteInterfaceEvent** event callback function, see [Using Device Interfaces in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

## See also

[IPnpCallbackRemoteInterfaceNotification::OnRemoteInterfaceArrival](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackremoteinterfacenotification-onremoteinterfacearrival)

[IRemoteInterfaceCallbackEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iremoteinterfacecallbackevent)

[IRemoteInterfaceCallbackRemoval::OnRemoteInterfaceRemoval](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iremoteinterfacecallbackremoval-onremoteinterfaceremoval)