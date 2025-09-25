# StringGetter function

## Description

Calls a member-function property getter callback for a string-type property.

## Parameters

### `effect` [in]

Type: **const IUnknown***

The effect with the property.

### `data` [out, optional]

Type: **BYTE***

When this method returns, contains a pointer to the data requested.

### `dataSize`

Type: **UINT32**

The number of bytes in the data to be retrieved.

### `actualSize` [out, optional]

Type: **UINT32***

The actual size of the data, if the data is not measured in bytes.

### `unnamedParam5`

TBD

## Return value

Type: **HRESULT CALLBACK**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.