# IITPropList::SaveHeader

## Description

Saves the property ID and data type from the property list to a buffer. Only saves properties marked with a persistence state of TRUE.

## Parameters

### `lpvData` [out]

Pointer to a buffer to fill.

### `dwHdrSize` [in]

Size of the buffer.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The property list was successfully saved. |

## Remarks

Make sure to pass a buffer large enough to hold the property list. Use [IITPropList::GetHeaderSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nf-infotech-iitproplist-getheadersize) to determine the buffer size to pass.

## See also

[IITPropList](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitproplist)