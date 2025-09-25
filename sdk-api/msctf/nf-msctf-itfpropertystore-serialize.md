# ITfPropertyStore::Serialize

## Description

Called to write the property store data into a stream for serialization.

## Parameters

### `pStream` [in]

Pointer to an **IStream** object that the property store data is written to.

### `pcb` [out]

Pointer to a **ULONG** value that receives the number of bytes written to the stream.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

The method must not move the stream insertion point before writing to the stream. The method must leave the insertion point at the end of the data written by the method.