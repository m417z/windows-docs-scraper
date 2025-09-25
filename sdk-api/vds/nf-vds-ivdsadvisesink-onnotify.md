# IVdsAdviseSink::OnNotify

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Passes notifications
from providers to VDS, and from VDS to applications.

## Parameters

### `lNumberOfNotifications` [in]

The number of notifications specified in *pNotificationArray*.

### `pNotificationArray` [in]

A pointer to an array of [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)
structures. A provider allocates the memory for the array when the provider calls into the service; the
service frees the array. VDS allocates the array when the service calls into an application. In this case,
callers must free the array by using the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | VDS returns this value to a provider if the service is not fully initialized when the provider calls into this method, or if some notifications are lost by the service. |

## Remarks

An application implements this method to receive notifications from VDS. Some of these notifications originate from VDS; others are provider notifications that are forwarded by VDS.

VDS maintains a cache of information about the properties of all VDS objects, such as subsystems and controllers. Whenever a change occurs that triggers a notification, this cache is updated automatically. Also, calling [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) or [IVdsService::Refresh](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-refresh) in response to a VDS notification could cause an endless loop of notifications to be sent. For these reasons, an application should not call **IVdsHwProvider::Refresh** or **IVdsService::Refresh** in its implementation of this method.

For providers that use this method to send notifications, it is good practice to group notifications originating from a single event together. For example, when a LUN
is deleted, send **VDS_NF_DRIVE_MODIFY** notifications for all affected drives
together.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[IVdsService::Refresh](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-refresh)

[IVdsService::Unadvise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-unadvise)

[VDS Notifications](https://learn.microsoft.com/windows/desktop/VDS/vds-notification-model)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)