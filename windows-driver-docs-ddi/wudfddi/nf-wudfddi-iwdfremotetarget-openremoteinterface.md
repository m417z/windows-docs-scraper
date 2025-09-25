# IWDFRemoteTarget::OpenRemoteInterface

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OpenRemoteInterface** method opens a [device interface](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers) so that the driver can send I/O requests to it.

## Parameters

### `pRemoteInterface` [in]

A pointer to a [IWDFRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremoteinterface) interface that the driver obtained from a previous call to [IWDFDevice2::CreateRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremoteinterface).

### `pszRelativeFileName` [in, optional]

An optional pointer to a caller-supplied, **null**-terminated string that the framework appends to the symbolic link name of the device interface.

### `DesiredAccess` [in]

A bitmask that specifies the caller's desired access to the file. For more information about this member, see the *DesiredAccess* parameter of [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) in the Windows SDK.

### `pOpenParams` [in, optional]

A pointer to a caller-allocated [UMDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ns-wudfddi-_umdf_io_target_open_params) structure that contains additional parameters. This parameter is optional and can be **NULL**.

## Return value

**OpenRemoteInterface** returns S_OK if the operation succeeds. Otherwise, the method might return the following value:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The framework's attempt to allocate memory failed. |

This method might return one of the other values that Winerror.h contains.

The framework's [verifier](https://learn.microsoft.com/windows-hardware/drivers/debugger/-verifier) reports an error if the framework cannot open the file.

## Remarks

After a driver's [IPnpCallbackRemoteInterfaceNotification::OnRemoteInterfaceArrival](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackremoteinterfacenotification-onremoteinterfacearrival) callback function receives notification that a device interface is available, and after the driver calls [IWDFDevice2::CreateRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremoteinterface) to create a remote interface object, the driver can call **OpenRemoteInterface** so that it can send I/O requests to the device interface.

The device interface must be accessible by the account that loaded the UMDF-based driver, which is typically the Local Service account. However, if the driver uses [impersonation](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-client-impersonation-in-umdf-drivers) when it calls **OpenRemoteInterface**, the device interface must be accessible by the impersonated account.

For more information about **OpenRemoteInterface** and how to use device interfaces in UMDF-based drivers, see [Using Device Interfaces in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

#### Examples

The following code example shows how an [IPnpCallbackRemoteInterfaceNotification::OnRemoteInterfaceArrival](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackremoteinterfacenotification-onremoteinterfacearrival) callback function can create a remote interface and remote target objects for a device interface and then open the interface for I/O operations.

```
void
STDMETHODCALLTYPE
CMyDevice::OnRemoteInterfaceArrival(
    __in IWDFRemoteInterfaceInitialize * FxRemoteInterfaceInit
    )
...
    HRESULT hr;
    CComPtr<IWDFRemoteInterface> fxRemoteInterface;
    CComPtr<IWDFRemoteTarget> m_FxTarget;

    hr = m_FxDevice->CreateRemoteInterface(FxRemoteInterfaceInit,
                                           NULL,
                                           &fxRemoteInterface);
    if (FAILED(hr)) goto Error;
    hr = FxDevice->CreateRemoteTarget(unknown,
                                      fxRemoteInterface,
                                      &m_FxTarget);
    if (FAILED(hr)) goto Error;
    hr = m_FxTarget->OpenRemoteInterface(fxRemoteInterface,
                                         NULL,
                                         GENERIC_READ | GENERIC_WRITE,
                                         NULL);
...
Error:
...
```

## See also

[IWDFRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremotetarget)

[IWDFRemoteTarget::OpenFileByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openfilebyname)