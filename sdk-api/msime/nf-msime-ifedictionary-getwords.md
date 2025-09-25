# IFEDictionary::GetWords

## Description

Gets word entries from a dictionary.

The selection of a word entry can be performed by a combination of

* A string with Japanese phonetic characters, with or without a wildcard at the end of the string.
* A word, with or without a wildcard at its end.
* A Part of Speech

In addition, retrievals by a string with Japanese phonetic characters can be performed by specifying a range in the Hiragana 50-on ordering.

## Parameters

### `pwchFirst` [in]

A text string against which [IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary) entries are matched; the value must be one of the following:

| Value | Meaning |
| --- | --- |
| **NULL** | Low-value. |
|  | Hiragana string (full text to be retrieved). |
|  | Hiragana string ending in "*" (specifying only leading characters of text).<br><br>This can be an initial text string when a range of words is to be retrieved, in which case a wildcard must not be used. |

### `pwchLast` [in]

A text string that is used to end a text string. This must contain the same value as **pwchReading** in the [IMEWRD](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imewrd) structure when a retrieval is performed by a single value; that is, not by a range value. The value must be one of the following:

| Value | Meaning |
| --- | --- |
| **NULL** | High-value. |
|  | Hiragana string (full text to be retrieved). |
|  | Hiragana string ending in "*" (specifying only leading characters of text). |

### `pwchDisplay` [in]

A display string against which [IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary) entries are matched; the value must be one of the following:

| Value | Meaning |
| --- | --- |
| **NULL** | Means "*". |
|  | Any Japanese string. |
|  | Japanese string ending in "*". |

### `ulPos` [in]

Filter(s) on the Microsoft IME public Parts of Speech. This is a combination of one or more of the following flags:

#### IFED_POS_NONE

#### IFED_POS_NOUN

#### IFED_POS_VERB

#### IFED_POS_ADJECTIVE

#### IFED_POS_ADJECTIVE_VERB

#### IFED_POS_ADVERB

#### IFED_POS_ADNOUN

#### IFED_POS_CONJUNCTION

#### IFED_POS_INTERJECTION

#### IFED_POS_INDEPENDENT

#### IFED_POS_INFLECTIONALSUFFIX

#### IFED_POS_PREFIX

#### IFED_POS_SUFFIX

#### IFED_POS_AFFIX

#### IFED_POS_TANKANJI

#### IFED_POS_IDIOMS

#### IFED_POS_SYMBOLS

#### IFED_POS_PARTICLE

#### IFED_POS_AUXILIARY_VERB

#### IFED_POS_SUB_VERB

#### IFED_POS_DEPENDENT

#### IFED_POS_ALL

### `ulSelect` [in]

Specifies the query output of a word. This is a combination of one or more of the following flags:

#### IFED_SELECT_NONE

#### IFED_SELECT_READING

#### IFED_SELECT_DISPLAY

#### IFED_SELECT_POS

#### IFED_SELECT_COMMENT

#### IFED_SELECT_ALL

### `ulWordSrc` [in]

Specifies the word source. When the [IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary) is a user dictionary, this is a combination of one or more of the following flags:

#### IFED_REG_NONE

#### IFED_REG_USER

#### IFED_REG_AUTO

#### IFED_REG_GRAMMAR

#### IFED_REG_ALL

### `pchBuffer` [in, out]

Buffer provided by the caller to receive the data.

### `cbBuffer` [in]

The size of *pchBuffer*.

### `pcWrd` [out]

The number of [IMEWRD](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imewrd) structures returned in *pchBuffer*. If more entries are found than *pchBuffer* can store, **IFED_S_MORE_ENTRIES** will be returned.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** |  |
| **IFED_S_MORE_ENTRIES** | The client must call [NextWords](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-nextwords) to get additional [IMEWRD](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imewrd) structures. |
| **IFED_E_NO_ENTRY** |  |
| **E_OUTOFMEMORY** |  |
| **E_FAIL** |  |

## See also

[IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary)

[IMEWRD](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imewrd)

[NextWords](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-nextwords)