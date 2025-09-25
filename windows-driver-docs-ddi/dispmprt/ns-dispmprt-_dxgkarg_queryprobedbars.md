# _DXGKARG_QUERYPROBEDBARS structure

## Description

Query probed base address registers (BARS).

## Members

### `VirtualFunctionIndex`

Zero-based offset of the Virtual Function from the first VF exposed by this Physical Function.

### `BaseRegisterValues`

Pointer to an array of ULONGs bounded by the number of Base Address Registers in a PCI device (currently 6). The driver should fully fill in this array, even if the values are 0. These values represent the PCIe BAR sizes in bytes. The returned value should be the size, minus -1, and then bitwise not. For example, a 256MB BAR is represented as 0xF000`0000. This is the same way the PCI bus enumerates BAR sizes. For 64 bit bars (or bars larger than 4GB) two sequential bars are used, with the lower bar setting the PCI_TYPE_64BIT (0x4) bit in the lower bar.

## Remarks

## See also