# KsForwardIrp function

## Description

The **KsForwardIrp** function forwards an IRP to the specified driver after initializing the next stack location and setting the file object.

## Parameters

### `Irp` [in]

Specifies the IRP that is being forwarded to the specified driver.

### `FileObject` [in]

Specifies the file object to initialize the next stack with.

### `ReuseStackLocation` [in]

Specifies the new stack location.

## Return value

The **KsForwardIrp** function returns the result of the **IoCallDriver**, or it returns an invalid status if no more stack depth is available.

## Remarks

Use the **KsForwardIrp** function when only the *FileObject* parameter of the forwarded IRP changes when the current stack parameters are copied to the next stack location. The function verifies that there is a new stack location to copy into before attempting to copy. If there is no new stack location, the IRP is completed with STATUS_INVALID_DEVICE_REQUEST.