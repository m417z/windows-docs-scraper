# RoGetBufferMarshaler function

## Description

Provides a standard IBuffer marshaler to implement the semantics associated with the IBuffer interface when it is marshaled.

## Parameters

### `bufferMarshaler` [out]

pointer to Windows Runtime IBuffer marshaler

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Provided for Windows Runtime language projections.

Custom IBuffer implementations are expected to be marshaled so that the remote instance eventually copies its contents back to the original instance. The [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) implementation provided by this method handles the copy by marshaling the current value of the IBuffer and specifying a platform-provided unmarshal COM class that creates an instance with identical IBuffer contents, length, and capacity.

The [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) implementation clones its contents to the original instance when the caller sets the Length property.

## See also

[IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal)