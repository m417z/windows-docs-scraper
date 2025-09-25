## Description

Describes features of an effect.

## Members

### `effect`

The effect whose input connection is being specified.

### `inputIndex`

The input index of the effect that is being considered.

### `inputRectangle`

The amount of data that would be available on the input. This can be used to query this information when the data is not yet available.

## Remarks

> [!NOTE]
> You shouldn't rely heavily on the input rectangles returned by this structure. They can change due to subtle changes in effect implementations, and due to optimization changes in the effect rendering system.