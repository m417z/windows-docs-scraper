# IsDsmActionNonDestructive macro

## Description

The **IsDsmActionNonDestructive** macro determines whether a data set management (DSM) action is nondestructive.

## Parameters

### `_Action`

The **DeviceDsmAction_*Xxx*** action to be performed. DSM action values are defined in *ntddstor.h*.

## Remarks

**IsDsmActionNonDestructive** returns **TRUE** if the action is nondestructive or **FALSE** if the action is destructive.

## See also