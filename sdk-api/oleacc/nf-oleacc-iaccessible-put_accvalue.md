# IAccessible::put_accValue

## Description

The **IAccessible::put_accValue** method sets the value of the specified object. Not all objects have a value.

## Parameters

### `varChild` [in]

Type: **VARIANT**

Specifies whether the value information being set belongs to the object or one of the object's child elements. This parameter is either CHILDID_SELF (to set information on the object) or a child ID (to set information about the object's child element). For more information about initializing the [VARIANT structure](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

### `szValue` [in]

Type: **BSTR**

A localized string that contains the object's value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values).

| Error | Description |
| --- | --- |
| **DISP_E_MEMBERNOTFOUND** | The object does not support this property. |
| **E_INVALIDARG** | An argument is not valid. |

## Remarks

The **IAccessible::put_accValue** method is supported for some UI elements (usually edit controls). For UI elements that do not support this method, control-specific methods are used instead. For more information, see [Supported User Interface Element Reference](https://learn.microsoft.com/windows/desktop/WinAuto/appendix-a--supported-user-interface-elements-reference).