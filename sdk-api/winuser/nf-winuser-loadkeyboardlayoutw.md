# LoadKeyboardLayoutW function

## Description

Loads a new input locale identifier (formerly called the keyboard layout) into the system.

**Prior to Windows 8:** Several input locale identifiers can be loaded at a time, but only one per process is active at a time. Loading multiple input locale identifiers makes it possible to rapidly switch between them.

**Beginning in Windows 8:** The input locale identifier is loaded for the entire system. This function has no effect if the current process does not own the window with keyboard focus.

## Parameters

### `pwszKLID` [in]

Type: **LPCTSTR**

The name of the input locale identifier to load. This name is a string composed of the hexadecimal value of the [Language Identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) (low word) and a device identifier (high word). For example, U.S. English has a language identifier of 0x0409, so the primary U.S. English layout is named "00000409". Variants of U.S. English layout (such as the Dvorak layout) are named "00010409", "00020409", and so on.

For a list of the input layouts that are supplied with Windows, see [Keyboard Identifiers and Input Method Editors for Windows](https://learn.microsoft.com/windows-hardware/manufacture/desktop/windows-language-pack-default-values).

### `Flags` [in]

Type: **UINT**

Specifies how the input locale identifier is to be loaded. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **KLF_ACTIVATE**<br><br>0x00000001 | **Prior to Windows 8:** If the specified input locale identifier is not already loaded, the function loads and activates the input locale identifier for the current thread.<br><br>**Beginning in Windows 8:** If the specified input locale identifier is not already loaded, the function loads and activates the input locale identifier for the system. |
| **KLF_NOTELLSHELL**<br><br>0x00000080 | **Prior to Windows 8:** Prevents a [ShellProc](https://learn.microsoft.com/windows/win32/winmsg/shellproc) hook procedure from receiving an **HSHELL_LANGUAGE** hook code when the new input locale identifier is loaded. This value is typically used when an application loads multiple input locale identifiers one after another. Applying this value to all but the last input locale identifier delays the shell's processing until all input locale identifiers have been added.<br><br>**Beginning in Windows 8:** In this scenario, the last input locale identifier is set for the entire system. |
| **KLF_REORDER**<br><br>0x00000008 | **Prior to Windows 8:** Moves the specified input locale identifier to the head of the input locale identifier list, making that locale identifier the active locale identifier for the current thread. This value reorders the input locale identifier list even if **KLF_ACTIVATE** is not provided.<br><br>**Beginning in Windows 8:** Moves the specified input locale identifier to the head of the input locale identifier list, making that locale identifier the active locale identifier for the system. This value reorders the input locale identifier list even if **KLF_ACTIVATE** is not provided. |
| **KLF_REPLACELANG**<br><br>0x00000010 | If the new input locale identifier has the same language identifier as a current input locale identifier, the new input locale identifier replaces the current one as the input locale identifier for that language. If this value is not provided and the input locale identifiers have the same language identifiers, the current input locale identifier is not replaced and the function returns **NULL**. |
| **KLF_SUBSTITUTE_OK**<br><br>0x00000002 | Substitutes the specified input locale identifier with another locale preferred by the user. The system starts with this flag set, and it is recommended that your application always use this flag. The substitution occurs only if the registry key **HKEY_CURRENT_USER\Keyboard Layout\Substitutes** explicitly defines a substitution locale. For example, if the key includes the value name "00000409" with value "00010409", loading the US layout ("00000409") causes the United States-Dvorak layout ("00010409") to be loaded instead. The system uses **KLF_SUBSTITUTE_OK** when booting, and it is recommended that all applications use this value when loading input locale identifiers to ensure that the user's preference is selected. |
| **KLF_SETFORPROCESS**<br><br>0x00000100 | **Prior to Windows 8:** This flag is valid only with **KLF_ACTIVATE**. Activates the specified input locale identifier for the entire process and sends the [WM_INPUTLANGCHANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-inputlangchange) message to the current thread's Focus or Active window. Typically, **LoadKeyboardLayout** activates an input locale identifier only for the current thread.<br><br>**Beginning in Windows 8:** This flag is not used. **LoadKeyboardLayout** always activates an input locale identifier for the entire system if the current process owns the window with keyboard focus. |
| **KLF_UNLOADPREVIOUS** | This flag is unsupported. Use the [UnloadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unloadkeyboardlayout) function instead. |

## Return value

Type: **HKL**

If the function succeeds, the return value is the input locale identifier corresponding to the name specified in *pwszKLID*. If no matching locale is available, the return value is the default language of the system.

If the function fails, the return value is NULL. This can occur if the layout library is loaded from the application directory.

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The input locale identifier is a broader concept than a keyboard layout, since it can also encompass a speech-to-text converter, an Input Method Editor (IME), or any other form of input.

An application can and will typically load the default input locale identifier or IME for a language and can do so by specifying only a string version of the language identifier. If an application wants to load a specific locale or IME, it should read the registry to determine the specific input locale identifier to pass to **LoadKeyboardLayout**. In this case, a request to activate the default input locale identifier for a locale will activate the first matching one. A specific IME should be activated using an explicit input locale identifier returned from [GetKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardlayout) or **LoadKeyboardLayout**.

**Prior to Windows 8:** This function only affects the layout for the current process or thread.

**Beginning in Windows 8:** This function affects the layout for the entire system.

> [!NOTE]
> The winuser.h header defines LoadKeyboardLayout as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ActivateKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-activatekeyboardlayout)

**Conceptual**

[GetKeyboardLayoutName](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardlayoutnamea)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

[MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid)

**Other Resources**

**Reference**

[UnloadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unloadkeyboardlayout)