# ITfContextOwnerCompositionSink::OnStartComposition

## Description

Called when a composition is started.

## Parameters

### `pComposition` [in]

Pointer to an [ITfCompositionView](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcompositionview) object that represents the new composition.

### `pfOk` [out]

Pointer to a **BOOL** value that receives a value that allows or denies the new composition. Receives a nonzero value to allow the composition or zero to deny the composition.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITfCompositionView interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompositionview), [ITfContextOwnerCompositionSink interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontextownercompositionsink)