# SetInputScopes2 function

## Description

The application must call [SetInputScope](https://learn.microsoft.com/windows/desktop/api/inputscope/nf-inputscope-setinputscope) with IS_DEFAULT before a window is destroyed to clear the reference of the interface.

## Parameters

### `hwnd` [in]

The window to set the scope on. This call will replace whatever scope may have been on the hwnd before.

### `pInputScopes` [in]

Pointer to an array of input scopes. May be **NULL**. If not **NULL**, all of the scopes contained within will be set as the input scope of the hwnd with equal weighting. Use IS_DEFAULT to accept all other input as well (this is the "don’t coerce" option).

### `cInputScopes` [in]

A count of the number of input scopes in *pInputScopes*. Must be zero if rgScopes is **NULL**, must be nonzero if *pInputScopes* is non-**NULL**.

### `pEnumString` [in]

IenumString interface pointer of the phrase list.

### `pszRegExp` [in]

Pointer to a **NULL**-terminated string describing the regular expression to be recognized. May be **NULL**.

### `pszSRGS` [in]

Pointer to a **NULL**-terminated XML string that provides speech-specific hints and rules to aid in speech recognition. The XML format conforms to the Speech Recognition Grammar Specification (SRGS) standard, outlined at [http://www.w3.org/TR/speech-grammar](https://www.w3.org/tr/speech-grammar). Can be **NULL**. $

## Return value

| Value | Meaning |
| --- | --- |
| S_OK | The input scope set or cleared successfully. |

## Remarks

The application must call [SetInputScope](https://learn.microsoft.com/windows/desktop/api/inputscope/nf-inputscope-setinputscope) with IS_DEFAULT before a window is destroyed to clear the reference of the interface.

If you call this method on a window (*hwnd* parameter) that has
not been associated with a Document Manager, then no text service notifications are sent to interested clients (such as the touch keyboard) that may want to respond to the
scope change.