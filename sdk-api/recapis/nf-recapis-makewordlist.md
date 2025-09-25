# MakeWordList function

## Description

Creates a word list.

## Parameters

### `hrec`

Handle to the recognizer.

### `pBuffer`

Words to insert into the new word list. Separate words in this list with a \0 character and end the list with two \0 characters.

### `phwl`

Handle to the new word list.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |
| **E_POINTER** | The pointer to the word list is incorrect. |
| **E_INVALIDARG** | An invalid argument was received. |
| **E_OUTOFMEMORY** | Unable to allocate memory to complete the operation. |
| **TPC_S_TRUNCATED** | An error is found in one of the words in the list. Possible errors include unsupported characters, spaces at the start or the end of the word or more than a single space between words. All words up to the incorrect word are added to the word list. |

## See also

[AddWordsToWordList Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-addwordstowordlist)

[SetWordList Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setwordlist)