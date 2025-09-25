# IExecuteCommand::SetKeyState

## Description

Sets a value based on the current state of the keys CTRL and SHIFT.

## Parameters

### `grfKeyState` [in]

Type: **DWORD**

One or both of the following flags to indicate whether the key is pressed.

#### MK_CONTROL

The CTRL key is pressed.

#### MK_SHIFT

The SHIFT key is pressed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.