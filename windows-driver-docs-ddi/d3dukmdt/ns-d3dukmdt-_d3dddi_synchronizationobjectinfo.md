# _D3DDDI_SYNCHRONIZATIONOBJECTINFO structure

## Description

The D3DDDI_SYNCHRONIZATIONOBJECTINFO structure contains information about a synchronization object.

## Members

### `Type` [in]

A [D3DDDI_SYNCHRONIZATIONOBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_synchronizationobject_type)-typed value that indicates the type of synchronization object.

### `SynchronizationMutex`

A structure that contains information about a synchronization mutex. If the **Type** member is equal to D3DDDI_SYNCHRONIZATION_MUTEX, the union in D3DDDI_SYNCHRONIZATIONOBJECTINFO holds a SynchronizationMutex structure, which contains the following member:

### `SynchronizationMutex.InitialState`

A Boolean value that indicates whether the synchronization mutex is initially owned by an object. A value of **TRUE** indicates that the mutex is owned; **FALSE** indicates that the mutex is not owned.

### `Semaphore`

A structure that contains information about a semaphore. If the **Type** member is equal to D3DDDI_SEMAPHORE, the union in D3DDDI_SYNCHRONIZATIONOBJECTINFO holds a Semaphore structure, which contains the following members:

### `Semaphore.MaxCount`

The maximum number of events that an object can be waiting for.

### `Semaphore.InitialCount`

The initial number of events that an object is waiting for.

### `Reserved`

A structure that is reserved for future use. This structure contains the following member:

### `Reserved.Reserved`

An array of 32-bit values that are reserved for future use.

## See also

[D3DDDICB_CREATESYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createsynchronizationobject)

[D3DDDI_SYNCHRONIZATIONOBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_synchronizationobject_type)