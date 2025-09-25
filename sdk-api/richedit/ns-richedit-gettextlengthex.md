# GETTEXTLENGTHEX structure

## Description

Contains information about how the text length of a rich edit control should be calculated. This structure is passed in the **wParam** in the [EM_GETTEXTLENGTHEX](https://learn.microsoft.com/windows/win32/controls/em-gettextlengthex) message.

## Members

### `flags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value specifying the method to be used in determining the text length. This member can be one or more of the following values (some values are mutually exclusive).

| Value | Meaning |
| --- | --- |
| **GTL_DEFAULT** | Returns the number of characters. This is the default. |
| **GTL_USECRLF** | Computes the answer by using CR/LFs at the end of paragraphs. |
| **GTL_PRECISE** | Computes a precise answer. This approach could necessitate a conversion and thereby take longer. This flag cannot be used with the GTL_CLOSE flag. E_INVALIDARG will be returned if both are used. |
| **GTL_CLOSE** | Computes an approximate (close) answer. It is obtained quickly and can be used to set the buffer size. This flag cannot be used with the GTL_PRECISE flag. E_INVALIDARG will be returned if both are used. |
| **GTL_NUMCHARS** | Returns the number of characters. This flag cannot be used with the GTL_NUMBYTES flag. E_INVALIDARG will be returned if both are used. |
| **GTL_NUMBYTES** | Returns the number of bytes. This flag cannot be used with the GTL_NUMCHARS flag. E_INVALIDARG will be returned if both are used. |

### `codepage`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Code page used in the translation. It is CP_ACP for ANSI Code Page and 1200 for Unicode.

## See also

[EM_GETTEXTLENGTHEX](https://learn.microsoft.com/windows/win32/controls/em-gettextlengthex)