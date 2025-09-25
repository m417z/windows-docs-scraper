# ISpellCheckProvider::SetOptionValue

## Description

Sets the value associated with the given option.

## Parameters

### `optionId` [in]

The option identifier.

### `value` [in]

The value to associate with *optionId*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **E_ INVALIDARG** | *optionId* is an empty string, or it is not one of the available options. |
| **E_POINTER** | *optionId* is a null pointer. |

## Remarks

This method is called by the system, which reads the option values that were set by the user in the control panel and sends them to the [ISpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-ispellcheckprovider). If the option was not set, this method will not be called and the provider should initialize itself internally with the default value for the option.

## See also

[ISpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-ispellcheckprovider)