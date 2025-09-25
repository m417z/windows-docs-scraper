# IVdsIscsiPortalGroup::RemovePortal

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Removes a portal from a portal group.

## Parameters

### `portalId` [in]

The **VDS_OBJECT_ID** of the portal to be removed from the portal group.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer. VDS
initializes the interface on return. Callers must release the interface. Use this interface to cancel, wait for,
or query the status of the operation. If
[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) is called and a success HRESULT value is returned, the interfaces returned in
the [VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure must be released by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer.
However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| ****S_OK**** | The portal was removed successfully from the portal group. |
| ****VDS_E_PROVIDER_CACHE_CORRUPT****<br><br>0x8004241FL | The cache of the provider is corrupted. This indicates a software or communication problem inside a provider that caches information about the attached devices. The caller can use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| ****VDS_E_OBJECT_DELETED****<br><br>0x8004240BL | The portal group object is no longer present. |
| ****VDS_E_ANOTHER_CALL_IN_PROGRESS****<br><br>0x80042404L | Another operation is in progress. This operation cannot proceed until the previous operations are complete. |
| ****VDS_E_OBJECT_NOT_FOUND****<br><br>0x80042405L | The *portalID* parameter does not refer to an existing object. |

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsIscsiPortalGroup](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsiscsiportalgroup)