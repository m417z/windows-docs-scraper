# _EXPLORERPANESTATE enumeration

## Description

Indicate flags used by [IExplorerPaneVisibility::GetPaneState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerpanevisibility-getpanestate) to get the current state of the given Windows Explorer pane.

## Constants

### `EPS_DONTCARE:0`

Do not make any modifications to the pane.

### `EPS_DEFAULT_ON:0x1`

Set the default state of the pane to "on", but respect any user-modified persisted state.

### `EPS_DEFAULT_OFF:0x2`

Set the default state of the pane to "off".

### `EPS_STATEMASK:0xffff`

Unused.

### `EPS_INITIALSTATE:0x10000`

Ignore any persisted state from the user, but the user can still modify the state.

### `EPS_FORCE:0x20000`

Users cannot modify the state, that is, they do not have the ability to show or hide the given pane. This option implies EPS_INITIALSTATE.