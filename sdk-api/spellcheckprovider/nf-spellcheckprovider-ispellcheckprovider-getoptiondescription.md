# ISpellCheckProvider::GetOptionDescription

## Description

Retrieves the information (id, description, heading and labels) of a specific option.

## Parameters

### `optionId` [in]

Identifier of the option to be retrieved.

### `value` [out, retval]

[IOptionDescription](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ioptiondescription) interface that contains the information about *optionId*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **E_ INVALIDARG** | *optionId* is an empty string, or it is not one of the available options. |
| **E_POINTER** | *optionId* is a null pointer. |

## See also

[IOptionDescription](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ioptiondescription)

[ISpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-ispellcheckprovider)