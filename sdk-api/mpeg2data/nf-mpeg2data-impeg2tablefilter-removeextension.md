# IMpeg2TableFilter::RemoveExtension

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **RemoveExtension** method removes a table extension from the list of MPEG-2 table sections that the filter sends.

## Parameters

### `p` [in]

Specifies the packet identifier (PID) of the table.

### `t` [in]

Specifies the table identifier (TID) of the table.

### `e` [in]

Specifies the table_extension identifier to remove from the list.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMpeg2TableFilter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-impeg2tablefilter)