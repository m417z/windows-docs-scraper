# SetInputScopes function

## Description

Sets a combination of one input scope, multiple input scopes, one phrase list, a regular expression, and/or Speech Recognition Grammar Specification (SRGS) rules for the specified window.

## Parameters

### `hwnd` [in]

The window to set the scope on.

### `pInputScopes` [in]

Pointer to an array of input scopes. Can be **NULL**. If not **NULL**, all of the input scopes in the array are set as the input scope of the window with equal weighting. Use IS_DEFAULT to accept all other input scopes as well.

### `cInputScopes` [in]

The number of input scopes in the array pointed to by **pInputScopes*. This value must be zero if the array is **NULL**.

### `ppszPhraseList` [in]

Pointer to an array of pointers to **NULL**-terminated phrases. Can be **NULL**.

### `cPhrases` [in]

Number of pointers pointed to by ***ppszPhraseList*, which represents the number of phrases.

### `pszRegExp` [in]

Pointer to a **NULL**-terminated string containing the regular expression to be recognized. Can be **NULL**.

### `pszSRGS` [in]

Pointer to a **NULL**-terminated XML string that provides speech-specific hints and rules to aid in speech recognition. The XML format conforms to the Speech Recognition Grammar Specification (SRGS) standard, outlined at [http://www.w3.org/TR/speech-grammar](https://www.w3.org/tr/speech-grammar). Can be **NULL**. $

## Return value

| Value | Meaning |
| --- | --- |
| S_OK | The method was successful. |

## Remarks

Calling this method replaces whatever scope is associated with the window.

This API works only when the window (hwnd parameter) and the calling thread are in the same thread. If you call this API for a different thread's window, it fails with E_INVALIDARG.

If you call this method on a window (*hwnd* parameter) that has
not been associated with a Document Manager, then no text service notifications are sent to interested clients (such as the touch keyboard) that may want to respond to the
scope change.