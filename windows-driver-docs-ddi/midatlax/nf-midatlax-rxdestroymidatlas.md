# RxDestroyMidAtlas function

## Description

**RxDestroyMidAtlas** destroys an existing instance of a MID_ATLAS data structure and frees the allocated memory.

## Parameters

### `MidAtlas`

The MID_ATLAS structure to be freed.

### `ContextDestructor`

An associated context destructor.

## Remarks

RDBSS defines a Multiplex ID (MID), a 16-bit value, that can be used by both the network client (mini-redirector) and the server to distinguish between the concurrently active requests on any connection. A MID is part of a MID_ATLAS data structure allocated by calling **RxCreateMidAtlas**.

**RxDestroyMidAtlas** destroys a MID_ATLAS data structure previously created by a call to **RxCreateMidAtlas**. As a side effect, **RxDestroyMidAtlas** invokes the passed in context destructor on every valid context in the MID_ATLAS.

## See also

[RxAssociateContextWithMid](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxassociatecontextwithmid)

[RxCreateMidAtlas](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxcreatemidatlas)

[RxMapAndDissociateMidFromContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxmapanddissociatemidfromcontext)

[RxMapMidToContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxmapmidtocontext)

[RxReassociateMid](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxreassociatemid)