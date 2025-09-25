# IFEDictionary::NextWords

## Description

Gets the next word entry from a dictionary.

This method is used only after [GetWords](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-getwords) to get additional words.

## Parameters

### `pchBuffer` [in, out]

Buffer provided by the caller to receive the data.

### `cbBuffer` [in]

The size of *pchBuffer*.

### `pcWrd` [out]

The number of [IMEWRD](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imewrd) structures returned in *pchBuffer*. If more entries are found than *pchBuffer* can store, **IFED_S_MORE_ENTRIES** will be returned.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** |  |
| **IFED_S_MORE_ENTRIES** | The client must call [NextWords](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-nextwords) to get additional [IMEWRD](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imewrd) structures. |
| **E_FAIL** |  |

## See also

[GetWords](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-getwords)

[IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary)

[IMEWRD](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-imewrd)