# OMAP structure

## Description

Describes an entry in an address map.

## Members

### `rva`

A relative virtual address (RVA) in image A.

### `rvaTo`

The relative virtual address that **rva** is mapped to in image B.

## Remarks

An address map provides a translation from one image layout (A) to another (B). An array of OMAP structures, sorted by **rva**, defines an address map.

To translate an address, addrA, in image A to an address, addrB, in image B, perform the following steps:

1. Search the map for the entry, e, with the largest rva less than or equal to addrA.
2. Set delta = addrA – e.rva.
3. Set addrB = e.rvaTo + delta.

## See also

[SymGetOmaps](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetomaps)