# PAGERANGE structure

## Description

Specifies a range of pages.

## Members

### `nFromPage`

The first page of the range. This member can have any page number as a value. If this value is greater than the value specified in **nToPage**, the document will be printed in reverse page order.

### `nToPage`

The last page of the range. A special value, **PAGESET_TOLASTPAGE**, indicates that all the remaining pages should be printed. This member can have any page number as a value. If this value is less than the value specified in **nFromPage**, the document will be printed in reverse page order.

## See also

[PAGESET](https://learn.microsoft.com/windows/desktop/api/docobj/ns-docobj-pageset)