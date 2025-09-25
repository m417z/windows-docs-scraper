# IITPropList::GetDataSize

## Description

Returns the number of bytes needed to save the property data.

## Parameters

### `lpvHeader` [in]

Pointer to a buffer containing the header.

### `dwHdrSize` [in]

Size of the header buffer.

### `dwDataSize` [out, ref]

Size in bytes.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The size was successfully returned. |
| **E_INVALIDARG** | The *lpvHeader* parameter is NULL, or *dwHdrSize* is too small. |
| **E_BADVALUE** | Invalid header buffer. |

## See also

[IITPropList](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitproplist)

[IITPropList::GetHeaderSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nf-infotech-iitproplist-getheadersize)