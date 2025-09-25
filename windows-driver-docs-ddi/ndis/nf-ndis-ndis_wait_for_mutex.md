# NDIS_WAIT_FOR_MUTEX macro

## Description

The **NDIS_WAIT_FOR_MUTEX** macro puts the current thread into the wait state until the specified mutex object is set to the signaled state.

## Parameters

### `_M_`

A pointer to an initialized NDIS_MUTEX-type mutex object. The caller initialized the mutex object in a prior call to the [**NDIS_INIT_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_init_mutex) macro. NDIS_MUTEX is a wrapper for the KMUTEX type.

## Return value

**NDIS_WAIT_FOR_MUTEX** returns STATUS_SUCCESS if the operation completed successfully. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

NDIS network drivers should use the **NDIS_WAIT_FOR_MUTEX** macro to wait for a mutex to transition to the signaled state.

A driver cannot wait for a nonzero time interval on a mutex object at a raised IRQL or in an *arbitrary thread context* (that is, the context of whatever thread is current when a driver function is called).

**NDIS_WAIT_FOR_MUTEX** examines the current state of the mutex object to determine if the wait operation can be satisfied immediately. If the operation can be satisfied immediately, the necessary updates are made to mutex object. Otherwise, the current thread is in a waiting state, and a new thread is selected for execution on the current processor.

This macro is an NDIS wrapper for the [**KeWaitForSingleObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject) routine.

Callers of **NDIS_WAIT_FOR_MUTEX** must be running at IRQL == PASSIVE_LEVEL and in a nonarbitrary thread context.

## See also

[**KeWaitForSingleObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)

[**NDIS_INIT_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_init_mutex)

[**NDIS_RELEASE_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_release_mutex)