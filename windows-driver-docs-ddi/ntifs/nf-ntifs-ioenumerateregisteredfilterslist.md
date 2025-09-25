# IoEnumerateRegisteredFiltersList function

## Description

The **IoEnumerateRegisteredFiltersList** routine enumerates the file system filter drivers that have registered with the system.

## Parameters

### `DriverObjectList` [out]

A pointer to a caller-allocated array that receives the driver object pointers. This parameter is optional and can be **NULL**. (See the following Remarks section.)

### `DriverObjectListSize` [in]

Size, in bytes, of the *DriverObjectList* array. Can be zero. (See the following Remarks section.)

### `ActualNumberDriverObjects` [out]

Actual number of driver objects found. Note that if the array at *DriverObjectList* is too small, the number of driver object pointers that are copied into the array will be less than *ActualNumberDriverObjects*.

## Return value

**IoEnumerateRegisteredFiltersList** can return one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The call to **IoEnumerateRegisteredFiltersList** was successful. |
| STATUS_BUFFER_TOO_SMALL | The array at *DriverObjectList* is too small to hold the entire driver object list. In this case, **IoEnumerateRegisteredFiltersList** copies as many driver object pointers into the array as possible. |

## Remarks

A file system filter driver calls **IoEnumerateRegisteredFiltersList** to obtain an array of pointers to the driver objects for all file system filter drivers that have called [**IoRegisterFsRegistrationChange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange).

The filter drivers are enumerated in order of decreasing distance from the base file system. The first element (index zero) in the *DriverObjectList* array represents the filter that is attached farthest from the file system. The second entry is for the next-farthest filter, and so on. The last entry in the array is for the filter that is closest to the base file system.

**IoEnumerateRegisteredFiltersList** enumerates only legacy filter drivers; it does not enumerate minifilters. To enumerate both minifilters and legacy filters, or only minifilters, call [**FltEnumerateFilterInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation).

The filter driver typically calls **IoEnumerateRegisteredFiltersList** twice: once to get the number of driver objects in the list, and once to get the driver object list itself. In the first call, the caller should set the *DriverObjectList* parameter to **NULL** and *DriverObjectListSize* to zero. In the second call, *DriverObjectList* should contain a pointer to an appropriately-sized pointer array, and *DriverObjectListSize* should contain the size, in bytes, of that array.

**IoEnumerateRegisteredFiltersList** increments the reference count on every driver object in the list pointed to by *DriverObjectList*. Thus every successful call to **IoEnumerateRegisteredFiltersList** must be matched by a subsequent call to [**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) for each driver object in the list. Failure to do so prevents the system from freeing or deleting these driver objects because of an outstanding reference count.

Minifilters should call [**FltEnumerateFilterInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation) or [**FltEnumerateFilters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters) instead of **IoEnumerateRegisteredFiltersList**.

## See also

[**FltEnumerateFilterInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation)

[**FltEnumerateFilters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilters)

[**IoRegisterFsRegistrationChange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange)

[**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)