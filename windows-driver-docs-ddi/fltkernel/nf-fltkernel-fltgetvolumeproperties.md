# FltGetVolumeProperties function

## Description

The **FltGetVolumeProperties** routine returns volume property information for the given volume.

## Parameters

### `Volume` [in]

Opaque pointer for the volume. This parameter is required and cannot be **NULL**.

### `VolumeProperties` [out]

Pointer to a caller-allocated buffer that receives the requested volume property information. If *Length* is zero on input, this parameter is ignored. Otherwise, this parameter is required and cannot be **NULL**.

### `VolumePropertiesLength`

Size, in bytes, of the buffer pointed to by the *VolumeProperties* parameter. This parameter is optional and can be zero. If it is zero, *LengthReturned* receives the size, in bytes, of the buffer needed to hold the volume properties. If this parameter is nonzero, it must be at least the value of **sizeof(**FLT_VOLUME_PROPERTIES**)**.

### `LengthReturned` [out]

Pointer to a caller-allocated variable that receives the size, in bytes, of the information returned in *VolumeProperties*. If **FltGetVolumeProperties** returns STATUS_BUFFER_TOO_SMALL, or if *Length* is zero on input, this parameter instead receives the size, in bytes, of the buffer needed to hold the volume properties. This parameter is required and cannot be **NULL**.

## Return value

**FltGetVolumeProperties** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_OVERFLOW** | The buffer that the *VolumeProperties* parameter points to is large enough to hold the fixed portion of the [FLT_VOLUME_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_volume_properties) structure but not the **FileSystemDriverName**, **FileSystemDeviceName**, or **RealDeviceName** members. In this case, only the fixed portion of the volume information is returned in the buffer pointed to by the *VolumeProperties* parameter. The *LengthReturned* parameter receives the actual length, in bytes, of data returned. This is a warning code. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *VolumeProperties* parameter points to is not large enough to hold the volume property information. The *LengthReturned* parameter receives the required buffer size. In this case, no volume information is returned. This is an error code. |

## Remarks

**FltGetVolumeProperties** only returns information that can safely be queried during the mount process without risk of a system deadlock. Therefore, a minifilter driver commonly calls this routine from a post-mount callback function or an *InstanceSetupCallback* ([PFLT_INSTANCE_SETUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback)) routine to determine whether to attach to a given volume.

## See also

[FLT_VOLUME_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_volume_properties)

[PFLT_INSTANCE_SETUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback)