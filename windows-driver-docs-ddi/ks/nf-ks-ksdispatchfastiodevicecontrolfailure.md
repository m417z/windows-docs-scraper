# KsDispatchFastIoDeviceControlFailure function

## Description

The **KsDispatchFastIoDeviceControlFailure** function is used in a KSDISPATCH_TABLE.FastDeviceIoControl entry that are not handled. The function should always return **FALSE**.

## Parameters

### `FileObject` [in]

Not used.

### `Wait` [in]

Not used.

### `InputBuffer` [in, optional]

Not used.

### `InputBufferLength` [in]

Not used.

### `OutputBuffer` [out, optional]

Not used.

### `OutputBufferLength` [in]

Not used.

### `IoControlCode` [in]

Not used.

### `IoStatus` [out]

Not used.

### `DeviceObject` [in]

Not used.

## Return value

The **KsDispatchFastIoDeviceControlFailure** function returns **FALSE**.

## Remarks

The **KsDispatchFastIoDeviceControlFailure** function is needed since the dispatch table for a particular opened instance of a device may not handle a specific major function that another opened instance needs to handle. Therefore, the function pointer in the driver object must always point to a function, such as the **KsDispatchFastIoDeviceControlFailure** function, that calls a dispatch table entry.