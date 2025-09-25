## Description

The **IoPropagateActivityIdToThread** routine associates the activity ID from an IRP with the current thread.

## Parameters

### `Irp` [in]

The IRP whose ID will be propagated to the thread.

### `PropagatedId` [out]

A pointer to memory allocated by the caller to store the ID in the thread.

### `OriginalId`

Upon successfully returning from the call, holds the ID that was previously set on the thread. The driver must call [**IoClearActivityIdThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioclearactivityidthread) with this pointer when tracing is completed within the same thread context.

## Return value

**IoPropagateActivityIdToThread** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following.

| Return code | Description |
|--|--|
| **STATUS_NOT_FOUND** | The IRP does not have an ID associated with it. |

## Remarks

This routine should be used by drivers that are tracing aware and are issuing I/O on a worker thread. Note that such drivers must call [IoClearActivityIdThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioclearactivityidthread) with the *OriginalId* before they return control from the thread, if the call was successful.

Drivers that use I/O work items do not need to call this routine because the I/O subsystem takes care of propagating activity IDs to threads in that case.