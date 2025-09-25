# _DXGKARG_WRITEVIRTUALFUNCTIONCONFIG structure

## Description

Used to write a virtual function configuration.

## Members

### `Data`

A buffer which will contain the data read from the Virtual Function’s configuration space.

### `VirtualFunctionIndex`

Zero-based offset of the Virtual Function from the first VF exposed by this Physical Function.

### `Offset`

The offset into the Virtual Function’s configuration space where this write will begin.

### `Length`

The length of *Data*.

## Remarks

## See also