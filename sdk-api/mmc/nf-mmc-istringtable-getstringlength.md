# IStringTable::GetStringLength

## Description

The **IStringTable::GetStringLength** method enables a snap-in to determine the length of a string in the snap-in's string table.

## Parameters

### `StringID` [in]

The identifier for the string whose length is being retrieved.

### `pcchString` [out]

The number of characters in the specified string in the snap-in's string table, not including the terminator.

## Return value

This method can return one of these values.

## Remarks

Use this method to determine the size of the buffer required for
[IStringTable::GetString](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-istringtable-getstring).

## See also

[IStringTable](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-istringtable)

[IStringTable::GetString](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-istringtable-getstring)