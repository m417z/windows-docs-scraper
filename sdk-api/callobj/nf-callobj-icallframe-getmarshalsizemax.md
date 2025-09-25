# ICallFrame::GetMarshalSizeMax

## Description

Retrieves an upper bound on the number of bytes needed to marshal the call frame.

Usually an interface proxy calls this method to learn how big a buffer is needed, allocates the buffer, and then calls the [Marshal](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframe-marshal) method to carry out the marshalling.

## Parameters

### `pmshlContext` [in]

A pointer to the [CALLFRAME_MARSHALCONTEXT](https://learn.microsoft.com/windows/win32/api/callobj/ns-callobj-callframe_marshalcontext) structure containing context information about how marshalling is carried out.

### `mshlflags` [in]

Indicates whether the data to be marshaled is to be transmitted back to the client process - the normal case - or written to a global table, where it can be retrieved by multiple clients. For a list of values, see the [MSHLFLAGS](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshlflags) enumeration.

### `pcbBufferNeeded` [out]

A pointer to the size of the buffer, in bytes, that will be needed to marshal the call frame.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)