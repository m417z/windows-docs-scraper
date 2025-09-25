# IFEDictionary::RegisterWord

## Description

Registers a new word or deletes an existing word in the [IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary).

## Parameters

### `reg` [in]

Type of operation to perform. This can be one of the following values:

| Value | Meaning |
| --- | --- |
| **IFED_REG_HEAD** | Register the word at the head of the dictionary. |
| **IFED_REG_TAIL** | Register the word at the tail of the dictionary. |
| **IFED_REG_DEL** | Delete the word from the dictionary. |

### `pwrd` [in]

An [IMEWRD](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imewrd) structure specifying the word to register or delete.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **IFED_E_NOT_USER_DIC** | This [IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary) object is not a user dictionary. |
| **IFED_S_WORD_EXISTS** | The word is already registered. |
| **IFED_E_USER_COMMENT** | Failed to insert the user comment. |
| **S_FALSE** | Failed to register or delete the word. |
| **E_FAIL** | An unexpected error. |

## See also

[IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary)

[IMEWRD](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imewrd)