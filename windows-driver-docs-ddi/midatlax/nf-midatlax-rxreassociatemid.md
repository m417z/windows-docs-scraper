# RxReassociateMid function

## Description

**RxReassociateMid** reassociates a Multiplex ID (MID) with an alternate context.

## Parameters

### `MidAtlas`

A pointer to the MID_ATLAS structure.

### `Mid`

The multiplex ID to be mapped.

### `NewContext`

A pointer that will hold the new context for this MID on exit.

## Return value

**RxReassociateMid** returns STATUS_SUCCESS on success. The returned *pNewMid* parameter can be **NULL** if no context is associated with this MID.

## Remarks

RDBSS defines a MID as a 16-bit value, which can be used by both the network client (mini-redirector) and the server to distinguish between the concurrently active requests on any connection. A MID is a component of a MID_ATLAS data structure allocated by calling [RxCreateMidAtlas](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxcreatemidatlas). A MID_MAP data structure is allocated and used for mapping MIDs to RX_CONTEXT data structures.

## See also

[RxAssociateContextWithMid](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxassociatecontextwithmid)

[RxCreateMidAtlas](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxcreatemidatlas)

[RxDestroyMidAtlas](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxdestroymidatlas)

[RxMapAndDissociateMidFromContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxmapanddissociatemidfromcontext)

[RxMapMidToContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxmapmidtocontext)