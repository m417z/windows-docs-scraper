# IAccessible::get_accChild

## Description

The **IAccessible::get_accChild** method retrieves an [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) for the specified child, if one exists. All objects must support this property.

## Parameters

### `varChild` [in]

Type: **VARIANT**

Identifies the child whose [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) interface is retrieved. For more information about initializing the [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

### `ppdispChild` [out, retval]

Type: **IDispatch****

[out, retval] Receives the address of the child object's [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values).

| Error | Description |
| --- | --- |
| **S_FALSE** | The child is not an accessible object. |
| **E_INVALIDARG** | An argument is not valid. |

## Remarks

Servers expose elements as either elements (child IDs) or full objects ([IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointers). If a child is an element, **get_accChild** returns S_FALSE, and the parent will provide information for that child. If the child is a full object, **get_accChild** will return the **IAccessible** interface pointer and the parent will not provide information about that child. If **get_accChild** fails because the server application cannot create an accessible object due to a temporary system error (such as an out-of-memory error), the server should return a suitable failure code.

**Note to server developers:** If *varChildID* contains VT_EMPTY, you should return E_INVALIDARG.

### Server Example

The following example code shows an implementation for an object that does not have any children, or whose children are elements rather than objects.

```cpp

HRESULT STDMETHODCALLTYPE AccServer::get_accChild(
    VARIANT varChild,
    IDispatch **ppdispChild)
{
    if (varChild.vt != VT_I4)
    {
        *ppdispChild = NULL;
        return E_INVALIDARG;
    }
    *ppdispChild = NULL;
    return S_FALSE;
};

```

## See also

[AccessibleChildren](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-accessiblechildren)

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IAccessible::get_accParent](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accparent)

[IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface)

[Object Navigation Properties and Methods](https://learn.microsoft.com/windows/desktop/WinAuto/object-navigation-properties-and-methods)

[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)