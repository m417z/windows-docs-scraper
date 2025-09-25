# IStringTable::AddString

## Description

The **IStringTable::AddString** method enables a snap-in to add a string to the snap-in's string table.

## Parameters

### `pszAdd` [in]

The string to add to the string table.

### `pStringID` [out]

A pointer to the ID of the string added to the string table.

## Return value

This method can return one of these values.

## Remarks

Strings in the string table are reference counted. For example, adding the string "My Text" to the string table will return an ID, say 1234. Adding "My Text" to the string table a second time will return an ID of 1234 again, and the internal reference count for the string will be incremented. Two calls to
[IStringTable::DeleteString](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-istringtable-deletestring), or a single call to
[IStringTable::DeleteAllStrings](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-istringtable-deleteallstrings), will be required to completely remove "My Text" from the snap-in's string table.

**IStringTable::AddString** returns a nonzero string ID if the call to it was successful. Snap-ins therefore can safely use 0 to indicate an unassigned ID.

## See also

[IStringTable](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-istringtable)

[IStringTable::DeleteAllStrings](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-istringtable-deleteallstrings)

[IStringTable::DeleteString](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-istringtable-deletestring)