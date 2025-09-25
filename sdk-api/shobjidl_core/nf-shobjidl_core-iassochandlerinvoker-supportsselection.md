# IAssocHandlerInvoker::SupportsSelection

## Description

Determines whether an invoker supports its selection.

## Return value

Type: **HRESULT**

Returns **S_OK** if this instance supports its selection, or **S_FALSE** otherwise.

## Remarks

For example, this method should return whether an application (as selected from an "Open With" context menu) can **Open** a file.