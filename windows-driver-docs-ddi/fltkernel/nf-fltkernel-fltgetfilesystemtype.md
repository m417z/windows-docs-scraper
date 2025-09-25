# FltGetFileSystemType function

## Description

The **FltGetFileSystemType** function takes a volume or instance object and provides the file system type of the volume.

## Parameters

### `FltObject` [in]

A pointer to a filter object. This can be a FLT_INSTANCE or FLT_VOLUME object.

### `FileSystemType` [out]

A pointer to a user allocated FLT_FILESYSTEM_TYPE object that receives the file system type for *FltObject*.

## Return value

**FltGetFileSystemType** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *FltObject* object was not a FLT_INSTANCE or FLT_VOLUME object. |

## Remarks

If an instance is passed as the *FltObject*, **FltGetFileSystemType** provides the file system type for the volume referred to by the instance object.

If STATUS_INVALID_PARAMETER is returned, the *FileSystemType* parameter is set to FLT_FSTYPE_UNKNOWN.

## See also

[FltGetVolumeFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromfileobject)

[FltGetVolumeFromInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefrominstance)

[FltGetVolumeFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromname)

[FltGetVolumeGuidName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeguidname)

[FltGetVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeinformation)

[FltGetVolumeInstanceFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeinstancefromname)

[FltGetVolumeName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumename)

[FltGetVolumeProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeproperties)

[FltIsVolumeWritable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisvolumewritable)