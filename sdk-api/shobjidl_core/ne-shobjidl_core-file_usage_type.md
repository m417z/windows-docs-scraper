# FILE_USAGE_TYPE enumeration

## Description

Constants used by [IFileIsInUse::GetUsage](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileisinuse-getusage) to indicate how a file in use is being used.

## Constants

### `FUT_PLAYING:0`

The file is being played by the process that has it open.

### `FUT_EDITING`

The file is being edited by the process that has it open.

### `FUT_GENERIC`

The file is open in the process for an unspecified action or an action that does not readily fit into the other two categories.

## Remarks

The interpretation of "playing" or "editing" is left to the application's implementation of [IFileIsInUse](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileisinuse). Generally, "playing" would refer to a media file while "editing" can refer to any file being altered in an application. However, the application itself best knows how to map these terms to its actions.