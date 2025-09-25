# IVdsVolume::ClearFlags

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Clears the volume flags.

## Parameters

### `ulFlags` [in]

The flags enumerated by [VDS_VOLUME_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_flag). Callers can clear the following flags:

**VDS_VF_LBN_REMAP_ENABLED**
**VDS_VF_HIDDEN**
**VDS_VF_READONLY**
**VDS_VF_NO_DEFAULT_DRIVE_LETTER**
**VDS_VF_INSTALLABLE**
**VDS_VF_SHADOW_COPY**

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The flags were cleared successfully. |
| **VDS_E_REVERT_ON_CLOSE_MISMATCH**<br><br>0x80042462L | The flags to be cleared do not match the flags set previously with the [SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-setflags) method and *bRevertOnClose* is set to **TRUE**. |

## Remarks

To create a boot volume on a dynamic disk, you must set the **VDS_VF_INSTALLABLE** flag for the volume and then format the volume by calling the [IVdsVolumeMF::Format](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-format) method.

## See also

[IVdsVolume](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolume)

[IVdsVolume::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-setflags)

[VDS_VOLUME_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_flag)