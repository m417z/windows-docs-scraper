# KSBUFFER_ITEM structure

## Description

The KSBUFFER_ITEM structure is used to store a list of data buffers copied from the event source, which can be retrieved by the event sink through KSEVENT_TYPE_QUERYBUFFER.

## Members

### `DpcItem`

A structure of type [KSDPC_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdpc_item). May be used by internal DPCs; do not use for data buffering.

### `BufferList`

Specifies the head of a list of pool allocated buffers that are created by calls to [KsGenerateDataEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgeneratedataevent) for events that have buffering enabled.

## Remarks

KSBUFFER_ITEM extends the normal deferred procedure call (DPC) structure, which may be needed for event generation, but does not use the structure itself.

## See also

[KSDPC_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdpc_item)

[KsGenerateDataEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgeneratedataevent)