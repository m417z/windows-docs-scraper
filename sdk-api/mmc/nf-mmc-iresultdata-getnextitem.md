# IResultData::GetNextItem

## Description

The **IResultData::GetNextItem** method gets the next item in the result view with the specified state flags set.

## Parameters

### `item` [in, out]

A pointer to a
[RESULTDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-resultdataitem) structure that contains information about the item to be obtained. The **nIndex** member should be set to the index at which to start the search, or to –1 to start at the first item. The specified index is excluded from the search. The **nState** member should specify which state flags must be set on the returned item.

The **nIndex** member will be updated to the index of the found item (or –1, if none is found). The **bScopeItem** and **lParam** members will be set according to the found item.

## Return value

This method can return one of these values.

## Remarks

When applied to virtual lists, only the **LVIS_FOCUSED** and **LVIS_SELECTED** state flags can specified. The **lParam** member is always set to 0 (zero).

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)