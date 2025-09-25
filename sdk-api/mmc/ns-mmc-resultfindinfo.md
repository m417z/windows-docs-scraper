# RESULTFINDINFO structure

## Description

The
**RESULTFINDINFO** structure is used by the
[IResultOwnerData::FindItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultownerdata-finditem) method to support keyboard navigation in virtual lists in the result pane.

## Members

### `psz`

Null-terminated string to match.

### `nStart`

Index at which to start search.

### `dwOptions`

One or both of the following flags:

#### RFI_PARTIAL

Match item names that begin with psz.

#### RFI_WRAP

Continue search at beginning of list if no match is found.

## See also

[IResultOwnerData::FindItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultownerdata-finditem)