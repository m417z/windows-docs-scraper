# RxReference function

## Description

**RxReference** increments the **NodeReferenceCount** member of a structure by one for several of the reference counted data structures used by RDBSS.

## Parameters

### `Instance` [in, out]

A pointer to the reference-counted data structure to be referenced (incremented).

## Remarks

The **RxReference** routine can be used to reference (increment by one) the **NodeReferenceCount** member on the following data structures used by RDBSS:

SRV_CALL

NET_ROOT

V_NET_ROOT

SRV_OPEN

FOBX

If **RxReference** is called with any other type of RDBSS data structure, the routine causes the system to ASSERT on checked builds.

## See also

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)