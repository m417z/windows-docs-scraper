# IInkRecognizers::GetDefaultRecognizer

## Description

Retrieves the default recognizer for a known language, specified by a national language support (NLS) language code identifier (LCID).

## Parameters

### `lcid` [in]

 The LCID locale identifier of the language for which you are retrieving the default recognizer. If *lcid* is 0, the method uses the user's locale setting to determine which default recognizer to retrieve. If the user has not specified a locale in Regional Options, the method uses the locale that was specified for the computer. The default value is 0.

### `DefaultRecognizer` [out, retval]

When this method returns, contains a pointer to the requested recognizer.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INVALIDARG** | The flag is invalid. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

Each language can have a default recognizer. For example, a user can have a default recognizer for U.S. English and a default recognizer for French. If no locale is specified, this method returns the recognizer for the active input locale. To select the active input locale, in the Regional and Language Options in ControlPanel, on the Languages tab, users click Details, and then select the Default input language.

The default value of the *lcid* parameter is 0.

This method generates an error if the *lcid* parameter is not a known locale or if a recognizer is not installed for the requested locale.

**GetDefaultRecognizer** first checks if there is a matching recognizer for the user's input locale. If there is none, it checks if there is a matching recognizer for the current system locale.

For more information about NLS, see [NLS Terminology](https://learn.microsoft.com/windows/desktop/Intl/nls-terminology).

## See also

[IInkRecognizer Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer)

[IInkRecognizers](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizers)

[InkRecognizers Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms702438(v=vs.85))