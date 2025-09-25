# IFEDictionary::Open

## Description

Opens a dictionary file.

This method opens an existing dictionary file and associates it with this [IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary) object. To implement a multiple dictionary facility, multiple open and release procedures must be carried out.

## Parameters

### `pchDictPath` [in, optional]

Points to a **NULL**-terminated file name string to be opened. If *pchDictPath* is **NULL** or an empty string, the user dictionary opened by the IME kernel will be used. If *pchDictPath* is an empty string, the name of user dictionary will be copied into *pchDictPath*, in which case the size of *pchDictPath* must be **MAX_PATH**.

### `pshf` [out]

The [IMESHF](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imeshf) header of the opened file. Can be **NULL**.

## Return value

One of the following:

* **S_OK**
* **JDIC_S_EMPTY_DICTIONARY**
* **IFED_E_NOT_FOUND**
* **IFED_E_INVALID_FORMAT**
* **IFED_E_OPEN_FAILED**
* **E_FAIL**

## See also

[IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary)

[IMESHF](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imeshf)