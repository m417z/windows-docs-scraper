# ITAgentSession::get_Agent

## Description

The
**get_Agent** method gets a pointer to the
[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent) interface associated with this session.

## Parameters

### `ppAgent` [out]

pointer to
[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppAgent* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent) interface returned by **ITAgentSession::get_Agent**. The application must call **Release** on the
**ITAgent** interface to free resources associated with it.

## See also

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)

[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession)