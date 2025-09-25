# RxAssociateContextWithMid function

## Description

**RxAssociateContextWithMid** associates the supplied opaque context with an available multiplex ID (MID) from a MID_ATLAS.

## Parameters

### `MidAtlas`

A pointer to the MID_ATLAS data structure.

### `Context`

A pointer to the context.

### `NewMid`

A pointer to the multiplex ID to be associated with the context.

## Return value

**RxAssociateContextWithMid** returns STATUS_SUCCESS on success or one of the following error values:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | This error is returned when it was not possible to allocate sufficient memory for the new MID_MAP data structure. |
| **STATUS_UNSUCCESSFUL** | This error is returned for several cases including when the number of MIDs already in use is greater than the maximum number of MIDs set when the MID_ATLAS structure was created. |

## Remarks

RDBSS defines a Multiplex ID (MID), a 16-bit value, that can be used by both the network client (mini-redirector) and the server to distinguish between the concurrently active requests on any connection. A MID is a component of a MID_ATLAS data structure allocated by calling **RxCreateMidAtlas**. A MID_MAP data structure is allocated and used for mapping MIDs to RX_CONTEXT data structures. **RxAssociateContextWithMid** allocates non-paged pool memory when creating a new MID_MAP data structure.

The *pContext* parameter can be any opaque context but it is commonly an RX_CONTEXT.

## See also

[RxCreateMidAtlas](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxcreatemidatlas)

[RxDestroyMidAtlas](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxdestroymidatlas)

[RxMapAndDissociateMidFromContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxmapanddissociatemidfromcontext)

[RxMapMidToContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxmapmidtocontext)

[RxReassociateMid](https://learn.microsoft.com/windows-hardware/drivers/ddi/midatlax/nf-midatlax-rxreassociatemid)