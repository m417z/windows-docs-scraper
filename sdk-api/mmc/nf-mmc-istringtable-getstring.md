# IStringTable::GetString

## Description

The **IStringTable::GetString** method enables a snap-in to retrieve a string from the snap-in's string table.

## Parameters

### `StringID` [in]

The ID of the string to be retrieved from the snap-in's string table.

### `cchBuffer` [in]

The number of characters in lpBuffer.

### `lpBuffer` [out]

A pointer to the buffer for the character string.

### `pcchOut` [out]

The number of characters in the retrieved string, not including the NULL terminator. If the number of characters written is not required, pass **NULL** for this parameter.

## Return value

This method can return one of these values.

## Remarks

If lpBuffer is not large enough to hold the entire string corresponding to StringID, as much of the string as will fit is copied to the buffer and is null-terminated.

## See also

[IStringTable](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-istringtable)

[IStringTable::GetStringLength](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-istringtable-getstringlength)