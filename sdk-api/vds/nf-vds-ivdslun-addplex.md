# IVdsLun::AddPlex

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Adds a LUN to the target LUN
as a new plex.

## Parameters

### `lunId` [in]

The GUID of the LUN to be added as a plex.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer,
which VDS initializes on return. Callers must release the interface. Use this interface to cancel, wait for, or
query the status of the operation.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | This return value signals a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The LUN object is no longer present. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The LUN is in a failed state and is unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress. This operation cannot proceed until the previous operation or operations are complete. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | This can be returned from any method that takes a **VDS_OBJECT_ID** constant. It indicates that the identifier does not refer to an existing object. |
| **VDS_E_INVALID_OPERATION**<br><br>0x80042415L | The operation is not valid. Alternatively, the source LUN is smaller than the target LUN. If the source LUN is larger than the target LUN, the target LUN remains the same size and the operation is successful. |

## Remarks

After the caller adds the new LUN as a plex, it is no longer visible as a LUN. If the caller
adds a mirrored LUN, VDS includes each plex as a discrete plex. All data on the added LUN is lost.

Implementers must return a pointer to the
[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface for this method, regardless of whether
the call initiates an asynchronous operation.

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate)

[IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh)

[IVdsLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslun)