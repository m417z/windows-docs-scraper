# ICallFrame::WalkFrame

## Description

Searches for interface pointers that are reachable from [in], [in, out], or [out] parameters of the frame.

## Parameters

### `walkWhat` [in]

Flags from the [CALLFRAME_WALK](https://learn.microsoft.com/windows/desktop/api/callobj/ne-callobj-callframe_walk) enumeration.

### `pWalker` [in]

A pointer to an instance of the [ICallFrameWalker](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframewalker) interface. When specified, a call back is made for each interface pointer encountered. This parameter is optional.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe)