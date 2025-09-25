# ICategorizer::GetCategory

## Description

Gets a list of categories associated with a list of identifiers.

## Parameters

### `cidl` [in]

Type: **UINT**

The number of items in an item identifier list array.

### `apidl` [in]

Type: **PCUITEMID_CHILD_ARRAY***

A pointer to an array of *cidl* item identifier list pointers.

### `rgCategoryIds` [out]

Type: **DWORD***

When this method returns, contains a pointer to an array of *cidl* category identifiers.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **ICategorizer::GetCategory** method accepts an array of pointers to item identifier lists (PIDLs) and fills an array of category identifiers.

**Important** The value -1 is an invalid category identifier.