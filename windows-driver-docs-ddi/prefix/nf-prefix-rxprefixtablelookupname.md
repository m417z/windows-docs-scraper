# RxPrefixTableLookupName function

## Description

**RxPrefixTableLookupName** looks up a name in a prefix table used to catalog SRV_CALL, NET_ROOT, and V_NET_ROOT names and converts the underlying pointer to a structure that contains the name.

## Parameters

### `ThisTable` [in]

A pointer to the RX_PREFIX_TABLE structure in which to look.

### `CanonicalName` [in]

A pointer to the Unicode string name to look up.

### `RemainingName` [out]

A pointer to the Unicode string name of the portion of the name that was unmatched.

### `ConnectionId`

An optional parameter that represents a pointer to the RX_CONNECTION_ID to be used.

## Return value

**RxPrefixTableLookupName** returns a pointer to the node that was found if a match is found. If no match is found, **RxPrefixTableLookupName** returns a **NULL** pointer.

## Remarks

This routine is used internally by RDBSS in response to a call from MUP to claim a name or form the create path for a NET_ROOT or V_NET_ROOT structure. The **RxPrefixTableLookupName** routine can also be used by network mini-redirectors as long as the appropriate lock is acquired before accessing the table, and the lock is released when work is completed. The normal use by a driver would be as follows:

* Acquire a shared lock by calling **RxpAcquirePrefixTableLockShared**.
* Look up a name by calling **RxPrefixTableLookupName**.
* Release the shared lock by calling **RxpReleasePrefixTableLock**.

Note that if a match is found, the reference count on the found node will be incremented.

On checked builds, **RxPrefixTableLookupName** causes the system to ASSERT if the length of the *CanonicalName* string is not greater than zero.

## See also

[RxpAcquirePrefixTableLockExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/prefix/nf-prefix-rxpacquireprefixtablelockexclusive)

[RxpAcquirePrefixTableLockShared](https://learn.microsoft.com/windows-hardware/drivers/ddi/prefix/nf-prefix-rxpacquireprefixtablelockshared)

[RxpReleasePrefixTableLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/prefix/nf-prefix-rxpreleaseprefixtablelock)