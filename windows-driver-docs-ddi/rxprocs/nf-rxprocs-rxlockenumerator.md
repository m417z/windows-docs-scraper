# RxLockEnumerator function

## Description

**RxLockEnumerator** is called from a network mini-redirector to enumerate the file locks on an FCB.

## Parameters

### `SrvOpen` [in, out]

A pointer to the SRV_OPEN structure on the FCB to be enumerated.

### `ContinuationHandle` [in, out]

A pointer to a handle passed back and forth representing the state of the enumeration. If this parameter is a **NULL** pointer, then this is the start of a lock enumeration.

### `FileOffset` [out]

A pointer to the file offset of the returned lock.

### `LockRange` [out]

A pointer to the lock range of the returned lock.

### `IsLockExclusive` [out]

A pointer to a BOOLEAN indicating if the returned lock is an exclusive lock.

## Return value

**RxLockEnumerator** returns **TRUE** on success indicating that the returned lock data is valid. The **RxLockEnumerator** routine returns or **FALSE** on failure when no lock data is found or the end of the list of locks has been reached.

## Remarks

**RxLockEnumerator** is normally called from a network min-redirector to enumerate the file locks on an FCB. **RxLockEnumerator** gets one lock on each call. so the caller needs to keep the enumeration state internally. As a result, only one enumeration process can be in progress at any time.

The **RxLockEnumerator** routine needs to allocate non-paged pool memory in order to enumerate locks. Consequently, **RxLockEnumerator** can fail if the memory allocation fails.

## See also

[The FCB Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-fcb-structure)

[The SRV_OPEN Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-srv-open-structure)