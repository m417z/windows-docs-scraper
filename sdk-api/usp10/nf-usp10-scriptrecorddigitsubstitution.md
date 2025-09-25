# ScriptRecordDigitSubstitution function

## Description

Reads the National Language Support (NLS) native digit and digit substitution settings and records them in a [SCRIPT_DIGITSUBSTITUTE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_digitsubstitute) structure. For more information, see [Digit Shapes](https://learn.microsoft.com/windows/desktop/Intl/digit-shapes).

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) of the locale to query. Typically, the application should set this parameter to [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default). Alternatively, the setting can indicate a specific locale combined with [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride) to obtain the default settings.

### `psds` [out]

Pointer to a [SCRIPT_DIGITSUBSTITUTE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_digitsubstitute) structure. This structure can be passed later to [ScriptApplyDigitSubstitution](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptapplydigitsubstitution).

## Return value

Returns S_OK if successful. The function returns a nonzero HRESULT value if it does not succeed.

Error returns include:

* E_INVALIDARG. The *Locale* parameter indicates a locale that is invalid or not installed.
* E_POINTER. The *psds* parameter is set to **NULL**.

## Remarks

See [Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe) for a discussion of the context in which this function is normally called.

This function supports context digit substitution only for Arabic and Persian locales. For other locales, context digit substitution is mapped to no substitution.

The following example shows the typical way to call this function.

```cpp
SCRIPT_DIGITSUBSTITUTE sds;
ScriptRecordDigitSubstitution(LOCALE_USER_DEFAULT, &sds);

```

At every itemization, the application can use the results as shown in the next example.

```cpp
SCRIPT_CONTROL sc = {0};
SCRIPT_STATE   ss = {0};
ScriptApplyDigitSubstitution(&sds, &sc, &ss);

```

For performance reasons, your application should not call **ScriptRecordDigitSubstitution** frequently. The function requires considerable overhead to call it every time [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize) or [ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse) is called. Instead, the application can save the [SCRIPT_DIGITSUBSTITUTE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_digitsubstitute) structure and update it only when a [WM_SETTINGCHANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-settingchange) message is received. Alternatively, the application can update the structure when a [RegNotifyChangeKeyValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regnotifychangekeyvalue) call in a dedicated thread indicates a change in the registry under HKCU\Control Panel\International.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe)

[SCRIPT_DIGITSUBSTITUTE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_digitsubstitute)

[ScriptApplyDigitSubstitution](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptapplydigitsubstitution)

[ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize)

[ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)