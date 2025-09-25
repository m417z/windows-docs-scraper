# IVdsLun::Delete

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Deletes the LUN and all of its
plexes. Any data on the LUN is lost. VDS frees the extents allocated to the LUN.

## Return value

This method can return standard HRESULT values, such as E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | This return value signals a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The LUN object is no longer present. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The LUN is in a failed state and is unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress; this operation cannot proceed until the previous operation or operations are complete. |

## Remarks

If an application holds a reference to the [IVdsLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslun) interface
and calls **IVdsLun::Delete**, implementers should return
**VDS_E_OBJECT_DELETED** on subsequent calls to methods such as
[GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-getproperties) on that interface. In this case,
the interface has an outstanding reference and is valid, but the underlying object no longer exists.

If a LUN that is unmasked to a target machine is deleted, the LUN's visibility on that machine may not change until a bus rescan is performed. The VDS application on the target machine initiates the bus rescan by calling [IVdsService::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-reenumerate). The initiating of the bus rescan is the responsibility of the VDS application, not the hardware provider.

If a method such as **IVdsLun::Delete** is called in one thread while [IVdsSubSystem::QueryLuns](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-queryluns) is called in another thread that is running simultaneously, the result could be a provider access violation. The hardware provider is responsible for serializing these methods as needed to minimize such synchronization issues.

The hardware provider is responsible for removing the LUN's partition information so that the LUN can be reused. If the LUN is an MBR disk, this is accomplished by writing zeros to the first and last 1 MB of the disk. For a GPT disk, zeros must be written to the first and last 16 KB of the disk.

## See also

[IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate)

[IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh)

[IVdsLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslun)

[IVdsLun::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-getproperties)