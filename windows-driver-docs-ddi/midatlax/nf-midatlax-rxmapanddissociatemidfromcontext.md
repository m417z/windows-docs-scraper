# RxMapAndDissociateMidFromContext function

## Description

**RxMapAndDissociateMidFromContext** maps a Multiplex ID (MID) to its associated context in a MID_ATLAS structure and then disassociates the MID from the context.

## Parameters

### `MidAtlas`

A pointer to the MID_ATLAS structure.

### `Mid`

The multiplex ID to be mapped.

### `ContextPointer`

A pointer that will hold the context for this MID on exit.

## Return value

[RxReassociateMid](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxreassociatemid)
always returns STATUS_SUCCESS.

The returned *pContextPointer* parameter is a pointer to the associated context, or a **NULL** if no context was associated with this MID.

## Remarks

RDBSS defines a Multiplex ID (MID), a 16-bit value, that can be used by both the network client (mini-redirector) and the server to distinguish between the concurrently active requests on any connection. A MID is a component of a MID_ATLAS data structure allocated by calling **RxCreateMidAtlas**. A MID_MAP data structure is allocated and used for mapping MIDs to RX_CONTEXT data structures.

## See also

[RxAssociateContextWithMid](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxassociatecontextwithmid)

[RxCreateMidAtlas](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxcreatemidatlas)

[RxDestroyMidAtlas](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxdestroymidatlas)

[RxMapMidToContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxmapmidtocontext)

[RxReassociateMid](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxreassociatemid)