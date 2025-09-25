# IAccessible::get_accParent

## Description

The **IAccessible::get_accParent** method retrieves the [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) of the object's parent. All objects support this property.

## Parameters

### `ppdispParent` [out, retval]

Type: **IDispatch****

 Receives the address of the parent object's [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) interface. If no parent exists or if the child cannot access its parent, the variable is set to **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values).

| Error | Description |
| --- | --- |
| **S_FALSE** | No parent exists for this object. |

## See also

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IAccessible::get_accChild](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accchild)

[IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface)

[Object Navigation Properties and Methods](https://learn.microsoft.com/windows/desktop/WinAuto/object-navigation-properties-and-methods)