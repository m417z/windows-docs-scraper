# IExplorerCommand::GetFlags

## Description

Gets the flags associated with a Windows Explorer command.

## Parameters

### `pFlags` [out]

Type: **EXPCMDFLAGS***

When this method returns, this value points to the current command flags. One of more of the following values:

#### ECF_DEFAULT (0x000)

**Windows 7 and later**. No command flags are set.

#### ECF_HASSUBCOMMANDS (0x001)

The command has subcommands.

#### ECF_HASSPLITBUTTON (0x002)

A split button is displayed.

#### ECF_HIDELABEL (0x004)

The label is hidden.

#### ECF_ISSEPARATOR (0x008)

The command is a separator.

#### ECF_HASLUASHIELD (0x010)

A UAC shield is displayed.

#### ECF_SEPARATORBEFORE (0x020)

**Introduced in Windows 7**. The command is located in the menu immediately below a separator.

#### ECF_SEPARATORAFTER (0x040)

**Introduced in Windows 7**. The command is located in the menu immediately above a separator.

#### ECF_ISDROPDOWN (0x080)

**Introduced in Windows 7**. Selecting the command opens a drop-down submenu (for example, **Include in library**).

#### ECF_TOGGLEABLE (0x100)

**Introduced in Windows 8**.

#### ECF_AUTOMENUICONS (0x200)

**Introduced in Windows 8**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.