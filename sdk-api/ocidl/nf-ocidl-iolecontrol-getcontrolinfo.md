# IOleControl::GetControlInfo

## Description

Retrieves information about the control's keyboard mnemonics and behavior.

## Parameters

### `pCI` [in, out]

A pointer to a [CONTROLINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-controlinfo) structure that receives the information.

## Return value

This method can return the standard return value E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | The control has no mnemonics. |
| **E_POINTER** | The address in *pCI* is not valid. For example, it may be **NULL**. |

## See also

[IOleControl](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iolecontrol)