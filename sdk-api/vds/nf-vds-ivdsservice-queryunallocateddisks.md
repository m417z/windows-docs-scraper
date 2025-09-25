# IVdsService::QueryUnallocatedDisks

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns an enumeration object containing a list of the unallocated disks managed by VDS.

## Parameters

### `ppEnum` [out]

The address of an [IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject) interface pointer that can be used to enumerate the disks as [disk objects](https://learn.microsoft.com/windows/desktop/VDS/disk-object). For more information, see [Working with Enumeration Objects](https://learn.microsoft.com/windows/desktop/VDS/working-with-enumeration-objects). Callers must release the interface and each of the disk objects when they are no longer needed by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The enumeration was returned successfully. |
| **VDS_E_INITIALIZED_FAILED**<br><br>0x80042401L | VDS failed to initialize. If an application calls this method before the service finishes initializing, the method is blocked until the initialization completes. If the initialization fails, this error is returned. |

## Remarks

An unallocated disk is not claimed by any
provider. It may or may not contain MBR or GPT partition format information. Often it is an uninitialized disk. If the disk status is **VDS_DS_ONLINE** or **VDS_DS_OFFLINE**, the disk is unallocated and uninitialized. If it is **VDS_DS_UNKNOWN**, **VDS_DS_NOT_READY**, **VDS_DS_FAILED**, or **VDS_DS_MISSING**, it is unallocated, but the VDS service cannot determine whether or not it is initialized, possibly because of problems with the disk.

To determine the disk status, see the **status** member of the [VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop) or [VDS_DISK_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop2) structure for the disk.

If the disk status is **VDS_DS_ONLINE**, the disk can be added to a pack.

If the disk status is **VDS_DS_OFFLINE**, try to bring the disk online by calling [IVdsDiskOnline::Online](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdiskonline-online). If the call to the **Online** method succeeds, the disk can be added to a pack. If the call to **Online** fails, the disk cannot be used.

## See also

[IEnumVdsObject](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ienumvdsobject)

[IVdsService](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsservice)