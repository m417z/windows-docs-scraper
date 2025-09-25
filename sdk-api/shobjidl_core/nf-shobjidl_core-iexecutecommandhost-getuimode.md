# IExecuteCommandHost::GetUIMode

## Description

Enables an [IExplorerCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorercommand)-based Shell verb handler to query the UI mode of the host component from which the application was invoked.

## Parameters

### `pUIMode` [out]

Type: **EC_HOST_UI_MODE***

#### ECHUIM_DESKTOP (0)

The application is running in the desktop environment.

#### ECHUIM_IMMERSIVE (1)

The application is running in the Windows 8 immersive environment.

#### ECHUIM_SYSTEM_LAUNCHER (2)

The application is running in the system launcher environment.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IExecuteCommandHost](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexecutecommandhost)