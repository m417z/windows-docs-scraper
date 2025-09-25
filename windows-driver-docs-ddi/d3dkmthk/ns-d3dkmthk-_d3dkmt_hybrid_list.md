# _D3DKMT_HYBRID_LIST structure

## Description

Describes the Direct 3D kernel mode hybrid list.

## Members

### `State`

The GPU preference query state.

### `AdapterLuid` [in,opt]

Adapter LUID to per-adapter DList state. Optional, if *bUserPreferenceQuery* is true.

For more info about DList, see *Setting up the dList DLL* in [Hybrid system DDI](https://learn.microsoft.com/windows-hardware/drivers/display/hybrid-system-ddi).

### `bUserPreferenceQuery`

Indicates whether the structure is referring to user GPU preference, or per-adapter DList query.

### `QueryType`

## Remarks

## See also