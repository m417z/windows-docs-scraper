# ISBE2EnumStream::Next

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Retrieves the next *n* streams in the collection.

## Parameters

### `cRequest` [in]

The number of streams to retrieve.

### `pStreamDesc` [in, out]

Pointer to an array of [SBE2_STREAM_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/ns-sbe-sbe2_stream_desc) structures, with at least *cRequest* elements. The method copies up to *cRequest* elements into the array.

### `pcReceived` [out]

Receives the number of elements returned in the *pStreamDesc* array. This parameter can be **NULL** if *cRequest* is 1.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded and retrieved *cRequest* elements. |
| **S_FALSE** | The method retrieved fewer elements than requested. |
| **E_FAIL** | The streams have changed, so the caller must enumerate them again. |

## See also

[ISBE2EnumStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2enumstream)