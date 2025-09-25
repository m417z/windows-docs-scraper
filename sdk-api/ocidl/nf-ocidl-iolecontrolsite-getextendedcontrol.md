# IOleControlSite::GetExtendedControl

## Description

Retrieves an **IDispatch** pointer to the extended control that the container uses to wrap the real control.

## Parameters

### `ppDisp` [out]

A pointer to an **IDispatch** pointer variable that receives the interface pointer to the extended control. If an error occurs, the implementation must set **ppDisp* to **NULL**. On success, the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when **ppDisp* is no longer needed.

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | The container does not implement extended controls. |
| **E_POINTER** | The address in *ppDisp* or **ppDisp* is not valid. For example, it may be **NULL**. |

## Remarks

This method gives the real control access to whatever properties and methods the container maintains in the extended control. These properties and methods would otherwise be inaccessible to the control.

### Notes to Callers

The returned pointer is the responsibility of the caller, which must release it when it is no longer needed.

## See also

[IOleControlSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iolecontrolsite)