# SHMessageBoxCheckA function

## Description

[**SHMessageBoxCheck** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Displays a message box that gives the user the option of suppressing further occurrences. If the user has already opted to suppress the message box, the function does not display a dialog box and instead simply returns the default value.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

The window handle to the message box's owner. This value can be **NULL**.

### `pszText` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains the message to be displayed.

### `pszCaption` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains the title of the message box. If this parameter is set to **NULL**, the title is set to **Error!**.

### `uType`

Type: **UINT**

The flags that specify the contents and behavior of the message box. This function supports only a subset of the flags supported by [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox). If you use any flags that are not listed below, the function's behavior is undefined.

You must specify the buttons to be displayed by setting one and only one of the following flags.

#### MB_OKCANCEL

Display a message box with **OK** and **Cancel** buttons.

#### MB_YESNO

Display a message box with **Yes** and **No** buttons.

#### MB_OK

Display a message box with an **OK** button.

You can display an optional icon by setting one and only one of the following flags.

#### MB_ICONHAND

Display a stop-sign icon.

#### MB_ICONQUESTION

Display a question-mark icon.

#### MB_ICONEXCLAMATION

Display an exclamation-point icon.

#### MB_ICONINFORMATION

Display an icon with a lowercase "i" in a circle.

### `iDefault`

Type: **int**

The value that the function returns when the user has opted not to have the message box displayed again. If the user has not opted to suppress the message box, the message box is displayed and the function ignores *iDefault*.

### `pszRegVal` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains a unique string value to associate with this message. To avoid collisions with values used by Microsoft, this string should include a GUID. This string must not exceed REGSTR_MAX_VALUE_LENGTH characters in length, including the terminating null character.

## Return value

Type: **int**

If the user has already chosen to suppress the message box, the function immediately returns the value assigned to *iDefault*.

If the user clicks the **OK**, **Cancel**, **Yes**, or **No** button, the function returns IDOK, IDCANCEL, IDYES, or IDNO, respectively.

If the user closes the message box by clicking the **X** button in the caption, the function returns IDCANCEL. This value is returned in this case even if the MB_OKCANCEL flag has not been set.

If an error occurs, the return value is normally –1. However, under certain low-memory conditions, the function might return *iDefault*.

## Remarks

**Security Warning:** Do not take any dangerous actions if the function returns either –1 or *iDefault*. If an error occurs when attempting to display the message box, **SHMessageBoxCheck** returns –1 or, in some cases, *iDefault*. Such errors can be caused by insufficient memory or resources. If you get one of these return values, you should be aware that the user did not necessarily see the dialog box and consequently did not positively agree to any action.

Do not confuse "Do not show this dialog box" with "Remember this answer". **SHMessageBoxCheck** does not provide "Remember this answer" functionality. If the user chooses to suppress the message box again, the function does not preserve which button they clicked. Instead, subsequent invocations of **SHMessageBoxCheck** simply return the value specified by *iDefault*. Consider the following example.

```

int iResult = SHMessageBoxCheck(hwnd,
                                TEXT("Do you want to exit without saving?"),
                                TEXT("Warning"),
                                MB_YESNO,
                                IDNO,
                                TEXT("{d9108ba3-9a61-4398-bfbc-b02102c77e8a}");
```

If the user selects **In the future, do not show me this** dialog box and clicks the **Yes** button, **SHMessageBoxCheck** returns IDYES. However, the next time this code is executed, **SHMessageBoxCheck** does not return IDYES, even though the user selected **Yes** originally. Instead, it returns IDNO, because that is the value specified by *iDefault*.

The default button displayed by the message box should agree with your *iDefault* value. The lack of support for the MB_DEFBUTTON2 flag means that *iDefault* should be set to IDOK if you have specified the MB_OK or MB_OKCANCEL flag. The *iDefault* value should be set to IDYES if you have set the MB_YESNO flag.

**SHMessageBoxCheck** records the message boxes that the user has chosen to suppress under the following registry key:

```
HKEY_CURRENT_USER
   Software
      Microsoft
         Windows
            CurrentVersion
               Explorer
                  DontShowMeThisDialogAgain
```

> [!NOTE]
> The shlwapi.h header defines SHMessageBoxCheck as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).