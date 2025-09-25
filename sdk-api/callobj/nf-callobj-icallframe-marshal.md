# ICallFrame::Marshal

## Description

Marshals the call frame by turning its reachable data into a flat buffer without disturbing the frame.

## Parameters

### `pmshlContext` [in]

A pointer to the [CALLFRAME_MARSHALCONTEXT](https://learn.microsoft.com/windows/win32/api/callobj/ns-callobj-callframe_marshalcontext) structure containing context information about how marshalling is carried out.

### `mshlflags` [in]

Flag indicating whether the data to be marshaled is to be transmitted back to the client process - the normal case - or written to a global table, where it can be retrieved by multiple clients. The possible values are from the [MSHLFLAGS](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshlflags) enumeration.

### `pBuffer` [in]

A pointer to the buffer into which the marshaled data is to be placed.

### `cbBuffer` [in]

The size of the buffer, in bytes.

### `pcbBufferUsed` [out]

Receives the size of the buffer that was actually used. This parameter is optional.

### `pdataRep` [out]

Receives the NDR data representation with which the data was marshaled. This parameter is optional. For more information, see [IRpcChannelBuffer::GetBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irpcchannelbuffer-getbuffer).

### `prpcFlags` [out]

Receives an RPC flag associated with the call. This parameter is optional. For more information, see [IRpcChannelBuffer::GetBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irpcchannelbuffer-getbuffer).

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

When marshalling the [In] versions of [in, out] parameters are present, and the [out] versions are undefined. When marshalling [out] parameters the values are valid.

If this method returns an error, the caller will not be able to clean it up. Resources such as memory transiently allocated during the attempted marshalling have been freed.

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)