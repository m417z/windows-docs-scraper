# IFEDictionary::ExistWord

## Description

Determines if the specified word exists in [IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary).

## Parameters

### `pwrd` [in]

An [IMEWRD](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imewrd) structure specifying the word to check.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The word exists. |
| **S_FALSE** | The word does not exist. |
| **E_FAIL** | An unexpected error. |

## See also

[IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary)

[IMEWRD](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imewrd)