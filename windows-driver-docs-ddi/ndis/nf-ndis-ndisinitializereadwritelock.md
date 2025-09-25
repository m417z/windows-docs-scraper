# NdisInitializeReadWriteLock function

## Description

The
**NdisInitializeReadWriteLock** function initializes a read or write lock variable of type
**NDIS_RW_LOCK**.

**Note** The read-write lock interface is deprecated for NDIS 6.20 and later drivers, which should use [NdisAllocateRWLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocaterwlock) instead of **NdisInitializeReadWriteLock**.

## Parameters

### `Lock` [out]

A pointer to an opaque
**NDIS_RW_LOCK** variable that represents a lock. The caller can use this lock to gain write or read
access to resources that are shared among non-ISR driver threads.

## Remarks

An
**NDIS_RW_LOCK** variable is used to limit write access to shared resources to one non-ISR driver
thread at a time. This
**NDIS_RW_LOCK** can allow multiple non-ISR driver threads concurrent read access to those resources.
Such read access is not permitted during a write access.

The
*Lock* pointer that is passed to
**NdisInitializeReadWriteLock** is a required parameter for all other
**Ndis..ReadWriteLock** functions.

Before a driver calls the
[NdisAcquireReadWriteLock](https://learn.microsoft.com/previous-versions/ff560696(v=vs.85)) function
to obtain write or read access to a resource, the driver must call
**NdisInitializeReadWriteLock** to initialize the lock that is associated with that resource. The
caller must provide nonpaged storage for the variable at
*Lock* .

After calling
**NdisInitializeReadWriteLock**, the driver can call
[NdisAcquireReadWriteLock](https://learn.microsoft.com/previous-versions/ff560696(v=vs.85)) to obtain either write or read access to the resource. Only one non-ISR
driver thread at a time can obtain write access to the resource. When one non-ISR thread has write
access, all read and write accesses by other non-ISR threads must wait until the write-access holder
releases the lock. However, if a non-ISR thread has read access, other non-ISR threads can concurrently
acquire read access.

Initialize and use this type of lock for resources that are frequently accessed for reading and
infrequently accessed for writing.

Once resource access is complete, the driver calls the
[NdisReleaseReadWriteLock](https://learn.microsoft.com/previous-versions/ff564521(v=vs.85)) function.

Each lock that a driver initializes does one of the following:

* Protects a discrete set of shared resources from simultaneous write and read access by driver
  threads that run at IRQL <= DISPATCH_LEVEL.
* Exposes a discrete set of shared resources to simultaneous read access by driver threads that run at
  IRQL <= DISPATCH_LEVEL.

Callers of
**NdisInitializeReadWriteLock** can run at any IRQL. Usually a caller is running at IRQL =
PASSIVE_LEVEL during initialization.

## See also

[NdisAcquireReadWriteLock](https://learn.microsoft.com/previous-versions/ff560696(v=vs.85))

[NdisReleaseReadWriteLock](https://learn.microsoft.com/previous-versions/ff564521(v=vs.85))