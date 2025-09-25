# _DXGKARG_READVIRTUALFUNCTIONCONFIG structure

## Description

Arguments used to read virtual function config.

## Members

### `Data`

A buffer which will contain the data read from the Virtual Function’s configuration space.

### `VirtualFunctionIndex`

Zero-based offset of the Virtual Function from the first VF exposed by this Physical Function.

### `Offset`

The offset into the Virtual Function’s configuration space where this read will begin.

### `Length`

The length in bytes.

## Remarks

## See also