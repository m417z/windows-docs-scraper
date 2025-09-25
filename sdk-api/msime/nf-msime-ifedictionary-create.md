# IFEDictionary::Create

## Description

Creates a new dictionary file.

## Parameters

### `pchDictPath` [in]

A **NULL**-terminated string containing the path and name for the new dictionary file to be created.

### `pshf` [in]

The [IMESHF](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imeshf) header for the new dictionary.

## Return value

One of the following:

* **S_OK**
* **IFED_S_EMPTY_DICTIONARY**
* **E_OUTOFMEMORY**
* **E_FAIL**

## See also

[IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary)

[IMESHF](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imeshf)