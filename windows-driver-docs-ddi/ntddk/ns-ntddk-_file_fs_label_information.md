# _FILE_FS_LABEL_INFORMATION structure

## Description

The FILE_FS_LABEL_INFORMATION structure is used to set the label for a file system volume.

## Members

### `VolumeLabelLength`

Length, in bytes, of the name for the volume.

### `VolumeLabel`

Name for the volume.

## Remarks

This information can be set in either of the following ways:

* Call [FltSetVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumeinformation) or [ZwSetVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetvolumeinformationfile), passing FileFsLabelInformation as the value of *FileInformationClass* and passing a caller-allocated, FILE_FS_LABEL_INFORMATION-structured buffer as the value of *FileInformation*.
* Create an IRP with major function code IRP_MJ_SET_VOLUME_INFORMATION.

FILE_WRITE_DATA access to the volume is required to set this information.

The size of the buffer passed in the *FileInformation* parameter to [FltSetVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumeinformation) or [ZwSetVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetvolumeinformationfile) must be at least **sizeof** (FILE_FS_LABEL_INFORMATION).

This structure must be aligned on a LONG (4-byte) boundary.

## See also

[FltSetVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumeinformation)

[IRP_MJ_SET_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-volume-information)

[ZwSetVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetvolumeinformationfile)