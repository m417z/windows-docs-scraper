# MultiByteToWideChar function

## Description

Maps a character string to a UTF-16 (wide character) string. The character string is not necessarily from a multibyte character set.

## Parameters

### `CodePage` [in]

Code page to use in performing the conversion. This parameter can be set to the value of any code page that is installed or available in the operating system. For a list of code pages, see [Code Page Identifiers](https://learn.microsoft.com/windows/win32/Intl/code-page-identifiers). Your application can also specify one of the values shown in the following table.

| Value | Meaning |
|----------------------|---------|
| **CP_ACP** | The system default Windows ANSI code page.<br><br>**Note:** This value can be different on different computers, even on the same network. It can be changed on the same computer, leading to stored data becoming irrecoverably corrupted. This value is only intended for temporary use and permanent storage should use UTF-16 or UTF-8 if possible. |
| **CP_MACCP** | The current system Macintosh code page (used primarily in legacy code and is typically not needed as Macintosh computers use Unicode for encoding.).<br><br>**Note:** This value can be different on different computers, even on the same network. It can be changed on the same computer, leading to stored data becoming irrecoverably corrupted. This value is only intended for temporary use and permanent storage should use UTF-16 or UTF-8 if possible. |
| **CP_OEMCP** | The current system OEM code page.<br><br>**Note:** This value can be different on different computers, even on the same network. It can be changed on the same computer, leading to stored data becoming irrecoverably corrupted. This value is only intended for temporary use and permanent storage should use UTF-16 or UTF-8 if possible. |
| **CP_SYMBOL** | Symbol code page (42). |
| **CP_THREAD_ACP** | The Windows ANSI code page for the current thread.<br><br>**Note:** This value can be different on different computers, even on the same network. It can be changed on the same computer, leading to stored data becoming irrecoverably corrupted. This value is only intended for temporary use and permanent storage should use UTF-16 or UTF-8 if possible. |
| **CP_UTF7** | UTF-7. Use this value only when forced by a 7-bit transport mechanism. Use of UTF-8 is preferred. |
| **CP_UTF8** | UTF-8. |

### `dwFlags` [in]

Flags indicating the conversion type. The application can specify a combination of the following values, with MB_PRECOMPOSED being the default. MB_PRECOMPOSED and MB_COMPOSITE are mutually exclusive. MB_USEGLYPHCHARS and MB_ERR_INVALID_CHARS can be set regardless of the state of the other flags.

| Value | Meaning |
|-------|---------|
| **MB_COMPOSITE** | Always use decomposed characters, that is, characters in which a base character and one or more nonspacing characters each have distinct code point values. For example, Ä is represented by A + ¨: LATIN CAPITAL LETTER A (U+0041) + COMBINING DIAERESIS (U+0308). Note that this flag cannot be used with MB_PRECOMPOSED. |
| **MB_ERR_INVALID_CHARS** | Fail if an invalid input character is encountered.\