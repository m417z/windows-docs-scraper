# IExecuteCommandApplicationHostEnvironment::GetValue

## Description

Determines whether the current application host environment is in the desktop or immersive mode.

## Parameters

### `pahe` [out]

A pointer to a **AHE_TYPE** value that, when this method returns successfully, receives one of the following values to indicate the current host environment.

#### AHE_DESKTOP (0)

Desktop.

#### AHE_IMMERSIVE (1)

Immersive mode.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IExecuteCommandApplicationHostEnvironment](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexecutecommandapplicationhostenvironment)