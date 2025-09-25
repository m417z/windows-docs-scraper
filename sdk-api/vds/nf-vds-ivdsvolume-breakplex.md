# IVdsVolume::BreakPlex

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Removes a specified
plex from the current volume. The interface pointer for the new
[volume object](https://learn.microsoft.com/windows/desktop/VDS/volume-object) can be retrieved by calling
[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) through the
*ppAsync* parameter. The
[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure returned contains the volume
object interface pointer in the **bvp.pVolumeUnk** member.

## Parameters

### `plexId` [in]

The GUID of the plex to be broken.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer,
which VDS initializes on return. Callers must release the interface. Use this pointer to cancel, wait for, or
query the status of the operation.

If you call [IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) on this method and a success HRESULT value is returned,
you must release the interfaces returned in the
[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The plex was broken successfully. |
| **VDS_E_VOLUME_NOT_ONLINE**<br><br>0x8004243DL | The volume is not available. |
| **VDS_E_VOLUME_NOT_A_MIRROR**<br><br>0x80042445L | The volume is not a mirror. |

## Remarks

This operation is not valid for basic volumes, which have exactly one plex.

Use this method to break a mirror. The broken plex becomes a new volume. If the remaining plex is stale or
missing, VDS stops the operation and returns an error. Note that VDS dismounts the volume during the
operation.

A boot or system plex—essentially, the plex used to boot the computer—is not valid for
**plexId**. When passed such a plex, VDS stops the operation and returns an error.

Implementers must return a pointer to the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)
interface for this method, regardless of whether the call initiates an asynchronous operation.

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait)

[IVdsVolume](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolume)

[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output)