# FltEnumerateVolumeInformation function

## Description

The **FltEnumerateVolumeInformation** routine provides information about volumes that are known to the filter manager.

## Parameters

### `Filter` [in]

Opaque filter pointer for the minifilter driver. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `Index` [in]

Zero-based index of the volume for which the information is requested.

### `InformationClass` [in]

Type of information requested. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **FilterVolumeBasicInformation** | The *Buffer* parameter receives a [FILTER_VOLUME_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_volume_basic_information) structure for the volume. |
| **FilterVolumeStandardInformation** | The *Buffer* parameter receives a [FILTER_VOLUME_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_volume_standard_information) structure for the volume. This structure is available starting with Windows Vista. |

### `Buffer` [out]

Pointer to a caller-allocated buffer that receives the requested information. The type of the information returned in the buffer is defined by the *InformationClass* parameter.

### `BufferSize` [in]

Size, in bytes, of the buffer that the *Buffer* parameter points to. The caller should set this parameter according to the given *InformationClass* value.

### `BytesReturned` [out]

Pointer to a caller-allocated variable that receives the number of bytes returned in the buffer that *Buffer* points to. If the input value of *BufferSize* is too small, **FltEnumerateVolumeInformation** returns STATUS_BUFFER_TOO_SMALL and sets this variable to the number of bytes required to store the requested information. This parameter is required and cannot be **NULL**.

## Return value

**FltEnumerateVolumeInformation** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *Buffer* parameter points to is not large enough to store the requested information. This is an error code. |
| **STATUS_FLT_DELETING_OBJECT** | A matching volume was found, but it is being torn down. This is an error code. |
| **STATUS_INVALID_PARAMETER** | An invalid value was specified for the *InformationClass* parameter. For example, if **FilterVolumeStandardInformation** is specified on an operating system prior to Windows Vista, the routine returns STATUS_INVALID_PARAMETER. This is an error code. |
| **STATUS_NO_MORE_ENTRIES** | There are no more entries in the global list of volumes. This is a warning code. |

## Remarks

Using the *Index* parameter is simply a way for the **FltEnumerateVolumeInformation** routine to select among volumes in the filter manager's global list of volumes. Two calls to **FltEnumerateVolumeInformation** with the same value of the *Index* parameter do not necessarily return the same result because volumes can be mounted or dismounted at any time.

If **FltEnumerateVolumeInformation** is used to create a list of volume information structures, it is possible for two or more of these structures to contain identical volume names. For more information, see [Understanding Volume Enumerations with Duplicate Volume Names](https://learn.microsoft.com/windows-hardware/drivers/ifs/understanding-volume-enumerations-with-duplicate-volume-names).

To enumerate all registered minifilter drivers, call [FltEnumerateFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters).

To enumerate all volumes that are known to the filter manager, call [FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes).

To list filter information for all registered minifilter drivers, call [FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation).

To get filter information for a given minifilter driver, call [FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation).

To enumerate all instances of a given minifilter driver, call [FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter).

To enumerate all minifilter driver instances on a given volume, call [FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume).

To enumerate instances of all minifilter drivers on all volumes, call [FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances).

## See also

[FILTER_VOLUME_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_volume_basic_information)

[FILTER_VOLUME_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_volume_standard_information)

[FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation)

[FltEnumerateFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters)

[FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter)

[FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume)

[FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances)

[FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes)

[FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation)