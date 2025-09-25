## Description

The GetAddressSpaceRelation method returns the relationship between the virtual memory space of the current context and that of another specified context. The relationship can indicate how the memory mappings of both contexts interact.

## Parameters

### `pContext`

A pointer to an IDebugHostContext2 instance representing the context to compare against the current context.

### `pAddressSpaceRelation`

A pointer to an [AddressSpaceRelation enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/ne-dbgmodel-addressspacerelation) that will receive the result of the relationship between the two contexts' virtual memory spaces.

## Return value

The possible return values are:

- Disjoint: The two contexts share no virtual memory mappings.
- Equal: The two contexts share all virtual memory mappings.
- Overlapping: The two contexts have partially shared memory mappings.
- Subset: The indicated context is a strict subset of the current context.
- Superset: The indicated context is a strict superset of the current context.

## Remarks

## See also

[IDebugHostContext2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontext2)