# IMpeg2TableFilter::AddExtension

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **AddExtension** method adds a table extension to the list of MPEG-2 table sections that the filter sends.

## Parameters

### `p` [in]

Specifies the packet identifier (PID) of the transport stream packets to examine.

### `t` [in]

Specifies the table identifier (TID) of the section to retrieve.

### `e` [in]

Specifies the table_extension identifier of the section to retrieve.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMpeg2TableFilter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-impeg2tablefilter)