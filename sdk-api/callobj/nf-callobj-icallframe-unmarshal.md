# ICallFrame::Unmarshal

## Description

Unmarshals a packet of data containing the previously marshaled [out] parameters of a call into this already existing activation record.

## Parameters

### `pBuffer` [in]

A pointer to the buffer containing the marshaled [out] values.

### `cbBuffer` [in]

The size of the buffer, in bytes.

### `dataRep` [in]

The NDR data representation with which the data was marshaled. For more information, see [IRpcChannelBuffer::GetBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irpcchannelbuffer-getbuffer).

### `pcontext` [in]

A pointer to the [CALLFRAME_MARSHALCONTEXT](https://learn.microsoft.com/windows/win32/api/callobj/ns-callobj-callframe_marshalcontext) structure containing context information about how unmarshalling is carried out.

### `pcbUnmarshalled` [out]

Receives the number of bytes that were successfully unmarshaled. This parameter is returned even in error situations. This parameter is optional.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

When unmarshalling, the [in] versions of [in, out] parameters are freed and interface pointers are released and replaced with their [out] versions. All the [in, out] and [out] parameters will always be set to reasonable [in], [in, out] values, [out] values successfully unmarshaled from the returned data, or a value explicitly initialized to **NULL**. On failure return, the caller will typically want to call [ICallFrame::Free](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframe-free) in order to clean up the values that are not **NULL**.

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)