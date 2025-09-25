# FltEnumerateFilters function

## Description

The **FltEnumerateFilters** routine enumerates all registered minifilter drivers in the system.

## Parameters

### `FilterList` [out]

Pointer to a caller-allocated buffer that receives an array of opaque filter pointers. This parameter is optional and can be **NULL** if the value of *FilterListSize* parameter is zero. If *FilterListSize* is zero on input and *FilterList* is **NULL**, the *NumberFiltersReturned* parameter receives the number of minifilter drivers found.

### `FilterListSize` [in]

Number of opaque filter pointers that the buffer that the *FilterList* parameter points to can hold. This parameter is optional and can be zero. If *FilterListSize* is zero on input and *FilterList* is **NULL**, the *NumberFiltersReturned* parameter receives the number of minifilter drivers found.

### `NumberFiltersReturned` [out]

Pointer to a caller-allocated variable that receives the number of opaque filter pointers returned in the array that the *FilterList* parameter points to. If the *FilterListSize* parameter value is too small and *FilterList* is non-**NULL** on input, **FltEnumerateFilters** returns STATUS_BUFFER_TOO_SMALL and sets *NumberFiltersReturned* to point to the number of minifilter drivers found. This parameter is required and cannot be **NULL**.

## Return value

**FltEnumerateFilters** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that the *FilterList* parameter points to is not large enough to store the requested information. This is an error code. |

## Remarks

Because filters can register at any time, two calls to **FltEnumerateFilters** are not guaranteed to return the same result.

**FltEnumerateFilters** adds a rundown reference to each of the opaque filter pointers returned in the array that the *FilterList* parameter points to. When these pointers are no longer needed, the caller must release them by calling [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference) on each one. Thus every successful call to **FltEnumerateFilters** must be matched by a subsequent call to **FltObjectDereference** for each returned filter pointer.

To list filter information for all registered minifilter drivers, call [FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation).

To enumerate instances of all minifilter drivers on all volumes, call [FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances).

To enumerate all volumes that are known to the Filter Manager, call [FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes).

## See also

[FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation)

[FltEnumerateInstances](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstances)

[FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes)

[FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation)

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)