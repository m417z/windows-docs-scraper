# ICallUnmarshal::Unmarshal

## Description

Turns a marshaled packet of data back into an activation record that can then be invoked or manipulated in some other way.

## Parameters

### `iMethod` [in]

The method number. If this parameter is -1, the method number will be determined from the data to be unmarshaled.

### `pBuffer` [in]

A pointer to the buffer from which the activation record is to be created.

### `cbBuffer` [in]

The size of the buffer, in bytes.

### `fForceBufferCopy` [in]

Indicates whether the buffer should be copied and retained (nonzero) or the buffer will remain valid (zero).

### `dataRep` [in]

The data representation with which the data was marshaled.

### `pcontext` [in]

A pointer to a [CALLFRAME_MARSHALCONTEXT](https://learn.microsoft.com/windows/win32/api/callobj/ns-callobj-callframe_marshalcontext) structure that contains information about the context in which unmarshaling is to be carried out.

### `pcbUnmarshalled` [out]

A pointer to the number of bytes that were successfully unmarshaled.

### `ppFrame` [out]

A call frame bound to the umarshaled invocation.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallUnmarshal](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallunmarshal)