# RxDereference function

## Description

**RxDereference** decrements the **NodeReferenceCount** member of a structure by one for several reference counted data structures used by RDBSS.

## Parameters

### `Instance` [in, out]

A pointer to the reference-counted data structure to be dereferenced.

### `LockHoldingState` [in]

The mode in which the appropriate lock for this data structure is held. This parameter can be one of the following values for the LOCK_HOLDING_STATE enumeration:

#### LHS_LockNotHeld

A lock is not currently held.

#### LHS_SharedLockHeld

A shared lock is being held.

#### LHS_ExclusiveLockHeld

An exclusive lock is being held.

## Remarks

**RxDereference** can be used to dereference (decrement by one) the **NodeReferenceCount** member on the following data structures used by RDBSS:

SRV_CALL

NET_ROOT

V_NET_ROOT

SRV_OPEN

FOBX

If **RxDereference** is called with any other type of RDBSS data structure, the routine causes the system to ASSERT on checked builds.

If the **NodeReferenceCount** member is less than 0 after being dereferenced (decremented) by **RxDereference**, then **RxDereference** causes the system to ASSERT on checked builds.

If the **NodeReferenceCount** member decrements to 1 and the *LockHoldingState* parameter was LHS_ExclusiveLockHeld, the instance of the data structure can be finalized immediately. Otherwise, the instance of the data structure is tagged to be scavenged and finalized later.

## See also

[RxReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxreference)

[The FOBX Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-fobx-structure)

[The NET_ROOT Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-net-root-structure)

[The SRV_CALL Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-srv-call-structure)

[The SRV_OPEN Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-srv-open-structure)

[The V_NET_ROOT Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-v-net-root-structure)