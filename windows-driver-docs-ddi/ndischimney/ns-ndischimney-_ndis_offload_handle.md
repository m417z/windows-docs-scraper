# _NDIS_OFFLOAD_HANDLE structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The NDIS_OFFLOAD_HANDLE structure represents a driver's context for an offloaded state object.

## Members

### `NdisReserved`

Reserved for use by NDIS.

### `MiniportOffloadContext`

A pointer that references a host memory location into which the underlying driver writes a PVOID
value when completing the initiate offload operation. This PVOID value references the underlying
driver's offload context for the offloaded state object.

## Remarks

When propagating the offload of a TCP chimney state object, an intermediate driver supplies a pointer
to an NDIS_OFFLOAD_HANDLE structure. This pointer, in effect, references the intermediate driver's
context for the offloaded state object.

The NDIS_OFFLOAD_HANDLE structure contains a
**MiniportOffloadContext** pointer that references a memory location into which the underlying driver
or offload target writes a PVOID value before completing the initiate offload operation. This PVOID value
references the underlying driver's or offload target's context for the offloaded state object.

For more information about the use of the NDIS_OFFLOAD_HANDLE structure, see
[Referencing Offloaded State Through an Intermediate Driver](https://learn.microsoft.com/windows-hardware/drivers/network/referencing-offloaded-state-through-an-intermediate-driver).

## See also

[MiniportInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-w_initiate_offload_handler)

[NdisMInitiateOffloadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisminitiateoffloadcomplete)