# IAccessible::accDoDefaultAction

## Description

The **IAccessible::accDoDefaultAction** method performs the specified object's default action. Not all objects have a default action.

## Parameters

### `varChild` [in]

Type: **VARIANT**

Specifies whether the default action belongs to the object or one of the object's child elements. For more information about initializing the [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).

| Error | Description |
| --- | --- |
| **DISP_E_MEMBERNOTFOUND** | The object does not support the method. This value is returned for controls that do not perform actions, such as edit fields. |
| **E_INVALIDARG** | An argument is not valid. |

## Remarks

Clients retrieve a string that describes the object's default action by calling **IAccessible::get_accDefaultAction**.

**Note to client developers:** When used on a menu item in a standard system menu, **accDoDefaultAction** returns S_OK but fails to perform the action if the character used in the access key (the underlined character in the text of a menu item name, also called a mnemonic) is ?, !, @, or any other character that requires the SHIFT key or another modifier key. This also happens on international keyboards with an access key character that requires the ALT GR key to be pressed. This is not an issue for menus in other applications, such as Microsoft Office or Windows Internet Explorer. For more information about access keys, see [IAccessible::get_accKeyboardShortcut](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_acckeyboardshortcut).

Also, while **accDoDefaultAction** is supposed to return immediately, some implementations block the return. For example, if clicking a link displays a dialog, some implementations will block the return until the dialog is dismissed. Such delays can prevent client applications from processing a dialog box. Servers should avoid implementations that block returns.

### Server Example

The following example shows a possible implementation for a custom list control whose default action is a double-click a child item. To prevent blocking, the method posts a custom message that, when received by the control window, triggers an action, such as displaying item properties.

```cpp

// Assume a previous definition such as this:
// #define CUSTOMLB_DEFERDOUBLECLICK   (WM_USER + 1)

HRESULT STDMETHODCALLTYPE AccServer::accDoDefaultAction(
    VARIANT varChild)
{
    if (varChild.vt != VT_I4)
    {
        return E_INVALIDARG;
    }
    if (varChild.lVal != CHILDID_SELF)
    {
        // It is assumed that the control does its own checking to see which
        // item has the focus when it receives this message.
        PostMessage(m_hwnd, CUSTOMLB_DEFERDOUBLECLICK, 0, 0);
    }
    return S_OK;
};

```

### Client Example

The following example function performs the default action on a control.

```cpp

HRESULT DoAction(IAccessible* pAcc)
{
        VARIANT varId;
        varId.vt = VT_I4;
        varId.lVal = CHILDID_SELF;
        return pAcc->accDoDefaultAction(varId);
}

```

## See also

[Appendix A: Supported User Interface Elements Reference](https://learn.microsoft.com/windows/desktop/WinAuto/appendix-a--supported-user-interface-elements-reference)

[DefaultAction Property](https://learn.microsoft.com/windows/desktop/WinAuto/defaultaction-property)

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IAccessible::get_accDefaultAction](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accdefaultaction)

[IAccessible::get_accKeyboardShortcut](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_acckeyboardshortcut)

[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)