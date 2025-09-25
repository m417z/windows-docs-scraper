# IPortClsNotifications::AllocNotificationBuffer

## Description

Allocates a buffer of the specified size, in the specified memory pool, for use in sending notifications, to allow for communications between audio modules and UWP apps.

For more information about audio modules, see [Implementing Audio Module Discovery](https://learn.microsoft.com/windows-hardware/drivers/audio/implementing-audio-module-communication).

## Parameters

### `PoolType` [in]

Specifies the type of memory pool from which the object is to be allocated (see [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)). The recommended values are NonPagedPoolNx or PagedPool. The memory pool type selection also depends on the IRQL level. If running at DISPATCH_LEVEL the memory must be non-paged.

### `NumberOfBytes` [in]

Number of bytes to allocate.

### `NotificationBuffer` [out]

Pointer to a [PCNOTIFICATION_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcnotification_buffer) which the method writes the address of the allocated notification.

## Return value

STATUS_SUCCESS – The driver was able to allocate the notification buffer.

STATUS_INVALID_PARAMETER – The driver returns this error if it finds any other parameter invalid, aside from the specific cases for other error status instances.

Additional standard status codes may be returned. For example, STATUS_INSUFFICIENT_RESOURCES will be returned if it is not possible to allocate the required buffer.

## Remarks

Callers of **AllocNotificationBuffer** must be running at IRQL <= DISPATCH_LEVEL. If a driver writer calls this routine at IRQL = DISPATCH_LEVEL, the NotificationStructure must be allocated from nonpaged memory.

## See also

[IPortClsNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclsnotifications)