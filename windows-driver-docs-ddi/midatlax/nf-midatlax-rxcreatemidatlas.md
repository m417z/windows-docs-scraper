# RxCreateMidAtlas function

## Description

**RxCreateMidAtlas** allocates a new instance of MID_ATLAS data structure and initializes it.

## Parameters

### `MaximumNumberOfEntries`

The maximum number of multiplex IDs (MIDs) to be allowed in the atlas.

### `InitialAllocation`

The number of multiplex IDs allocated initially.

## Return value

**RxCreateMidAtlas** returns a pointer to allocated and initialized MID_ATLAS data structure on success or a **NULL** pointer on failure.

## Remarks

RDBSS defines a Multiplex ID (MID), a 16-bit value, that can be used by both the network client (mini-redirector) and the server to distinguish between the concurrently active requests on any connection.

The MID must be efficiently able to manage the unique tagging and identification of a number of MIDs (typically 50) from a possible combination of 65,536 values. In order to ensure a proper time space tradeoff, the lookup is organized as a three level hierarchy. The 16 bits used to represent a MID are split up into three bitfields. The length of the rightmost field (least significant ) is decided by the maximum number of MIDs that are to be allowed in the atlas. This maximum value is a parameter passed to **RxCreateMidAtlas** when the MID_ATLAS data structure is created. The remaining length is split up equally between the next two fields.

For example, if a maximum of 50 MIDs are to be allocated on creation , the length of the first field is 6 (64 ( 2 ** 6 ) is greater than 50 ). The remaining length is split into two fields of 5 bits each.

**RxCreateMidAtlas** allocates non-paged pool memory when creating a new MID_ATLAS data structure.

## See also

[RxAssociateContextWithMid](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxassociatecontextwithmid)

[RxDestroyMidAtlas](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxdestroymidatlas)

[RxMapAndDissociateMidFromContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxmapanddissociatemidfromcontext)

[RxMapMidToContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxmapmidtocontext)

[RxReassociateMid](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxreassociatemid)