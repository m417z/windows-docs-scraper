# FltGetVolumeInformation function

## Description

The **FltGetVolumeInformation** routine provides information about a given volume.

## Parameters

### `Volume` [in]

Opaque pointer for the volume. This parameter is required and cannot be **NULL**.

### `InformationClass` [in]

Type of information requested. This parameter is required and must be one of the following values.

| Value | Meaning |
| --- | --- |
| **FilterVolumeBasicInformation** | The *Buffer* parameter receives a [FILTER_VOLUME_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_volume_basic_information) structure for the volume. |
| **FilterVolumeStandardInformation** | The *Buffer* parameter receives a [FILTER_VOLUME_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_volume_standard_information) structure for the volume. This structure is available starting with Windows Vista. |

### `Buffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *InformationClass* parameter. This parameter is required and cannot be **NULL**.

### `BufferSize` [in]

Size, in bytes, of the buffer that the *Buffer* parameter points to. The caller should set this parameter according to the given *InformationClass* value. This parameter is required.

### `BytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *Buffer* points to. If the input value of *BufferSize* is too small, **FltGetVolumeInformation** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the number of bytes required to store the requested information. This parameter is required and cannot be **NULL**.

## Return value

**FltGetVolumeInformation** returns STATUS_SUCCESS or an appropriate NTSTATUS status code, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid value was specified for the *InformationClass* parameter. For example, if **FilterVolumeStandardInformation** is specified on an operating system prior to Windows Vista, the routine will return STATUS_INVALID_PARAMETER. This is an error code. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *Buffer* parameter points to is not large enough to store the requested information. This is an error code. |

## Remarks

Given an opaque volume pointer, such as that returned by the [FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes) routine, the **FltGetVolumeInformation** routine provides information about the volume pointed to by the opaque volume pointer, passed through the *Volume* parameter. Note that the caller must eventually release the opaque volume pointer by calling the [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference) routine.

The **FltGetVolumeInformation** routine returns information for a single volume. However, given a list of opaque volume pointers, the routine can be iteratively used to create a list of corresponding volume information structures. In such a list, it is possible for two or more of the structures to contain identical volume names. For more information, see [Understanding Volume Enumerations with Duplicate Volume Names](https://learn.microsoft.com/windows-hardware/drivers/ifs/understanding-volume-enumerations-with-duplicate-volume-names).

To list volume information for all volumes that are known to the filter manager, call [FltEnumerateVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumeinformation).

The following list contains related information, which may be of use:

* To enumerate all registered minifilter drivers in the system, call the [FltEnumerateFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters) routine.
* To obtain information about minifilter driver instances attached to a given volume, call the [FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume) routine.
* To enumerate minifilter driver instances for a given minifilter driver or volume, call the [FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances) routine.
* To enumerate all volumes in the system, call the [FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes) routine.
* To obtain an opaque pointer for the volume represented by a given volume device object (VDO), call the [FltGetVolumeFromDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromdeviceobject) routine.
* To obtain an opaque pointer for the volume that a given file stream resides on, call the [FltGetVolumeFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromfileobject) routine.
* To obtain an opaque pointer for the volume that a given minifilter driver instance is attached to, call the [FltGetVolumeFromInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefrominstance) routine.
* To obtain an opaque pointer for the volume whose name matches a given volume name, call the [FltGetVolumeFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromname) routine.

## See also

[FILTER_VOLUME_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_volume_basic_information)

[FILTER_VOLUME_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_volume_standard_information)

[FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects)

[FltEnumerateFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters)

[FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume)

[FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances)

[FltEnumerateVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumeinformation)

[FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes)

[FltGetVolumeFromDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromdeviceobject)

[FltGetVolumeFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromfileobject)

[FltGetVolumeFromInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefrominstance)

[FltGetVolumeFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromname)