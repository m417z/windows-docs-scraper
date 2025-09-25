# FltAcquirePushLockExclusiveEx function

## Description

The **FltAcquirePushLockExclusiveEx** routine acquires the given push lock for exclusive access by the calling thread.

## Parameters

### `PushLock` [in, out]

Opaque push lock pointer. This pointer must have been initialized by a previous call to [**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock).

### `Flags`

A bitmask of flags that control the attributes of the lock. **Flags** can be the following value.

| Flag | Meaning |
| ---- | ------- |
| FLT_PUSH_LOCK_DISABLE_AUTO_BOOST | Disable push lock auto boost. |
| FLT_PUSH_LOCK_ENABLE_AUTO_BOOST | Deprecated; has no effect. Enables push lock auto boost. |

## Return value

None.

## Remarks

**FltAcquirePushLockExclusiveEx** acquires the given push lock for exclusive access by the calling thread.

Push locks are similar to ERESOURCE structures (also called resources) in that they can be acquired for shared or exclusive access. For more information about push locks, see the reference entry for [**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock).

Unlike ERESOURCE structures, push locks cannot be acquired recursively. If the caller already has acquired the push lock for exclusive or shared access, the thread will hang.

When the caller will be given exclusive access to the given push lock depends on the following:

* If the push lock is currently unowned, exclusive access is granted immediately to the current thread.

* If the push lock has already been acquired for exclusive or shared access by another thread, the current thread is put into a wait state until the push lock can be acquired.

## See also

[**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock)