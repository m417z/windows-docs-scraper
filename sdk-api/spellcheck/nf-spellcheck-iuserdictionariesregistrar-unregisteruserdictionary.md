# IUserDictionariesRegistrar::UnregisterUserDictionary

## Description

Unregisters a previously registered user dictionary. The dictionary will no longer be used by the spell checking functionality.

## Parameters

### `dictionaryPath` [in]

The path of the dictionary file to be unregistered.

### `languageTag` [in]

The language for which this dictionary was used. It must match the language passed to [RegisterUserDictionary](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-iuserdictionariesregistrar-registeruserdictionary).

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | Successful. |
| E_POINTER | *dictionaryPath* or *languageTag* is a null pointer. |

## Remarks

**Note** To unregister a given file, this method must be passed the same arguments that were previously used to register it.

## See also

[IUserDictionariesRegistrar](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-iuserdictionariesregistrar)