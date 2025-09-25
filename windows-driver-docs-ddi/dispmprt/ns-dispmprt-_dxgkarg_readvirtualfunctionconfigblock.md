# _DXGKARG_READVIRTUALFUNCTIONCONFIGBLOCK structure

## Description

Arguments used to read virtual function config block.

## Members

### `Data`

A buffer which will contain the data read from the Virtual Function’s configuration space.

### `VirtualFunctionIndex`

Zero-based offset of the Virtual Function from the first VF exposed by this Physical Function.

### `BlockId`

Number identifying the block to be read. This is defined by the provider of the Physical Function driver.

### `Length`

The length in bytes.

## Remarks

## See also