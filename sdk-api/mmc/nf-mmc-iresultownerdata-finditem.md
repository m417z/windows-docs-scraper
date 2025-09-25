# IResultOwnerData::FindItem

## Description

The **IResultOwnerData::FindItem** method finds the next item in a virtual list matching a specified string.

## Parameters

### `pFindInfo` [in]

A pointer to the
[RESULTFINDINFO](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-resultfindinfo) structure.

### `pnFoundIndex` [out]

A pointer to the returned index of the item found. The value is –1 if no items are found.

## Return value

This method can return one of these values.

## Remarks

Because the snap-in maintains all the item data for a virtual list, the snap-in must implement
FindItem to allow navigation by partial name typing. The console calls
FindItem to find the next match each time the user types a printable character. The console handles the character accumulation and timing functions, passing the snap-in the current partial name in each
FindItem call.

## See also

[RESULTFINDINFO](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-resultfindinfo)