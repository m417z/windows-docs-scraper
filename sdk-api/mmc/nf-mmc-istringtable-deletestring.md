# IStringTable::DeleteString

## Description

The **IStringTable::DeleteString** method enables a snap-in to delete a specified string from the snap-in string table.

## Parameters

### `StringID` [in]

The string to be deleted from the snap-in string table.

## Return value

This method can return one of these values.

## Remarks

Strings in the string table are reference counted. For example, adding the string "My Text" to the string table will return an ID, such as 1234. Adding "My Text" to the string table a second time will return an ID of 1234 again, and the internal reference count for the string will be incremented. Two calls to **IStringTable::DeleteString** will be required to completely remove "My Text" from the snap-in string table.

## See also

[IStringTable](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-istringtable)

[IStringTable::AddString](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-istringtable-addstring)

[IStringTable::DeleteAllStrings](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-istringtable-deleteallstrings)