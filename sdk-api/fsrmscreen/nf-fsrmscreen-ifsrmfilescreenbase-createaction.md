# IFsrmFileScreenBase::CreateAction

## Description

Creates an action for this file screen object. The action is triggered when a file
violates the file screen.

## Parameters

### `actionType` [in]

The type of action to create. For possible values, see the
[FsrmActionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmactiontype) enumeration.

### `action` [out]

An [IFsrmAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmaction) interface to the newly created action.
Query the interface for the specific action specified. For example, if *actionType* is
**FsrmActionType_Command**, query *action* for the
[IFsrmActionCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmactioncommand) interface.

## Return value

The method returns the following return values.

## Remarks

You can specify up to four unique actions for each file screen.

The action is deleted if the file screen is deleted.

#### Examples

For an example, see
[Performing Actions Based on File Screen Violations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/performing-actions-based-on-file-screen-violations).

## See also

[IFsrmFileScreenBase](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreenbase)