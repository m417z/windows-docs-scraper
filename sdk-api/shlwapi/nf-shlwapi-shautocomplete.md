# SHAutoComplete function

## Description

Instructs system edit controls to use AutoComplete to help complete URLs or file system paths.

## Parameters

### `hwndEdit` [in]

Type: **HWND**

The window handle of a system edit control. Typically, this parameter is the handle of an edit control or the edit control embedded in a [ComboBoxEx](https://learn.microsoft.com/windows/desktop/Controls/comboboxex-control-reference) control.

### `dwFlags`

Type: **DWORD**

The flags to control the operation of **SHAutoComplete**. The first four flags are used to override the Internet Explorer registry settings. The user can change these settings manually by launching the **Internet Options** property sheet from the **Tools** menu and clicking the **Advanced** tab.

#### SHACF_AUTOAPPEND_FORCE_OFF (0x80000000)

Ignore the registry default and force the AutoAppend feature off. This flag must be used in combination with one or more of the SHACF_FILESYS* or SHACF_URL* flags.

#### SHACF_AUTOAPPEND_FORCE_ON (0x40000000)

Ignore the registry value and force the AutoAppend feature on. The completed string will be displayed in the edit box with the added characters highlighted. This flag must be used in combination with one or more of the SHACF_FILESYS* or SHACF_URL* flags.

#### SHACF_AUTOSUGGEST_FORCE_OFF (0x20000000)

Ignore the registry default and force the AutoSuggest feature off. This flag must be used in combination with one or more of the SHACF_FILESYS* or SHACF_URL* flags.

#### SHACF_AUTOSUGGEST_FORCE_ON (0x10000000)

Ignore the registry value and force the AutoSuggest feature on. A selection of possible completed strings will be displayed as a drop-down list, below the edit box. This flag must be used in combination with one or more of the SHACF_FILESYS* or SHACF_URL* flags.

#### SHACF_DEFAULT (0x00000000)

The default setting, equivalent to **SHACF_FILESYSTEM** | **SHACF_URLALL**. **SHACF_DEFAULT** cannot be combined with any other flags.

#### SHACF_FILESYS_ONLY (0x00000010)

Include the file system only.

#### SHACF_FILESYS_DIRS (0x00000020)

Include the file system and directories, UNC servers, and UNC server shares.

#### SHACF_FILESYSTEM (0x00000001)

Include the file system and the rest of the Shell (Desktop, Computer, and Control Panel, for example).

#### SHACF_URLALL (SHACF_URLHISTORY | SHACF_URLMRU)

Include the URLs in the users **History** and **Recently Used** lists. Equivalent to **SHACF_URLHISTORY** | **SHACF_URLMRU**.

#### SHACF_URLHISTORY (0x00000002)

Include the URLs in the user's **History** list.

#### SHACF_URLMRU (0x00000004)

Include the URLs in the user's **Recently Used** list.

#### SHACF_USETAB (0x00000008)

Allow the user to select from the autosuggest list by pressing the TAB key. If this flag is not set, pressing the TAB key will shift focus to the next control and close the autosuggest list. If **SHACF_USETAB** is set, pressing the TAB key will select the first item in the list. Pressing TAB again will select the next item in the list, and so on. When the user reaches the end of the list, the next TAB key press will cycle the focus back to the edit control. This flag must be used in combination with one or more of the SHACF_FILESYS* or SHACF_URL* flags listed on this page.

#### SHACF_VIRTUAL_NAMESPACE (0x00000040)

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**SHAutoComplete** works on any system edit control, including the edit control and controls that contain edit controls such as [ComboBoxEx](https://learn.microsoft.com/windows/desktop/Controls/comboboxex-control-reference) controls. To retrieve a handle to an edit control embedded in a ComboBoxEx control, send the ComboBoxEx control a [CBEM_GETEDITCONTROL](https://learn.microsoft.com/windows/desktop/Controls/cbem-geteditcontrol) message.

An application must have invoked either [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) prior to calling this function. [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) or [OleUninitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleuninitialize) cannot be called until the edit box has finished processing the [WM_DESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-destroy) message for *hwndEdit*.

The maximum number of items that can be displayed in an autosuggest drop-down list box is 1000.

On versions of Windows prior to Windows Vista and server versions prior to Windows Server 2008, **SHAutoComplete** should not be called more than once with the same **HWND**. Doing so results in a memory leak. It prevents the original resources from being released, including the previous instance of the AutoComplete object, enumerator objects that the previous AutoComplete object has referenced, and Windows Graphics Device Interface (GDI) resources. Rather than call **SHAutoComplete** again with a different set of flags to change the AutoComplete list, call [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) with CLSID_AutoComplete to obtain the AutoComplete object. Then pass the **HWND** to the object to initialize it and provide your own custom enumerator. You can use CLSID_ACLMulti if you want AutoComplete to use multiple lists.

## See also

[Using Autocomplete](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776884(v=vs.85))