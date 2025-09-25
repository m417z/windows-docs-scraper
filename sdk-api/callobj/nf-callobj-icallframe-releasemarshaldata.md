# ICallFrame::ReleaseMarshalData

## Description

Releases resources that are held by interface pointers residing in a packet of marshaled data. This method finds all interface pointers in the packet, and calls the [CoReleaseMarshalData](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreleasemarshaldata) function on each one.

## Parameters

### `pBuffer` [in]

A pointer to the buffer containing the marshaled [out] values.

### `cbBuffer` [in]

The size of the buffer, in bytes.

### `ibFirstRelease` [in]

The first byte in the buffer, which is to be released. A value of zero implies that the interface pointers in the whole buffer are to be released. The marshaled interface pointers are assumed to have been released by some other mechanism.

### `dataRep` [in]

The data representation with which the data was marshaled.

### `pcontext` [in]

A pointer to the [CALLFRAME_MARSHALCONTEXT](https://learn.microsoft.com/windows/win32/api/callobj/ns-callobj-callframe_marshalcontext) structure containing context information about how un-marshalling is carried out.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

The **ReleaseMarshalData** method must be called exactly once to clean up the resources held in a marshaled buffer. However when the [MSHLFLAGS](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshlflags) enumeration is set to MSHLFLAGS_NORMAL, this is done automatically during un-marshaling and so need not be carried out explicitly.

This method can function correctly on both marshaled [in] and [out] parameters.

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)