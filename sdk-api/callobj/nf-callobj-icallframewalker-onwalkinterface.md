# ICallFrameWalker::OnWalkInterface

## Description

Walks through a call frame to look for the specified interface in the call frame. The interface can be manipulated or replaced by paying close attention to the reference count.

## Parameters

### `iid` [in]

The IID of the interface to be found.

### `ppvInterface` [in]

A points to the buffer from which the activation record is to be reconstituted.

### `fIn` [in]

This parameter is nonzero if an interface is inside an [in] or [in, out] parameter.

### `fOut` [in]

This parameter is nonzero if an interface is inside an [out] or [in, out] parameter.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallFrameWalker](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframewalker)