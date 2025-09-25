# IAccessible::get_accValue

## Description

The **IAccessible::get_accValue** method retrieves the value of the specified object. Not all objects have a value.

## Parameters

### `varChild` [in]

Type: **VARIANT**

Specifies whether the retrieved value information belongs to the object or one of the object's child elements. This parameter is either CHILDID_SELF (to obtain information about the object) or a child ID (to obtain information about the object's child element). For more information about initializing the [VARIANT structure](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

### `pszValue` [out, retval]

Type: **BSTR***

 Address of the **BSTR** that receives a localized string that contains the object's current value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values).

| Error | Description |
| --- | --- |
| **DISP_E_MEMBERNOTFOUND** | The object does not support this property. |
| **E_INVALIDARG** | An argument is not valid. |

## Remarks

Numeric values returned from scroll bar and trackbar accessible objects indicate percentages. They are integers between zero (0) and one hundred (100), inclusive, but might also be a limited range for example, between one (1) and sixteen (16). Also, some scroll bar and trackbar objects return strings that correspond to settings such as screen size or Internet security.

**Note to server developers:** Localize the string returned from this property.

## See also

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[Value Property](https://learn.microsoft.com/windows/desktop/WinAuto/value-property)