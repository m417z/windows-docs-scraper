# IITWordWheel::Count

## Description

Returns the number of entries in a word wheel.

## Parameters

### `pcEntries` [in]

Number of entries in word wheel.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The count was successfully returned. |
| **E_NOTOPEN** | The word wheel has not been opened. |
| **E_POINTER** | The *pcEntries* parameter was an invalid pointer. |

## See also

[IITWordWheel](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitwordwheel)