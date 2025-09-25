## Description

Compares two entry identifiers.

## Parameters

### `cbEntryID1`

Value of type ULONG that specifies the number of bytes in the entry identifier to which the *lpEntryID1* parameter points.

### `lpEntryID1`

Pointer to a variable of type ENTRYID that specifies the first entry identifier to be compared.

### `cbEntryID2`

Value of type ULONG that specifies the number of bytes in the entry identifier to which the *lpEntryID2* parameter points.

### `lpEntryID2`

Pointer to a variable of type ENTRYID that specifies the first entry identifier to be compared.

### `ulFlags`

Reserved. Must be set to 0.

### `lpulResult`

Pointer to a variable of type ULONG that receives the result of the comparison. The contents of *lpulResult* are set to TRUE if the two entry identifiers refer to the same object, FALSE otherwise.

## Return value

HRESULT

## Remarks

## See also