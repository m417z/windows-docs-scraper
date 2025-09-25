# IMSVidGenericSink::SetSinkFilter

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

**Note**This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 or later.

The **SetSinkFilter** method sets the filter for the sink.

## Parameters

### `bstrName` [in]

**BSTR** that contains the CLSID of the sink filter. The **BSTR** must use the following format: `{XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX}`.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |

## See also

[IMSVidGenericSink Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidgenericsink)