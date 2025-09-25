# ICallUnmarshal::ReleaseMarshalData

## Description

Releases resources that may be held by interface pointers residing in a packet of marshaled data. This method finds all interface pointers in the packet and calls the [CoReleaseMarshalData](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreleasemarshaldata) function on each interface pointer.

## Parameters

### `iMethod` [in]

The method number.

### `pBuffer` [in]

A pointer to the buffer containing the marshaled out parameters.

### `cbBuffer` [in]

The size of the buffer, in bytes.

### `ibFirstRelease` [in]

The first byte in the buffer to be released. A value of zero implies that the interface pointers in the whole buffer are to be released. The idea is that marshaled interface pointers prior to the indicated byte are assumed to have already been released by some other mechanism.

### `dataRep` [in]

The data representation with which the data was marshaled.

### `pcontext` [in]

A pointer to a [CALLFRAME_MARSHALCONTEXT](https://learn.microsoft.com/windows/win32/api/callobj/ns-callobj-callframe_marshalcontext) structure that contains information about the context in which unmarshaling is to be carried out.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

To clean up resources held in the marshaled buffer, the **ReleaseMarshalData** method must be called. However when the [MSHLFLAGS](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshlflags) enumeration is set to normal, this is done automatically when unmarshaling.

**ReleaseMarshalData** can be used on both marshaled in and out parameters.

## See also

[ICallUnmarshal](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallunmarshal)