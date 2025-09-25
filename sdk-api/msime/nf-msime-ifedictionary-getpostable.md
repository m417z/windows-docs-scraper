# IFEDictionary::GetPosTable

## Description

Obtains the public POS (Part of Speech) table.

## Parameters

### `prgPosTbl` [out]

Pointer to the array of [POSTBL](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-postbl) structures.

### `pcPosTbl` [out]

Pointer to the number of [POSTBL](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-postbl) structures in the returned array. Can be **NULL**.

## Return value

**S_OK** if successful, otherwise **E_FAIL**.

## See also

[IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary)

[POSTBL](https://learn.microsoft.com/windows/desktop/api/msime/ns-msime-postbl)