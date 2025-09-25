# StringSetter function

## Description

Calls a member-function property setter callback for a string-type property.

## Parameters

### `effect` [in]

Type: **IUnknown***

The effect with the property.

### `data` [in]

Type: **const BYTE***

When this method returns, contains a pointer to the data requested.

### `dataSize`

Type: **UINT32**

The number of bytes in the data to be retrieved.

### `unnamedParam4`

TBD

## Return value

Type: **HRESULT CALLBACK**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.