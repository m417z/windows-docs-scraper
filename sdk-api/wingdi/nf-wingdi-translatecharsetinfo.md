# TranslateCharsetInfo function

## Description

Translates character set information and sets all members of a destination structure to appropriate values.

## Parameters

### `lpSrc` [in, out]

Pointer to the **fsCsb** member of a [FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature) structure if *dwFlags* is set to TCI_SRCFONTSIG. Otherwise, this parameter is set to a DWORD value indicating the source.

### `lpCs` [out]

Pointer to a [CHARSETINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-charsetinfo) structure that receives the translated character set information.

### `dwFlags` [in]

Flags specifying how to perform the translation. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TCI_SRCCHARSET** | Source contains the character set value in the low word, and 0 in the high word. |
| **TCI_SRCCODEPAGE** | Source is a code page identifier in the low word and 0 in the high word. |
| **TCI_SRCFONTSIG** | Source is the code page bitfield portion of a [FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature) structure. On input this should have only one Windows code-page bit set, either for an ANSI code page value or for a common ANSI and OEM value (for OEM values, bits 32-63 must be clear). On output, this has only one bit set.<br><br>If the TCI_SRCFONTSIG value is given, the *lpSrc* parameter must be the address of the code-page bitfield. If any other TCI_ value is given, the *lpSrc* parameter must be a value not an address. |
| **TCI_SRCLOCALE** | **Windows 2000:** Source is the locale identifier (LCID) or language identifier of the keyboard layout. If it is a language identifier, the value is in the low word. |

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CHARSETINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-charsetinfo)

[FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature)

[Unicode and Character Set Functions](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-set-functions)

[Unicode and Character Sets](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-sets)