# _DXGK_TRANSFERVIRTUALFLAGS structure

## Description

**DXGK_TRANSFERVIRTUALFLAGS** is used as part of an allocation transfer operation.

## Members

### `Src64KBPages`

When set, the source page tables are mapped to 64KB pages.

### `Dst64KBPages`

When set, the destination page tables are mapped to 64KB pages.

### `Reserved`

This member is reserved and should be set to zero.

### `Flags`

The consolidated value of the structure flags.