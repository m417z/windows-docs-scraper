# SetTextContext function

## Description

Provides the text strings that come before and after the text contained in the recognizer context.

You call this function before processing the ink for the first time. Therefore, call the **SetTextContext** function before calling the [Process](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-process) function.

## Parameters

### `hrc`

Handle to the recognizer context.

### `cwcBefore`

Number of characters in *pwcBefore*.

### `pwcBefore`

Text string that comes before the text contained in the recognizer context. The string is not **NULL** terminated.

### `cwcAfter`

Number of characters in *pwcAfter*.

### `pwcAfter`

Text string that comes after the text contained in the recognizer context. The string is not **NULL** -terminated.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | The context is invalid or one of the parameters is an invalid pointer. |
| **E_NOTIMPL** | The recognizer does not support this function. |
| **E_OUTOFMEMORY** | Unable to allocate memory to complete the operation. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was specified. |

## Remarks

The **SetTextContext** function provides context for a phrase or a word, increasing your recognizer's accuracy. For example, if the *pwcBefore**pwcBefore* string is "under the " and the *pwcAfter* string is "in the house", you can bias your recognizer using a word or words between the strings. Your recognizer should consider the space after "the" and before "in" when performing the recognition.

However, if the *pwcAfter* string is "Hel" and the *pwcBefore* string is "o", the lack of space between the strings indicates the recognizer should recognize one or more letters inside a word that begins with "Hel" and ends with "o".

It is recommended that you limit the length of the text context to no more than 1024 characters each for the left and right contexts.