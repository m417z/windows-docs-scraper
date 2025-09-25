# FltEnumerateInstances function

## Description

The **FltEnumerateInstances** routine enumerates minifilter driver instances for a given minifilter driver or volume.

## Parameters

### `Volume` [in, optional]

Opaque pointer for the volume for which the caller wants to enumerate minifilter driver instances. If **NULL**, instances for all volumes are enumerated. Must be non-**NULL** if *Filter* is **NULL**.

### `Filter` [in, optional]

Opaque filter pointer for the minifilter driver whose instances are to be enumerated. If **NULL**, instances for all minifilter drivers are enumerated. Must be non-**NULL** if *Volume* is **NULL**.

### `InstanceList` [out]

Pointer to a caller-allocated buffer that receives an array of opaque instance pointers.

### `InstanceListSize` [in]

Number of opaque instance pointers that the buffer that *InstanceList* points to can hold.

### `NumberInstancesReturned` [out]

Pointer to a caller-allocated variable that receives the number of opaque instance pointers returned in the array that *InstanceList* points to. If *InstanceListSize* is too small, **FltEnumerateInstances** returns STATUS_BUFFER_TOO_SMALL and sets *NumberInstancesReturned* to point to the number of matching instances found.

## Return value

**FltEnumerateInstances** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *InstanceList* parameter points to is not large enough to store the requested information. This is an error code. |
| **STATUS_INVALID_PARAMETER** | *Volume* and *Filter* cannot both be **NULL**. This is an error code. |

## Remarks

Because the minifilter driver instances in the instance list can change at any time, two calls to **FltEnumerateInstances** with the same *Volume* and *Filter* values are not guaranteed to return the same result.

**FltEnumerateInstances** adds a rundown reference to each of the opaque instance pointers returned in the array that the *InstanceList* parameter points to. When these pointers are no longer needed, the caller must release them by calling [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference) on each one. Thus every successful call to **FltEnumerateInstances** must be matched by a subsequent call to **FltObjectDereference** for each returned instance pointer.

To enumerate all registered minifilter drivers, call [FltEnumerateFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters).

To enumerate all volumes that are known to the Filter Manager, call [FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes).

To list filter information for all registered minifilter drivers, call [FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation).

To get filter information for a given minifilter driver, call [FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation).

To enumerate all instances of a given minifilter driver, call [FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter).

To enumerate all minifilter driver instances on a given volume, call [FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume).

## See also

[FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation)

[FltEnumerateFilters](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters)

[FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter)

[FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume)

[FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes)

[FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation)

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)