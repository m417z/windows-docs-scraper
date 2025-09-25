# NDIS_INIT_MUTEX macro

## Description

The **NDIS_INIT_MUTEX** macro initializes a mutex object and sets it to a signaled state.

## Parameters

### `_M_`

A pointer to a caller-supplied NDIS_MUTEX-type mutex object. NDIS_MUTEX is a wrapper for KMUTEX.

## Remarks

NDIS network drivers should use the **NDIS_INIT_MUTEX** macro to initialize a mutex.

The initial state of the mutex object is the signaled state. To acquire the mutex, call the [**NDIS_WAIT_FOR_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_wait_for_mutex) macro. To release the mutex, call the [**NDIS_RELEASE_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_release_mutex) macro.

A driver cannot wait for a nonzero time interval on a mutex object at a raised IRQL or in an *arbitrary thread context* (that is, the context of whatever thread is current when a driver function is called).

Storage for a mutex object must reside in a driver context area or in a nonpaged pool that the caller allocated.

The **NDIS_INIT_MUTEX** macro is an NDIS wrapper for the [**KeInitializeMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializemutex) routine.

## See also

[**KeInitializeMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializemutex)

[**NDIS_RELEASE_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_release_mutex)

[**NDIS_WAIT_FOR_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_wait_for_mutex)