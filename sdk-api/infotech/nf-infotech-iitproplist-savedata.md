# IITPropList::SaveData

## Description

Saves the data size and data from the property list to a buffer.

## Parameters

### `lpvHeader` [in]

Pointer to a buffer containing the header.

### `dwHdrSize` [in]

Size of the buffer containing the header.

### `lpvData` [out]

Pointer to a buffer to fill.

### `dwBufSize` [in]

Size of the buffer to fill.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The property list was successfully saved. |

## Remarks

Make sure to pass a buffer large enough to hold the property list. Use [IITPropList::GetDataSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nf-infotech-iitproplist-getdatasize) to determine the buffer size to pass.

## See also

[IITPropList](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitproplist)