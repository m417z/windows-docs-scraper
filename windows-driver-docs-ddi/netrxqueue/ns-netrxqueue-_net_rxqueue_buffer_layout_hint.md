# _NET_RXQUEUE_BUFFER_LAYOUT_HINT structure

## Description

The **NET_RXQUEUE_BUFFER_LAYOUT_HINT** structure represents receive buffer layout hints returned to a client driver from the upper layer.

## Members

### `MinimumBackfillSize`

The minimum space that should be unused in the beginning of the first fragment of the ring buffer.

### `L3HeaderAlignment`

The ideal alignment for the start of the L3 header. This member's value is in the form *N-1*, where *N* is the alignment. For example, TCP/IP performance is optimized with a 4-byte alignment boundary, so this member would be set to 3 in that case. You can use the **FILE_XXX_ALIGNMENT** constants, such as **FILE_QUAD_ALIGNMENT**, to name a specific alignment.

## Remarks

The information in this structure is set by the upper layer.

## See also