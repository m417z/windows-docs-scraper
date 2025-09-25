# IImePlugInDictDictionaryList::GetDictionariesInUse

## Description

Obtains the list of Dictionary IDs (**GUID**) of the IME plug-in dictionaries which are in use by IME, with their creation dates and encryption flags.

## Parameters

### `prgDictionaryGUID` [out]

Array of the dictionary IDs (**GUID**) of the IME plug-in dictionaries which are in use by IME.

### `prgDateCreated` [in, out]

Array of the dates of creation for each of the IME plug-in dictionaries returned by *prgDictionaryGUID*.

### `prgfEncrypted` [in, out]

Array of flags indicating whether each dictionary is encrypted or not for each of the IME plug-in dictionaries returned by *prgDictionaryGUID*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Succeeded. |
| **E_OUTOFMEMORY** | Out of memory. |
| **E_FAIL** | Other errors. |

## See also

[IImePlugInDictDictionaryList](https://learn.microsoft.com/windows/desktop/api/msimeapi/nn-msimeapi-iimeplugindictdictionarylist)