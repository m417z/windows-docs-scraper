# _PATH_OFFLOAD_STATE_DELEGATED structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The PATH_OFFLOAD_STATE_DELEGATED structure contains the delegated variables of a path state
object.

## Members

### `Header`

An
[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header) structure. NDIS
sets the
**Length** member of
**Header** to the size, in bytes, of the PATH_OFFLOAD_STATE_DELEGATED structure. The
**RecognizedOptions** member of
**Header** is reserved.

## Remarks

Currently there are no delegated path variables.

## See also

[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header)

[PATH_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_cached)

[PATH_OFFLOAD_STATE_CONST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_path_offload_state_const)