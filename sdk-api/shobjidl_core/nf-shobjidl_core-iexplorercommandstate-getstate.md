# IExplorerCommandState::GetState

## Description

Gets the command state associated with a specified Shell item.

## Parameters

### `psiItemArray` [in]

Type: **[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)***

A pointer to an [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray) with a single element that represents the Shell item.

### `fOkToBeSlow` [in]

Type: **BOOL**

**FALSE** if a verb object should not perform any memory intensive computations that could cause the UI thread to stop responding. The verb object should return E_PENDING in that case. If **TRUE**, those computations can be completed.

### `pCmdState` [out]

Type: **[EXPCMDSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_expcmdstate)***

A pointer to a value that, when this method returns successfully, receives one or more Windows Explorer command states indicated by the [EXPCMDSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_expcmdstate) constants.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method provides the same functionality as [GetState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorercommand-getstate). Use [IExplorerCommandState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorercommandstate) when you only need to know the command state.