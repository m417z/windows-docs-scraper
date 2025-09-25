# ITfFunctionProvider::GetType

## Description

Obtains the type identifier for the function provider.

## Parameters

### `pguid` [out]

Pointer to a GUID value that receives the type identifier of the function provider.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful |
| **E_INVALIDARG** | *pguid* is invalid. |