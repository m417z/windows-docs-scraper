# KsAllocateDeviceHeader function

## Description

The **KsAllocateDeviceHeader** function allocates and initializes the required device extension header.

## Parameters

### `Header` [out]

Points to the location in which to return a pointer to the initialized header.

### `ItemsCount` [in]

Specifies the number of subitems in the *ItemsList*. This should be zero if an *ItemsList* is not passed.

### `ItemsList` [in, optional]

Optional. Points to a KSOBJECT_CREATE_ITEM structure for each subitem. If there are no subitems, this value should be **NULL** and *ItemsCount* should be zero.

## Return value

The **KsAllocateDeviceHeader** function returns STATUS_SUCCESS if successful or STATUS_INSUFFICIENT_RESOURCES if unable to allocate the necessary resources.

## Remarks

The **KsAllocateDeviceHeader** function allocates memory for the KSDEVICE_HEADER structure for a device. When the header is no longer needed, the driver should call the **KsFreeDeviceHeader** function to free the memory allocated.

If subobjects exist for a given device, the driver must, before calling **KsAllocateDeviceHeader**, allocate a buffer of either paged or nonpaged memory of sufficient size to hold a KSOBJECT_CREATE_ITEM structure for each subobject. For example:

```cpp
/* Allocate a buffer for 4 subobjects for a given streaming device */
PKSOBJECT_CREATE_ITEM createBuffer ;
ULONG bufferSize  = (sizeof (KSOBJECT_CREATE_ITEM)) * 4 ;

createBuffer = (PKSOBJECT_CREATE_ITEM)
               ExAllocatePoolWithTag (PagedPool, bufferSize) ;
```

Drivers must not free the memory allocated for the subobject KSOBJECT_CREATE_ITEM list until after calling **KsFreeDeviceHeader**. Failure to do so can result in a bug check condition.

## See also

[KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item)

[KsFreeDeviceHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreedeviceheader)