# ITfPropertyStore::GetType

## Description

Obtains the property identifier.

## Parameters

### `pguid` [out]

Pointer to a **GUID** value that receives the property identifier.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pguid* is invalid. |
| **E_FAIL** | An unspecified error occurred. |