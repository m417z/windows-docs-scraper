# IVdsIscsiTarget::CreatePortalGroup

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Creates a portal group. The interface pointer for the new
portal group object can be retrieved by calling
[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) through the
*ppAsync* parameter. The
[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure returned contains the volume
object interface pointer in the **cpg.pPortalGroupUnk** member.

## Parameters

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer, which VDS
initializes on return. Callers must release the interface. Use this interface to cancel, wait for, or query the
status of the operation. If you call the
[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) method on this interface and a success HRESULT value is returned, you must
release the interfaces returned in the
[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| ****S_OK**** | The portal group was created successfully. |
| ****VDS_S_ALREADY_EXISTS****<br><br>0x00042714L | No more portal groups can be created. The [CreatePortalGroup](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-createportalgroup) method did not create a new portal group. If you call the [IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) method on the interface pointer returned in the *ppAsync* parameter, an existing portal group object is retrieved. |
| ****VDS_E_PROVIDER_CACHE_CORRUPT****<br><br>0x8004241FL | The cache of the provider is corrupted. This indicates a software or communication problem inside a provider that caches information about the attached devices. The caller can use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| ****VDS_E_OBJECT_DELETED****<br><br>0x8004240BL | The target object is no longer present. |
| ****VDS_E_ANOTHER_CALL_IN_PROGRESS****<br><br>0x80042404L | Another operation is in progress; this operation cannot proceed until the previous operations are complete. |

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsIscsiTarget](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsiscsitarget)