# IOleUndoManager::Enable

## Description

Enables or disables the undo manager.

## Parameters

### `fEnable` [in]

Indicates whether to enable or disable the undo manager. If **TRUE**, the undo manager should be enabled. If **FALSE**, the undo manager should be disabled.

## Return value

This method returns S_OK if the undo manager was successfully enabled or disabled. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | There is an open undo unit on the stack or the undo manager is currently performing an undo or a redo. |

## Remarks

The undo manager should clear both stacks when making the transition from enabled to disabled.

If the undo manager is disabled, each method in [IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager) must behave as specified. See each method for details.

## See also

[IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager)