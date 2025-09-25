# AddWordsToWordList function

## Description

Adds one or more words to the word list.

## Parameters

### `hwl`

Handle to the word list.

### `pwcWords`

Words to add to the word list. Separate words in this list with a \0 character and end the list with two \0 characters. Words that already exist in the list are not added.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | An invalid argument was received. |
| **E_FAIL** | Returned when the word list handle parameter is invalid. |
| **E_POINTER** | The pointer to the word list is incorrect. |

## See also

[MakeWordList Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-makewordlist)

[SetWordList Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setwordlist)