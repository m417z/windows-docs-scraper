# ISpellChecker::GetOptionValue

## Description

Retrieves the value associated with the given option.

## Parameters

### `optionId` [in]

The option identifier.

### `value` [out, retval]

The value associated with *optionId*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **E_ INVALIDARG** | *optionId* is an empty string, or it is not one of the available options. |
| **E_POINTER** | *optionId* is a null pointer. |

## See also

[ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker)