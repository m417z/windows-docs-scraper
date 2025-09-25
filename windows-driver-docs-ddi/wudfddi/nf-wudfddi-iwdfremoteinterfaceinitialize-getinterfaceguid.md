# IWDFRemoteInterfaceInitialize::GetInterfaceGuid

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetInterfaceGuid** method retrieves the GUID that identifies a [device interface](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

## Parameters

### `pDeviceInterfaceGuid` [out]

A pointer to a driver-allocated GUID structure that receives the device interface GUID.

## Remarks

For more information about the **GetInterfaceGuid** method, see [Using Device Interfaces in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

#### Examples

The following code example shows how a driver's [IPnpCallbackRemoteInterfaceNotification::OnRemoteInterfaceArrival](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackremoteinterfacenotification-onremoteinterfacearrival) callback function can obtain the GUID that identifies the device interface that has arrived.

```
void
STDMETHODCALLTYPE
CMyDevice::OnRemoteInterfaceArrival(
    __in IWDFRemoteInterfaceInitialize  *FxRemoteInterfaceInit
    )
{
    GUID DeviceInterfaceGUID;
    FxRemoteInterfaceInit->GetInterfaceGuid(&DeviceInterfaceGUID);
...
}
```

## See also

[IWDFRemoteInterfaceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremoteinterfaceinitialize)

[IWDFRemoteInterfaceInitialize::RetrieveSymbolicLink](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremoteinterfaceinitialize-retrievesymboliclink)