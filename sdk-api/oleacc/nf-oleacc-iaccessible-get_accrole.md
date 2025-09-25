# IAccessible::get_accRole

## Description

The **IAccessible::get_accRole** method retrieves information that describes the role of the specified object. All objects support this property.

## Parameters

### `varChild` [in]

Type: **VARIANT**

Specifies whether the retrieved role information belongs to the object or one of the object's child elements. This parameter is either CHILDID_SELF (to obtain information about the object) or a child ID (to obtain information about the object's child element). For more information about initializing the [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

### `pvarRole` [out, retval]

Type: **VARIANT***

Address of a [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure) that receives an [object role](https://learn.microsoft.com/windows/desktop/WinAuto/object-roles) constant. The **vt** member must be VT_I4. The **lVal** member receives an object role constant.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values).

| Error | Description |
| --- | --- |
| **E_INVALIDARG** | An argument is not valid. |

## Remarks

Clients call [GetRoleText](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-getroletexta) to retrieve a localized string that describes the object's role.

**Note to server developers:** You must use the predefined role constants.

### Server Example

The following example code is a possible implementation of this method for a custom list box that maintains its own list items.

```cpp

HRESULT STDMETHODCALLTYPE AccServer::get_accRole(
    VARIANT varChild,
    VARIANT *pvarRole)
{
    if (varChild.vt != VT_I4)
    {
        pvarRole->vt = VT_EMPTY;
        return E_INVALIDARG;
    }

    pvarRole->vt = VT_I4;

    if (varChild.lVal == CHILDID_SELF)
    {
        pvarRole->lVal = ROLE_SYSTEM_LIST;
    }
    else
    {
        pvarRole->lVal = ROLE_SYSTEM_LISTITEM;
    }
    return S_OK;
};

```

### Client Example

The following example function displays the role of an accessible object or child element.

```cpp

HRESULT PrintRole(IAccessible* pAcc, long childId)
{
    DWORD roleId;
    if (pAcc == NULL)
    {
        return E_INVALIDARG;
    }
    VARIANT varChild;
    varChild.vt = VT_I4;
    varChild.lVal = childId;
    VARIANT varResult;
    HRESULT hr = pAcc->get_accRole(varChild, &varResult);
    if ((hr == S_OK) && (varResult.vt == VT_I4))
    {
        roleId = varResult.lVal;
        UINT   roleLength;
        LPTSTR lpszRoleString;

        // Get the length of the string.
        roleLength = GetRoleText(roleId, NULL, 0);

        // Allocate memory for the string. Add one character to
        // the length you got in the previous call to make room
        // for the null character.
        lpszRoleString = (LPTSTR)malloc((roleLength+1) * sizeof(TCHAR));
        if (lpszRoleString != NULL)
        {
            // Get the string.
            GetRoleText(roleId, lpszRoleString, roleLength + 1);
#ifdef UNICODE
            printf("Role: %S\n", lpszRoleString);
#else
            printf(("Role: %s\n", lpszRoleString);
#endif
            // Free the allocated memory
            free(lpszRoleString);
        }
        else
        {
            return E_OUTOFMEMORY;
        }
    }
    return S_OK;
}

```

## See also

[GetRoleText](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-getroletexta)

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[Role Property](https://learn.microsoft.com/windows/desktop/WinAuto/role-property)

[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)