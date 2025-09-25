# CombineMode enumeration

## Description

The **CombineMode** enumeration specifies how a new region is combined with an existing region.

## Constants

### `CombineModeReplace`

Specifies that the existing region is replaced by the new region.

### `CombineModeIntersect`

Specifies that the existing region is replaced by the intersection of itself and the new region.

### `CombineModeUnion`

Specifies that the existing region is replaced by the union of itself and the new region.

### `CombineModeXor`

Specifies that the existing region is replaced by the result of performing an
**XOR** on the two regions. A point is in the
**XOR** of two regions if it is in one region or the other but not in both regions.

### `CombineModeExclude`

Specifies that the existing region is replaced by the portion of itself that is outside of the new region.

### `CombineModeComplement`

Specifies that the existing region is replaced by the portion of the new region that is outside of the existing region.