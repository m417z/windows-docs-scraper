# IGenericDescriptor::GetBody

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **GetBody** method returns the body of the descriptor.

## Parameters

### `ppbVal` [out]

Receives a pointer to a buffer. To get the size of the buffer, call the [IGenericDescriptor::GetLength](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nf-mpeg2psiparser-igenericdescriptor-getlength) method. The buffer contains the body of the descriptor, in network byte order (Big Endian). The caller is responsible for converting the data to Little Endian byte order. The caller must free the buffer by calling the **CoTaskMemFree** function.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## See also

[IGenericDescriptor Interface](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor)