# IWDFDevice2::RegisterRemoteInterfaceNotification

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RegisterRemoteInterfaceNotification** method registers a driver to receive a notification when a specified [device interface](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers) becomes available.

## Parameters

### `pDeviceInterfaceGuid` [in]

A pointer to a GUID that identifies a device interface.

### `IncludeExistingInterfaces` [in]

A Boolean value. If the driver sets this value to **TRUE**, the framework notifies the driver if the specified device interface becomes available after the driver calls **RegisterRemoteInterfaceNotification**, and it also notifies the driver if the device interface was available before the driver called **RegisterRemoteInterfaceNotification**.

If the driver sets this value to **FALSE**, the framework notifies the driver only if the device interface becomes available after the driver calls **RegisterRemoteInterfaceNotification**.

## Return value

**RegisterRemoteInterfaceNotification** returns S_OK of the operation succeeds. Otherwise, this method returns another value that Winerror.h contains.

## Remarks

Your driver can call **RegisterRemoteInterfaceNotification** only if the callback interface that the driver previously passed to [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) supports the [IPnpCallbackRemoteInterfaceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackremoteinterfacenotification) interface.

For more information, see [Using Device Interfaces in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

#### Examples

The following code example shows how an [IDriverEntry::OnDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-idriverentry-ondeviceadd) callback function can register for notification of the arrival of a device interface.

```
HRESULT
CMyDriver::OnDeviceAdd(
    __in IWDFDriver  *FxDriver,
    __in IWDFDeviceInitialize  *FxDeviceInit
    )
{
    CComPtr<IWDFDevice> fxDevice;
    HRESULT hr;

    //
    // Create a device object and obtain the IWDFDevice interface.
    //
    hr = FxDriver->CreateDevice(FxDeviceInit,
                                MyDeviceIUnknown,
                                &fxDevice);
    if (FAILED(hr)) goto Error;

    //
    // Obtain the IWDFDevice2 interface from IWDFDevice.
    //
    CComPtr<IWDFDevice2> fxDevice2;
    if (FAILED(hr)) goto Error;
    hr = fxDevice->QueryInterface(IID_PPV_ARGS(&fxDevice2));
    if (S_OK != hr) goto Error;
    //
    // Register for notification when a device interface
    // arrives.
    //
    hr = fxDevice2->RegisterRemoteInterfaceNotification(&GUID_DEVINTERFACE_TOASTER,
                                                        true);
...
}
```

## See also

[IPnpCallbackRemoteInterfaceNotification::OnRemoteInterfaceArrival](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackremoteinterfacenotification-onremoteinterfacearrival)

[IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2)