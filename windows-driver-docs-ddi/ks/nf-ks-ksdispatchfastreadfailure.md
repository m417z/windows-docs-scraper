# KsDispatchFastReadFailure function

## Description

The **KsDispatchFastReadFailure** function is used in a KSDISPATCH_TABLE.FastRead entry when fast I/O read is not handled. The function should always return **FALSE**.

## Parameters

### `FileObject` [in]

Not used.

### `FileOffset` [in]

Not used.

### `Length` [in]

Not used.

### `Wait` [in]

Not used.

### `LockKey` [in]

Not used.

### `Buffer` [out]

Not used.

### `IoStatus` [out]

Not used.

### `DeviceObject` [in]

Not used.

## Return value

The **KsDispatchFastReadFailure** function returns **FALSE**.

## Remarks

The **KsDispatchFastReadFailure** function is needed since the dispatch table for a particular opened instance of a device may not handle a specific major function that another opened instance needs to handle. Therefore, the function pointer in the driver object must always point to a function, such as the **KsDispatchFastReadFailure** function, that calls a dispatch table entry.