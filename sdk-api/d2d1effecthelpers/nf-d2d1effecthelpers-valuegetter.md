# ValueGetter function

## Description

Calls a member-function property setter callback for a value-type property.

## Parameters

### `effect` [in]

The effect with the property.

### `data` [out, optional]

When this method returns, contains a pointer to the data requested.

### `dataSize`

The number of bytes in the data to be retrieved.

### `actualSize` [out, optional]

The actual size of the data, if the data is not measured in bytes.

### `unnamedParam5`

TBD

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.