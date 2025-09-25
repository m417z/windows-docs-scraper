# _SECURE_ELEMENT_ROUTING_TABLE structure

## Description

SECURE_ELEMENT_ROUTING_TABLE is an input parameter for [IOCTL_NFCSE_SET_ROUTING_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ni-nfcsedev-ioctl_nfcse_set_routing_table).

## Members

### `NumberOfEntries`

Number of routing table entries.

### `TableEntries[ANYSIZE_ARRAY]`

Listen mode routing table.