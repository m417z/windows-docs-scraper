# ITACDGroup::get_Name

## Description

The
**get_Name** method gets the ACD group name. This string can be a displayable name for the group.

## Parameters

### `ppName` [out]

Pointer to **BSTR** representation of group name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppName* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must free *ppName* through
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when the variable is no longer needed.

## See also

[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup)