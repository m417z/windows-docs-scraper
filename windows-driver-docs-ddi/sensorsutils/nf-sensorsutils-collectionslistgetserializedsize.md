# CollectionsListGetSerializedSize function

## Description

This routine returns the larger of the two sizes to provide for sufficient buffer sizes to accommodate passing the collection list across processes that can have different bit-ness values (e.g. 32 bit <-> 64 bit):

1. The architecture-independent size of the entire collection list, including size of memory blocks that are pointed by embedded pointers.
2. The RPC serialized size of the collection list.

## Parameters

### `Collection` [in]

Pointer to a collection list.

## Return value

This function returns a ULONG that represents the serialized data size.

## Remarks

## See also