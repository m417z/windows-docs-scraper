# LINEFORWARDLIST structure

## Description

The
**LINEFORWARDLIST** structure describes a list of forwarding instructions. This structure can contain an array of
[LINEFORWARD](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforward) structures. The
[lineForward](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineforward) and
[TSPI_lineForward](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineforward) functions use the
**LINEFORWARDLIST** structure.

## Members

### `dwTotalSize`

Total size of the data structure, in bytes.

### `dwNumEntries`

Number of entries in the array specified as **ForwardList[]**.

### `ForwardList`

Array of forwarding instruction. The array's entries are of type
[LINEFORWARD](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforward).

## Remarks

This structure may not be extended.

The
**LINEFORWARDLIST** structure defines the forwarding parameters requested for forwarding calls on an address or on all addresses on a line.

## See also

[LINEFORWARD](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforward)

[TSPI_lineForward](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineforward)

[lineForward](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineforward)