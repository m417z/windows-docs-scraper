# IWDFDevice2::CreateRemoteInterface

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateRemoteInterface** method creates a remote interface object that represents a [device interface](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

## Parameters

### `pRemoteInterfaceInit` [in]

A pointer to an [IWDFRemoteInterfaceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremoteinterfaceinitialize) interface that the driver's [IPnpCallbackRemoteInterfaceNotification::OnRemoteInterfaceArrival](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackremoteinterfacenotification-onremoteinterfacearrival) callback function received.

### `pCallbackInterface` [in, optional]

A pointer to an optional, driver-supplied callback interface. The **IUnknown::QueryInterface** method of this interface must return a pointer to the driver's [IRemoteInterfaceCallbackEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iremoteinterfacecallbackevent) and [IRemoteInterfaceCallbackRemoval](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iremoteinterfacecallbackremoval) interfaces, if the driver supports those interfaces. This parameter is optional and can be **NULL**.

### `ppRemoteInterface` [out]

A pointer to a driver-supplied location that receives a pointer to the [IWDFRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremoteinterface) interface of the new remote interface object.

## Return value

**CreateRemoteInterface** returns S_OK if the operation succeeds. Otherwise, the method might return the following value:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The framework's attempt to allocate memory failed. |

This method might return one of the other values that Winerror.h contains.

## Remarks

If your driver calls **CreateRemoteInterface**, it must do so from within its [IPnpCallbackRemoteInterfaceNotification::OnRemoteInterfaceArrival](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackremoteinterfacenotification-onremoteinterfacearrival) callback function.

For more information about **CreateRemoteInterface** and using device interfaces, see [Using Device Interfaces in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers)

#### Examples

The following code example shows an [IPnpCallbackRemoteInterfaceNotification::OnRemoteInterfaceArrival](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackremoteinterfacenotification-onremoteinterfacearrival) callback function that creates a remote interface object, creates a remote target object, and opens the remote target for I/O operations.

```
void
STDMETHODCALLTYPE
CMyDevice::OnRemoteInterfaceArrival(
    __in IWDFRemoteInterfaceInitialize * FxRemoteInterfaceInit
    )
{
    HRESULT hr = S_OK;

    //
    // Create a new remote interface object and provide a callback
    // object to handle remote interface events.
    //
    CComPtr<IWDFRemoteInterface> fxRemoteInterface;
    hr = m_FxDevice->CreateRemoteInterface(FxRemoteInterfaceInit,
                                           MyRemoteInterfaceIUnknown,
                                           &fxRemoteInterface);
    if (FAILED(hr)) goto Error;
    //
    // Create a new remote target object and provide a callback
    // object to handle remote target events.
    //
    CComPtr<IWDFRemoteTarget> fxTarget;
    hr = m_FxDevice->CreateRemoteTarget(MyRemoteTargetIUnknown,
                                        fxRemoteInterface,
                                        &fxTarget);
    if (FAILED(hr)) goto Error;

    //
    // Open the remote interface with read/write access.
    //
    hr = FxTarget->OpenRemoteInterface(fxRemoteInterface,
                                       NULL,
                                       GENERIC_READ | GENERIC_WRITE,
                                       NULL);
    if (FAILED(hr)) goto Error;
...
}
```

## See also

[IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2)

[IWDFDevice2::CreateRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremotetarget)

[IWDFRemoteTarget::OpenRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openremoteinterface)