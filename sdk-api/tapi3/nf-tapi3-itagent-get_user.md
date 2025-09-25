# ITAgent::get_User

## Description

The
**get_User** method gets the agent user name, which is the same as the operating system user login or e-mail name.

## Parameters

### `ppUser` [out]

Pointer to **BSTR** containing user name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppUser* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must free the memory allocated for the *ppUser* parameter through
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when the variable is no longer needed.

## See also

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)