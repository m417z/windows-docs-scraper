# FsrmAccountType enumeration

## Description

Defines the computer account types under which a command action (see
[FsrmActionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmactiontype)) can run.

## Constants

### `FsrmAccountType_Unknown:0`

The account type is unknown. Do not use this value to set the
[IFsrmActionCommand::Account](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmactioncommand-get_account) property.

### `FsrmAccountType_NetworkService:1`

Run the command or pipeline module under the "NetworkService" account.

### `FsrmAccountType_LocalService:2`

Run the command or pipeline module under the "LocalService" account.

### `FsrmAccountType_LocalSystem:3`

Run the command or pipeline module under the "LocalSystem" account.

### `FsrmAccountType_InProc:4`

This value is reserved for internal use.

### `FsrmAccountType_External:5`

Run the classifier or storage module in a separate process from FSRM (FSRM uses
**CLSCTX_LOCAL_SERVER** to instantiate the module). The module's COM registration
specifies the account used to run the module. If the registration does not specify the account, the module is
run using the user's account.

### `FsrmAccountType_Automatic:500`

Run the command or pipeline module under the account that FSRM selects. This is the recommended value.

**Windows Server 2008 R2 and Windows Server 2008:** This enumeration value is not supported before Windows Server 2012.

## See also

[FSRM Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-enumerations)

[FsrmActionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmactiontype)

[IFsrmActionCommand.Account](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmactioncommand-get_account)

[IFsrmPipelineModuleDefinition.Account](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpipelinemoduledefinition-get_account)