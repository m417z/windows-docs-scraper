# ISBE2EnumStream::Clone

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Creates a copy of the enumerator object. The copy starts with the same enumeration state as the original.

## Parameters

### `ppIEnumStream` [out]

Receives a pointer to the [ISBE2EnumStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2enumstream) interface of the new enumerator object. This method allocates memory for the stream enumeration object. The caller is responsible for releasing the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Null pointer argument. |
| **E_OUTOFMEMORY** | Out of memory for enumeration object. |

## See also

[ISBE2EnumStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2enumstream)