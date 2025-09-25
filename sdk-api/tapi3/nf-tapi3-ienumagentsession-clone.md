# IEnumAgentSession::Clone

## Description

The
**Clone** method creates another enumerator that contains the same enumeration state as the current one.

## Parameters

### `ppEnum` [out]

Pointer to new
[IEnumAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagentsession) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnum* parameter not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | Failed for unknown reasons. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagentsession) interface returned by **IEnumAgentSession::Clone**. The application must call **Release** on the
**IEnumAgentSession** interface to free resources associated with it.

## See also

[IEnumAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagentsession)