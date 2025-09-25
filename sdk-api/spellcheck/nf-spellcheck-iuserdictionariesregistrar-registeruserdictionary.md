# IUserDictionariesRegistrar::RegisterUserDictionary

## Description

Registers a file to be used as a user dictionary for the current user, until unregistered.

## Parameters

### `dictionaryPath` [in]

The path of the dictionary file to be registered.

### `languageTag` [in]

The language for which this dictionary should be used. If left empty, it will be used for any language.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | Successful. |
| S_FALSE | The file is already registered for the language. |
| E_INVALIDARG | The file doesn’t exist or isn't valid, or it doesn't have a valid extension (.dic, .exc, or .acl) |
| E_POINTER | *dictionaryPath* or *languageTag* is a null pointer. |

## Remarks

The filename must have the extension .dic (added words), .exc (excluded words), or .acl (autocorrect word pairs). The files are UTF-16 LE plaintext that must start with the appropriate Byte Order Mark (BOM).
Each line contains a word (in the Added and Excluded word lists), or an autocorrect pair with the words separated by a vertical bar ("|") (in the AutoCorrect word list). The wordlist in which the dictionary is included is inferred through the file extension.

A file registered for a language subtag will be picked up for all languages that contain it. For example, a dictionary registered for "en" will also be used by an "en-US" spell checker.

## See also

[IUserDictionariesRegistrar](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-iuserdictionariesregistrar)