# RxMapMidToContext function

## Description

**RxMapMidToContext** maps a Multiplex ID (MID) to its associated context in a MID_ATLAS structure.

## Parameters

### `MidAtlas`

A pointer to the MID_ATLAS structure.

### `Mid`

The multiplex ID to be mapped.

## Return value

**RxMapMidToContext** returns a pointer to the associated context, or **NULL** if none exists.

## Remarks

RDBSS defines a Multiplex ID (MID), a 16-bit value, that can be used by both the network client (mini-redirector) and the server to distinguish between the concurrently active requests on any connection. A MID is a component of a MID_ATLAS data structure allocated by calling **RxCreateMidAtlas**. A MID_MAP data structure is allocated and used for mapping MIDs to RX_CONTEXT data structures.

## See also

[RxAssociateContextWithMid](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxassociatecontextwithmid)

[RxCreateMidAtlas](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxcreatemidatlas)

[RxDestroyMidAtlas](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxdestroymidatlas)

[RxMapAndDissociateMidFromContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxmapanddissociatemidfromcontext)

[RxReassociateMid](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxreassociatemid)