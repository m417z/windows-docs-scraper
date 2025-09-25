# IAccessible::get_accHelpTopic

## Description

The **IAccessible::get_accHelpTopic** method retrieves the full path of the WinHelp file that is associated with the specified object; it also retrieves the identifier of the appropriate topic within that file. Not all objects support this property. This property is rarely supported or used by applications

**Note** **IAccessible::get_accHelpTopic** is deprecated and should not be used.

## Parameters

### `pszHelpFile` [out]

Type: **BSTR***

Address of a **BSTR** that receives the full path of the WinHelp file that is associated with the specified object.

### `varChild` [in]

Type: **VARIANT**

Specifies whether the retrieved Help topic belongs to the object or one of the object's child elements. This parameter is either CHILDID_SELF (to obtain a Help topic for the object) or a child ID (to obtain a Help topic for one of the object's child elements). For more information about initializing the [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

### `pidTopic`

Type: **long***

[out, retval] Address of a variable that identifies the Help file topic associated with the specified object. This value is used as the context identifier of the desired topic that passes to the [WinHelp](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-winhelpa) function. When calling [WinHelp](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-winhelpa) to display the topic, set the *uCommand* parameter to HELP_CONTEXT, cast the value pointed to by *pidTopic* to a **DWORD**, and pass it as the *dwData* parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values).

| Error | Description |
| --- | --- |
| **S_FALSE** | No Help information is available. |
| **E_INVALIDARG** | An argument is not valid. |
| **DISP_E_MEMBERNOTFOUND** | The object does not support this property. |

## Remarks

Getting information from a Help file might be time and memory intensive.

**Note to server developers:** This property provides access to a Help topic in WinHelp, whereas [IAccessible::get_accHelp](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_acchelp) returns a string. Objects are not required to support both **IAccessible::get_accHelp** and **IAccessible::get_accHelpTopic**, but they must support at least one. If they can easily return a string, they must support **IAccessible::get_accHelp**; otherwise they must support **IAccessible::get_accHelpTopic**. If both are supported, **IAccessible::get_accHelpTopic** provides more detailed information.

## See also

[HelpTopic Property](https://learn.microsoft.com/windows/desktop/WinAuto/helptopic-property)

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IAccessible::get_accHelp](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_acchelp)