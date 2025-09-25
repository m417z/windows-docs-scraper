# IVdsService::Advise

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Registers the caller's [IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface
with VDS so that the caller receives notifications from the VDS service.

## Parameters

### `pSink` [in]

A pointer to the [IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface.

### `pdwCookie` [out]

A pointer to a cookie that can later be used to unregister the interface.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The registration completed successfully. |
| **VDS_E_INITIALIZED_FAILED**<br><br>0x80042401L | VDS failed to initialize. If an application calls this method before the service finishes initializing, the method is blocked until the initialization completes. If the initialization fails, this error is returned. |

## Remarks

To receive notifications from the VDS service, your application must implement the [IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)
interface and use the **Advise** method to register the interface.

To stop receiving notifications from the VDS service, use the [IVdsService::Unadvise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-unadvise) method to unregister the [IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface.

**Note** An application that calls **Advise** must eventually call [Unadvise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-unadvise). Ideally, it should call **Unadvise** as soon as it no longer needs to receive notifications.

To receive notifications from underlying software and hardware providers, VDS passes a notification callback
function to each provider as a parameter of the
[IVdsProviderPrivate::OnLoad](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsproviderprivate-onload) method.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsProviderPrivate::OnLoad](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsproviderprivate-onload)

[IVdsService](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsservice)

[VDS Notifications](https://learn.microsoft.com/windows/desktop/VDS/vds-notification-model)