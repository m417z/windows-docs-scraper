# IAccessible::accSelect

## Description

The **IAccessible::accSelect** method modifies the selection or moves the keyboard focus of the specified object. All objects that support selection or receive the keyboard focus must support this method.

## Parameters

### `flagsSelect` [in]

Type: **long**

Specifies which selection or focus operations are to be performed. This parameter must have a combination of the [SELFLAG Constants](https://learn.microsoft.com/windows/desktop/WinAuto/selflag).

### `varChild` [in]

Type: **VARIANT**

Specifies the selected object. If the value is CHILDID_SELF, the object itself is selected; if a child ID, one of the object's child elements is selected. For more information about initializing the [VARIANT structure](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).

| Error | Description |
| --- | --- |
| **S_FALSE** | The specified object is not selected. |
| **E_INVALIDARG** | An argument is not valid. This return value means that the specified SELFLAG combination is not valid, or that the SELFLAG value does not make sense for the specified object. For example, the following flags are not allowed on a single-selection list box: [SELFLAG_EXTENDSELECTION](https://learn.microsoft.com/windows/desktop/WinAuto/selflag), [SELFLAG_ADDSELECTION](https://learn.microsoft.com/windows/desktop/WinAuto/selflag), and [SELFLAG_REMOVESELECTION](https://learn.microsoft.com/windows/desktop/WinAuto/selflag). |
| **DISP_E_MEMBERNOTFOUND** | The object does not support this method. |

## Remarks

Client applications use this method to perform complex selection operations. For more information, see [Selecting Child Objects](https://learn.microsoft.com/windows/desktop/WinAuto/selecting-child-objects). This method provides the simplest way to programmatically switch the input focus between applications. This applies to applications running on Windows 2000.

**Note:** This method is for the selection of items, not text.

### Client Example

The following example function selects the item at a specified point on the screen. It is assumed that a single selection is wanted.

```cpp

HRESULT SelectItemAtPoint(POINT point)
{
    VARIANT varItem;
    IAccessible* pAcc;
    HRESULT hr = AccessibleObjectFromPoint(point, &pAcc, &varItem);
    if ((hr == S_OK))
    {
        hr = pAcc->accSelect((SELFLAG_TAKEFOCUS | SELFLAG_TAKESELECTION), varItem);
        VariantClear(&varItem);
        pAcc->Release();
    }
    return hr;
}

```

## See also

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IAccessible::get_accFocus](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accfocus)

[IAccessible::get_accSelection](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accselection)

[SELFLAG](https://learn.microsoft.com/windows/desktop/WinAuto/selflag)

[Selection and Focus Properties and Methods](https://learn.microsoft.com/windows/desktop/WinAuto/selection-and-focus-properties-and-methods)

[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)