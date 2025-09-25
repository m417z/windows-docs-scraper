# IImePlugInDictDictionaryList::DeleteDictionary

## Description

Deletes a dictionary from the IME's plug-in dictionary list.

## Parameters

### `bstrDictionaryGUID` [in]

The dictionary ID (**GUID**) of the dictionary to be removed from the list.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The specified dictionary existed in the list and was successfully removed. |
| **S_FALSE** | The specified dictionary does not exist in the list. |
| **E_FAIL** | Other errors. |

## See also

[IImePlugInDictDictionaryList](https://learn.microsoft.com/windows/desktop/api/msimeapi/nn-msimeapi-iimeplugindictdictionarylist)