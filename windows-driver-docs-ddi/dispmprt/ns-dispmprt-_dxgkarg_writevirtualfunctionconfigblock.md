# _DXGKARG_WRITEVIRTUALFUNCTIONCONFIGBLOCK structure

## Description

Used to write a virtual function configuration block.

## Members

### `Data`

A buffer which will contain the data read from the Virtual Function’s configuration space.

### `VirtualFunctionIndex`

Zero-based offset of the Virtual Function from the first VF exposed by this Physical Function.

### `BlockId`

Number identifying the block to be written. This is defined by the provider of the Physical Function driver.

### `Length`

The length in bytes.

## Remarks

## See also