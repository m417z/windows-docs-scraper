# IEnumFullIDList::Skip

## Description

Skips a specified number of IDLIST_ABSOLUTE items.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of items to skip.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The enumeration index is advanced by the number of items skipped.