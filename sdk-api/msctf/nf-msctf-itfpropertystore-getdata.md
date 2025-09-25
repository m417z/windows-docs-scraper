# ITfPropertyStore::GetData

## Description

Obtains the property store data.

## Parameters

### `pvarValue` [out]

Pointer to a **VARIANT** value that receives property data.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pvarValue* is invalid. |
| **E_FAIL** | An unspecified error occurred. |