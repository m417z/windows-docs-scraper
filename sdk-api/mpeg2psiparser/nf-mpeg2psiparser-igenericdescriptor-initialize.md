# IGenericDescriptor::Initialize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **Initialize** method initializes the object. This method is called internally by the various methods that return **IGenericDescriptor** interface pointers, so applications typically should not call it.

## Parameters

### `pbDesc` [in]

Pointer to a buffer that contains the raw descriptor data.

### `bCount` [in]

Specifies the size of the buffer, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **MPEG2_E_ALREADY_INITIALIZED** | The object is already initialized. |
| **MPEG2_E_MALFORMED_TABLE** | Invalid or malformed descriptor. |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## See also

[IGenericDescriptor Interface](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor)