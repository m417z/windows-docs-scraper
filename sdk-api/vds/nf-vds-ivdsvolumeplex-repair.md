# IVdsVolumePlex::Repair

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Repairs a fault-tolerant
volume plex by moving bad members to good disks.

## Parameters

### `pInputDiskArray` [in]

Pointer to an array of [VDS_INPUT_DISK](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_input_disk) structures,
one structure for each disk.

**Note** Include only the required members of this structure (**diskId** and
**ullSize**).

**Windows Server 2003:**  only volumes that are striped with parity (RAID-5) can be repaired with this method, and only one new disk can
be passed to this method at a time.

### `lNumberOfDisks` [in]

The total number of disks in the volume.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer, which VDS
initializes on return. Callers must release the interface. Use this pointer to cancel, wait for, or query the
status of the operation.

If you call [IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) on this method and a success HRESULT value is returned, you
must release the interfaces returned in the
[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The repair completed successfully. |
| **E_NOTIMPL** | The caller attempted to repair the plex of a basic volume, which is always healthy and never needs repair. |
| **VDS_E_REPAIR_VOLUMESTATE**<br><br>0x80042460L | The plex or volume is not accessible. In addition, this error can be returned when the status of a plex is not one of the following: failing redundancy, failed redundancy, or failed redundancy failing. |
| **VDS_E_DISK_IN_USE_BY_VOLUME**<br><br>0x8004244CL | One or more extents of the disk are already being used by the volume. |
| **VDS_E_VOLUME_INCOMPLETE**<br><br>0x80042432L | The volume is missing one or more members or is somehow incomplete. |

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait)

[IVdsVolumePlex](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolumeplex)

[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output)

[VDS_INPUT_DISK](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_input_disk)