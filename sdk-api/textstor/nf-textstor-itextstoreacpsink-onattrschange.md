# ITextStoreACPSink::OnAttrsChange

## Description

Called when the value of one or more text attribute changes.

## Parameters

### `acpStart` [in]

Specifies the starting point of the attribute change.

### `acpEnd` [in]

Specifies the ending point of the attribute change.

### `cAttrs` [in]

Specifies the number of attributes in the *paAttrs* array.

### `paAttrs` [in]

Pointer to an array of [TS_ATTRID](https://learn.microsoft.com/windows/desktop/TSF/ts-attrid) values that identify the attributes changed.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |