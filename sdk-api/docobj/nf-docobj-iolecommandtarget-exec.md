# IOleCommandTarget::Exec

## Description

Executes the specified command or displays help for the command.

## Parameters

### `pguidCmdGroup` [in]

The unique identifier of the command group; can be **NULL** to specify the standard group.

### `nCmdID` [in]

The command to be executed. This command must belong to the group specified with *pguidCmdGroup*.

### `nCmdexecopt` [in]

Specifies how the object should execute the command. Possible values are taken from the [OLECMDEXECOPT](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdexecopt) and [OLECMDID_WINDOWSTATE_FLAG](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdid_windowstate_flag) enumerations.

### `pvaIn` [in]

A pointer to a [VARIANTARG](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-variant) structure containing input arguments. This parameter can be **NULL**.

### `pvaOut` [in, out]

Pointer to a VARIANTARG structure to receive command output. This parameter can be **NULL**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLECMDERR_E_UNKNOWNGROUP** | The *pguidCmdGroup* parameter is not **NULL** but does not specify a recognized command group. |
| **OLECMDERR_E_NOTSUPPORTED** | The *nCmdID* parameter is not a valid command in the group identified by *pguidCmdGroup*. |
| **OLECMDERR_E_DISABLED** | The command identified by *nCmdID* is currently disabled and cannot be executed. |
| **OLECMDERR_E_NOHELP** | The caller has asked for help on the command identified by *nCmdID*, but no help is available. |
| **OLECMDERR_E_CANCELED** | The user canceled the execution of the command. |

## Remarks

The list of input and output arguments of a command and how they are packaged is unique to each command. Such information should be documented with the specification of the command group. (See the description of OLECMDID_ZOOM in the [OLECMDID](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdid) enumeration.) In the absence of any specific information the command is assumed to take no arguments and have no return value.

### Notes to Callers

The *pguidCmdGroup* and *nCmdID* parameters together uniquely identify the command to invoke. The *nCmdExecOpt* parameter specifies the exact action to be taken. (See the [OLECMDEXECOPT](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdexecopt) enumeration for more details.)

Most commands neither take arguments nor return values. For such commands, the caller can pass **NULL** in *pvaIn* and *pvaOut*. For commands that expect one or more input values, the caller can declare and initialize a VARIANTARG variable and pass a pointer to that variable in pvaIn. If the input to the command is a single value, the argument can be stored directly in the VARIANTARG structure and passed to the function. If the command expects multiple arguments, those arguments must be packaged appropriately within the VARIANTARG, using one of the supported types (such as **IDispatch** or **SAFEARRAY**).

If a command returns one or more arguments, the caller is expected to declare a VARIANTARG, initialize it to VT_EMPTY, and pass its address in pvaOut. If the command returns a single value, then the object can store that value directly in pvaOut. If the command has multiple output values, then it will package those in some way appropriate for the VARIANTARG.

Because *pvaIn* and *pvOut* are both caller-allocated, stack variables are permitted for both the caller and the object receiving the call. For commands that take zero or one argument on input and return zero or one value, no additional memory allocation is necessary. Most of the types supported by VARIANTARG do not require memory allocation. Exceptions include **SAFEARRAY** and **BSTR**.

### Notes to Implementers

A command target must implement this function; E_NOTIMPL is not a valid return value.

## See also

[IOleCommandTarget](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-iolecommandtarget)

[OLECMDEXECOPT](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdexecopt)