# NDIS_RELEASE_MUTEX macro

## Description

The NDIS_RELEASE_MUTEX macro releases the specified mutex object.

## Parameters

### `_M_`

A pointer to an initialized NDIS_MUTEX-type mutex object. The caller initialized the mutex object in a prior call to the [**NDIS_INIT_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_init_mutex) macro. NDIS_MUTEX is a wrapper for the KMUTEX type.

## Return value

**NDIS_RELEASE_MUTEX** returns a LONG value. If the return value is zero, the mutex object was released and is in the signaled state. If **NDIS_RELEASE_MUTEX** returns a nonzero value, the mutex is not in the signaled state.

## Remarks

NDIS network drivers should use the **NDIS_RELEASE_MUTEX** macro to release a mutex.

Only the thread that is currently holding the mutex object can release it. Otherwise, a bugcheck occurs. A bugcheck also occurs if a driver attempts to release a mutex object that is in the signaled state.

To acquire the mutex, call the [**NDIS_WAIT_FOR_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_wait_for_mutex) macro. If a mutex is acquired recursively, the holding thread must call **NDIS_RELEASE_MUTEX** the same number of times that it acquired the mutex to set it back to the signaled state.

**NDIS_RELEASE_MUTEX** is an NDIS wrapper for the [**KeReleaseMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasemutex) routine.

## See also

[**KeReleaseMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasemutex)

[**NDIS_INIT_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_init_mutex)

[**NDIS_WAIT_FOR_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_wait_for_mutex)