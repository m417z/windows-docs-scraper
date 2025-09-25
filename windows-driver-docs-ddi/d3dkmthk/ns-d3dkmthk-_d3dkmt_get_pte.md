# _D3DKMT_GET_PTE structure

## Description

Used to get page table entries (PTE).

## Members

### `PhysicalAdapterIndex`

The physical adapter index in the LDA (linked display adapter) chain.

### `PageTableLevel`

The page table level.

### `PageTableIndex`

The page table index.

### `b64KBPte`

Indicates whether the page table is 64KB. This value is valid only when dual PTEs are supported.

### `NumPtes`

The number of PTEs to fill.

### `Pte`

An array of PTEs.

### `NumValidEntries`

The number of valid entries.

## Remarks

## See also