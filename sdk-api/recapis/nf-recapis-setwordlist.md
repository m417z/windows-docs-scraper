# SetWordList function

## Description

Sets the word list for the current recognizer context to recognize.

## Parameters

### `hrc`

Handle to the recognizer context.

### `hwl`

Handle to recognition word list to be used.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | The context is invalid or one of the parameters is an invalid pointer. |
| **E_NOTIMPL** | The recognizer does not support this function. |
| **E_OUTOFMEMORY** | Unable to allocate memory to complete the operation. |
| **E_INVALIDARG** | An invalid argument was received. |
| **E_FAIL** | The method was called after [Process](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-process) has been called. |

## Remarks

The word list passed in as the second parameter must already exist. You create a word list by using the [MakeWordList](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-makewordlist) function. The **SetWordList** function does not alter the word list.

To clear the wordlist, pass **NULL** as the second parameter.

It is recommended that you limit the length of individual words in the wordlist to no more than 256 characters and limit memory allocation for wordlists to no more than 128 MB.

## See also

[AddWordsToWordList Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-addwordstowordlist)

[MakeWordList Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-makewordlist)