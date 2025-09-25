# KSEVENTS_LOCKTYPE enumeration

## Description

The KSEVENTS_LOCKTYPE enumeration identifies the type of exclusion lock. The types are used with *EventFlags* in several event-set helper functions.

## Constants

### `KSEVENTS_NONE`

No lock.

### `KSEVENTS_SPINLOCK`

Lock is assumed to be a KSPIN_LOCK.

### `KSEVENTS_MUTEX`

Lock is assumed to be a KMUTEX.

### `KSEVENTS_FMUTEX`

Lock is assumed to be a FAST_MUTEX and is acquired by raising IRQL to APC_LEVEL.

### `KSEVENTS_FMUTEXUNSAFE`

Lock is assumed to be a FAST_MUTEX and is acquired without raising IRQL to APC_LEVEL.

### `KSEVENTS_INTERRUPT`

Lock is assumed to be an interrupt synchronization spin lock.

### `KSEVENTS_ERESOURCE`

Lock is assumed to be an ERESOURCE.