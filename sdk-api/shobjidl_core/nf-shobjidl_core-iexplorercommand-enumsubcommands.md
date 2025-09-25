# IExplorerCommand::EnumSubCommands

## Description

Retrieves an enumerator for a command's subcommands.

## Parameters

### `ppEnum` [out]

Type: **[IEnumExplorerCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumexplorercommand)****

When this method returns successfully, contains an [IEnumExplorerCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumexplorercommand) interface pointer that can be used to walk the set of subcommands.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Subcommands are displayed as menu drop-down items through the use of a Split button when commands are exposed at the top of a Windows Explorer window. In that position, only the default command button is given an icon. In a normal menu, the icons for all commands are shown.

Subcommands which themselves have subcommands are not supported by Windows Explorer. When a command has its own subcommands, it must designate this status by specifying ECF_HASSUBCOMMANDS in the [IExplorerCommand::GetFlags](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorercommand-getflags) call.