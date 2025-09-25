# IFsrmFileScreenBase::EnumActions

## Description

Enumerates all the actions for the file screen object.

## Parameters

### `actions` [out]

An [IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection) interface that contains a collection of actions that are defined for the object.

Each item of the collection is a **VARIANT** of type **VT_DISPATCH**. Query the **pdispVal** member for the [IFsrmAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmaction) interface. You can then use the [IFsrmAction::ActionType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmaction-get_actiontype) property to determine the type of action.

## Return value

The method returns the following return values.

## See also

[IFsrmFileScreenBase](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreenbase)