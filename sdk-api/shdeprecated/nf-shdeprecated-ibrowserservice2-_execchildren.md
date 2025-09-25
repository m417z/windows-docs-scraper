# IBrowserService2::_ExecChildren

## Description

Deprecated. Enables the derived class to issue a command through the [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec) method directly, instead of relying on the base class.

## Parameters

### `punkBar` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the [IOleCommandTarget](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-iolecommandtarget) interface.

### `fBroadcast` [in]

Type: **BOOL**

**TRUE** to broadcast the command; **FALSE** otherwise.

### `pguidCmdGroup` [in]

Type: **const GUID***

A pointer to the unique identifier of the command group; can be **NULL** to specify the standard group.

### `nCmdID` [in]

Type: **DWORD**

The command to be executed. This command must belong to the group specified with *pguidCmdGroup*.

### `nCmdexecopt` [in]

Type: **DWORD**

The values taken from the [OLECMDEXECOPT](https://learn.microsoft.com/windows/desktop/api/docobj/ne-docobj-olecmdexecopt) enumeration, which describe how the object should execute the command.

### `pvarargIn` [in]

Type: **VARIANTARG***

A pointer to a **VARIANTARG** structure containing input arguments. Can be **NULL**.

### `pvarargOut` [in, out]

Type: **VARIANTARG***

A pointer to a **VARIANTARG** structure to receive command output. Can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For further information, see [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec).