# ICallIndirect::GetMethodInfo

## Description

Retrieves information about the interface method from the call frame.

## Parameters

### `iMethod` [in]

The method number.

### `pInfo` [out]

A pointer to the [CALLFRAMEINFO](https://learn.microsoft.com/windows/win32/api/callobj/ns-callobj-callframeinfo) structure containing information about the specified method.

### `pwszMethod` [out]

The method name. This parameter is optional.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

The information returned is a static analysis of the method, not a dynamic one, in that it is based on an analysis of the method signature only, not the actual current contents of the call frame. For example, the static analysis might indicate that this method has the potential of having an in-interface, but because of, say, a union switch, a given call might not actually have any such interfaces. This method is equivalent to the [GetInfo](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframe-getinfo) and [GetNames](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframe-getnames) methods in [ICallFrame](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframe), but avoids the need to actually make any invocation to get the information.

## See also

[ICallIndirect](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallindirect)