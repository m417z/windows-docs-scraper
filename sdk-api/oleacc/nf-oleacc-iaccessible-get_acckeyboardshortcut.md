# IAccessible::get_accKeyboardShortcut

## Description

The **IAccessible::get_accKeyboardShortcut** method retrieves the specified object's shortcut key or access key, also known as the mnemonic. All objects that have a shortcut key or an access key support this property.

## Parameters

### `varChild` [in]

Type: **VARIANT**

Specifies whether the retrieved keyboard shortcut belongs to the object or one of the object's child elements. This parameter is either CHILDID_SELF (to obtain information about the object) or a child ID (to obtain information about the object's child element). For more information about initializing the [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

### `pszKeyboardShortcut` [out, retval]

Type: **BSTR***

 Address of a **BSTR** that receives a localized string that identifies the keyboard shortcut, or **NULL** if no keyboard shortcut is associated with the specified object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values).

| Error | Description |
| --- | --- |
| **S_FALSE** | The object does not have an associated keyboard shortcut. |
| **E_INVALIDARG** | An argument is not valid. |
| **DISP_E_MEMBERNOTFOUND** | The object does not support this property. |

## Remarks

An access key is an underlined character in the text of a menu, menu item, or label of a button or some other control. For example, a user can display a menu by pressing the ALT key while also pressing the indicated underlined key, such as ALT+F to open the File menu. To use the access key of a menu item, the menu that contains the item must be active.

Controls such as toolbar buttons and menu items often have an associated shortcut key, also known as a keyboard accelerator. Some menu items may have both an access key and a shortcut key, and some may have only one. For example, a menu item called New has an access key N and a shortcut key CTRL+N. The menu does not have to be active for the shortcut key to work.

**Note to client developers:**

If this property returns a single character, you cannot assume it is an access key or a keyboard shortcut. With standard menu items, the access key is returned by **IAccessible::get_accKeyboardShortcut**, and the shortcut key is returned as part of the menu item name returned from [IAccessible::get_accName](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accname). In general, access keys tend to be defined as ALT + \<letter>, and keyboard shortcuts tend to be CTRL + \<letter>.

**Note to server developers:** If the UI element can receive keyboard focus, then you should expose the access key for the element. If the UI element cannot receive keyboard focus (such as toolbar icons), then you should display the shortcut key.

Because shortcut keys are usually determined by the application rather than by the control itself, servers can usually return the value obtained from the standard accessible object for the window.

### Client Example

The following example function retrieves the keyboard shortcut for the specified accessible object, or one of its children, and prints it to the console.

```cpp

HRESULT PrintShortcut(IAccessible* pAcc, long child)
{
    if (pAcc == NULL)
    {
        return E_INVALIDARG;
    }
    BSTR bstrShortcut;
    VARIANT varObj;
    varObj.vt = VT_I4;
    varObj.lVal = child;
    HRESULT hr = pAcc->get_accKeyboardShortcut(varObj, &bstrShortcut);
    if (hr == S_OK)
    {
        printf("Shortcut: %S\n", bstrShortcut);
        SysFreeString(bstrShortcut);
    }
    return hr;
}

```

## See also

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IAccessible::get_accName](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accname)

[KeyboardShortcut Property](https://learn.microsoft.com/windows/desktop/WinAuto/keyboardshortcut-property)

[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)