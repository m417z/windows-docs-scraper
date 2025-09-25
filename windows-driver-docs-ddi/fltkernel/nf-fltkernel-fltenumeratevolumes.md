# FltEnumerateVolumes function

## Description

The **FltEnumerateVolumes** routine enumerates all volumes in the system.

## Parameters

### `Filter` [in]

Opaque filter pointer for the caller. This parameter is required and cannot be **NULL**.

### `VolumeList` [out]

Pointer to a caller-allocated buffer that receives an array of opaque volume pointers. This parameter is optional and can be **NULL** if *VolumeListSize* is zero. If *VolumeListSize* is zero on input and *VolumeList* is **NULL**, *NumberVolumesReturned* receives the number of volumes found.

### `VolumeListSize` [in]

Number of opaque filter pointers that the buffer that *VolumeList* points to can hold. This parameter is optional and can be zero. If *VolumeListSize* is zero on input and *VolumeList* is **NULL**, *NumberVolumesReturned* receives the number of volumes found.

### `NumberVolumesReturned` [out]

Pointer to a caller-allocated variable that receives the number of opaque volume pointers returned in the array that *VolumeList* points to. If *VolumeListSize* is too small and *VolumeList* is non-**NULL** on input, **FltEnumerateVolumes** returns STATUS_BUFFER_TOO_SMALL and sets *NumberVolumesReturned* to point to the number of volumes found. This parameter is required and cannot be **NULL**.

## Return value

**FltEnumerateVolumes** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *VolumeList* parameter points to is not large enough to store the requested information. This is an error code. |

## Remarks

Because the contents of the filter manager's volume list can change at any time, two calls to **FltEnumerateVolumes** are not guaranteed to return the same result.

**FltEnumerateVolumes** adds a rundown reference to each of the opaque volume pointers returned in the array that *VolumeList* points to. When these pointers are no longer needed, the caller must release them by calling [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference) on each one. Thus every successful call to **FltEnumerateVolumes** must be matched by a subsequent call to **FltObjectDereference** for each returned volume pointer.

To convert one or more opaque volume pointers returned by the *VolumeList* parameter into volume information, call [FltGetVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeinformation).

To list volume information for all volumes that are known to the filter manager, call [FltEnumerateVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumeinformation).

To enumerate all registered minifilter drivers, call [FltEnumerateFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters).

To enumerate all minifilter driver instances, call [FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances).

To enumerate all minifilter driver instances on a given volume, call [FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume).

## See also

[FltEnumerateFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters)

[FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume)

[FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances)

[FltEnumerateVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumeinformation)

[FltGetVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeinformation)

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)