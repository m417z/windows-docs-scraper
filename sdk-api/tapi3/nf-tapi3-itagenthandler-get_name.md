# ITAgentHandler::get_Name

## Description

The
**get_Name** method gets the agent handler name.

## Parameters

### `ppName` [out]

Pointer to **BSTR** representation of the agent handler name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppName* parameter is not a valid pointer. |

## Remarks

The application must free the memory allocated for the *ppName* parameter through
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when the variable is no longer needed.

## See also

[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler)