# CreateContext function

## Description

Creates a recognizer context.

## Parameters

### `hrec`

Handle to the recognizer.

### `phrc`

Pointer to the recognizer context.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |
| **E_POINTER** | The parameter is an invalid pointer. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete the operation. |
| **E_INVALIDARG** | An invalid argument was received. |