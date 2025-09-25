## Description

The **SIMULATE_CAPS_1** structure contains information about the types of simulations a spooler supports.

## Members

### `dwLevel`

Specifies the version of this structure. This value must be 1.

### `dwPageOrderFlags`

Specifies the order in which pages will be printed. This member can be set to one of the following values:

| Flag | Definition |
|--|--|
| BOOKLET_PRINT | Pages should be printed in booklet form, with two document pages printed on one side of a physical page. In landscape mode, the two document pages are printed side-by-side on the paper. In portrait mode, the two document pages are printed top-and-bottom. |
| NORMAL_PRINT | Pages should be printed in normal order: page 1, page 2, and so on. |
| REVERSE_PRINT | Pages should be printed in reverse order: last page, next-to-last page, and so on. |

### `dwNumberOfCopies`

Specifies the maximum number of copies the spooler can handle.

### `dwCollate`

Specifies whether the spooler supports collation. A value of 1 indicates that the spooler supports collation, and a value of 0 indicates that it does not.

### `dwNupOptions`

Is a bitmask representing the various numbers of document pages the printer can print on a physical page. The least significant bit represents 1 document page per page, the next bit represents 2 document pages per page, the next bit represents 3 document pages per physical page, and so on. For example, 0x0000810B indicates that the spooler supports 1, 2, 4, 9, and 16 document pages per physical page.

## Remarks

The **IPrintCoreUI2::QuerySimulationSupport** method uses this structure to report the spooler's level of simulation support to a user-interface plug-in.

## See also

[IPrintCoreUI2::QuerySimulationSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-querysimulationsupport)