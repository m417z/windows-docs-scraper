# IVdsVolume::SetFlags

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Sets the volume
flags.

## Parameters

### `ulFlags` [in]

The flags enumerated by [VDS_VOLUME_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_flag). Callers
can set the following flags:

* `VDS_VF_LBN_REMAP_ENABLED`
* `VDS_VF_HIDDEN`
* `VDS_VF_READONLY`
* `VDS_VF_NO_DEFAULT_DRIVE_LETTER`
* `VDS_VF_INSTALLABLE`
* `VDS_VF_SHADOW_COPY`

### `bRevertOnClose` [in]

If **TRUE**, the flags are temporarily set. VDS resets each
flag to the previous state when the caller releases the last reference to the volume object, calls
[IVdsVolume::ClearFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-clearflags), or dismounts the volume,
except when the flag is set on the entire disk (see the table in the Remarks section for details). When the flag
is set on the entire disk, the
**IVdsVolume::ClearFlags** method must be called to
reset the flags.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The flags are set. |
| **VDS_E_LBN_REMAP_ENABLED_FLAG**<br><br>0x80042456L | The provider does not support the **VDS_VF_LBN REMAP_ENABLED** volume flag. |
| **VDS_E_NO_DRIVELETTER_FLAG**<br><br>0x80042457L | The provider does not support the **VDS_VF_NO DRIVELETTER** volume flag. |
| **VDS_E_REVERT_ON_CLOSE**<br><br>0x80042458L | *bRevertOnClose* should only be set to true if either the **VDS_VF_HIDDEN** or **VDS_VF_READONLY** volume flag is set. |
| **VDS_E_REVERT_ON_CLOSE_SET**<br><br>0x80042459L | Some volume flags are set to true already. You must clear these flags first, then call this method and set the *bRevertOnClose* parameter to true again. The **VDS_E_INVALID_OPERATION** return value can also indicate this condition. |

## Remarks

The **VDS_VF_READONLY**, **VDS_VF_HIDDEN**, and
**VDS_VF_NO_DEFAULT_DRIVE_LETTER** flags scope differently depending on the disk type (basic
or dynamic) and partition style (MBR or GPT). The scope is either disk-based or volume-based, as described by the
following conditions:

* If the disk is basic and MBR, then setting one of these flags on a volume affects the current volume and
  all future volumes with the specified attribute created on the disk.
* If the disk is basic and GPT, dynamic and MBR, or dynamic and GPT, then setting one of the flags on a
  volume applies to that specific volume only.

The following table identifies the scope of each volume flag on MBR basic disks, GPT basic disks, and MBR or
GPT dynamic disks.

| Flag | MBR basic disks | GPT basic disks | MBR or GPT dynamic disks |
| --- | --- | --- | --- |
| **VDS_VF_LBN_REMAP_ENABLED** | Cannot be set. | Cannot be set. | Set on volume, if supported by third party volume manager. |
| **VDS_VF_HIDDEN** | Set on the entire disk. | Set on volumes (data partitions only). | Set on volumes. |
| **VDS_VF_READONLY** | Set on the entire disk. | Set on volumes (data partitions only). | Set on volumes. |
| **VDS_VF_NO_DEFAULT_DRIVE_LETTER** | Set on the entire disk. | Set on partitions. | See [VDS_VOLUME_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_flag). |
| **VDS_VF_SHADOW_COPY** | Set on the entire disk. | Set on volumes (data partitions only). | Set on volumes. |
| **VDS_VF_INSTALLABLE** | Cannot be set. | Cannot be set. | Set on volumes. |

If *bRevertOnClose* is **TRUE** and the disk is an MBR basic
disk and the volume is then deleted, the flags are still set on the entire disk and the flags will apply to any new volumes
that are created on the disk. [IVdsAdvancedDisk::Clean](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-clean)
must then be used to clear the flags.

To create a boot volume on a dynamic disk, you must set the **VDS_VF_INSTALLABLE** flag for the volume and then format the volume by calling the [IVdsVolumeMF::Format](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-format) method.

This method fails if the volume contains one or more of the following flags:

* **VDS_VF_SYSTEM**
* **VDS_VF_BOOT**
* **VDS_VF_PAGEFILE**
* **VDS_VF_HIBERNATION**
* **VDS_VF_CRASHDUMP**

Specifying either **VDS_VF_HIDDEN** or **VDS_VF_READONLY** will
force a dismount and remount of the volume, unless *bRevertOnClose* is
**TRUE**.

## See also

[IVdsAdvancedDisk::Clean](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-clean)

[IVdsVolume](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolume)

[IVdsVolume::ClearFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-clearflags)

[VDS_VOLUME_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_flag)