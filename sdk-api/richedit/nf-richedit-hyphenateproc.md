# HyphenateProc function

## Description

The *HyphenateProc* function is an application–defined
callback function used with the [EM_SETHYPHENATEINFO](https://learn.microsoft.com/windows/win32/controls/em-sethyphenateinfo) message. It determines how hyphenation is done in a Microsoft Rich Edit control.

## Parameters

### `pszWord` [in]

Type: **[WCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the word to hyphenate.

### `langid` [in]

Type: **[LANGID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Current language ID for the control.

### `ichExceed` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the character in the passed string that exceeds the line width.

### `phyphresult` [out]

Type: **[HYPHRESULT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-hyphresult)***

Pointer to a [HYPHRESULT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-hyphresult) structure that *HyphenateProc* fills in with the result of the hyphenation.

## Remarks

*HyphenateProc* is a placeholder for the application-defined function name.

An application must install the callback function by specifying the address of the callback function in an [EM_SETHYPHENATEINFO](https://learn.microsoft.com/windows/win32/controls/em-sethyphenateinfo) message.

## See also

[EM_SETHYPHENATEINFO](https://learn.microsoft.com/windows/win32/controls/em-sethyphenateinfo)

[HYPHENATEINFO](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-hyphenateinfo)

[HYPHRESULT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-hyphresult)

**Reference**