# KsGenerateDataEvent function

## Description

The **KsGenerateDataEvent** function generates one of the standard event notifications when given an event entry structure and callback data. This allows a device to determine when event notifications should be generated, yet still use this helper function to perform the actual notification.

## Parameters

### `EventEntry` [in]

Specifies the event entry structure that references the event data. The information is used to determine what type of notification to perform. If the notification type is not one of the predefined standards, an error is returned. In the case of a single, nonrecurring event, this entry will be invalid when returned from the function. Therefore, any code that enumerates a list of events must preincrement to acquire the next event in the list before passing this event to the function.

### `DataSize` [in]

Specifies the size in bytes of the *Data* parameter passed.

### `Data` [in]

Points to data to be passed to the client callback. This data is copied to one of the preallocated buffer slots set up when the event was enabled. The size of the data must be less than whatever was originally allocated or the event will fail.

## Return value

The **KsGenerateDataEvent** function returns STATUS_SUCCESS if successful, or if unsuccessful it returns an exception or memory error.

## Remarks

It is assumed that the event list lock has been acquired before this function is called. This function can result in a call to the **RemoveHandler** for the event entry. Therefore, the function must not be called at higher than the IRQ level of the lock, or the **Remove** function must be able to handle being called at such an IRQ level.

This function is specifically for events that pass data back through a callback to a client.

## See also

[KSBUFFER_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksbuffer_item)