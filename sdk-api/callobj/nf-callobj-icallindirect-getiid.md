# ICallIndirect::GetIID

## Description

Retrieves the interface id supported by this [ICallIndirect](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallindirect) implementation.

## Parameters

### `piid` [out]

A pointer to the interface. This parameter is optional.

### `pfDerivesFromIDispatch` [out]

Indicates whether the interface is derived from **IDispatch**. This parameter is optional.

### `pcMethod` [out]

Receives the number of methods in the interface.

### `pwszInterface` [out]

Receives the interface name if it is available.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallIndirect](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallindirect)