# LoadCachedAttributes function

## Description

Loads the cached attributes of a recognizer.

## Parameters

### `clsid`

The CLSID of the recognizer. This value is created in the registry when you register the recognizer.

### `pRecoAttributes`

Pointer to the recognizer attributes.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | The parameter is an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |