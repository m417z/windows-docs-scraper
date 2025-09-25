# IMSVidGenericSink2::AddFilter

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

**Note**This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 or later.

The **AddFilter** method specifies a DirectShow filter that is added to the graph when this segment is built.

## Parameters

### `bstrName`

**BSTR** that contains the CLSID of the filter. The **BSTR** must use the following format: `{XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX}`

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Use this method to insert additional filters to the graph other than the sink filter. To specify the sink filter, call [IMSVidGenericSink::SetSinkFilter](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidgenericsink-setsinkfilter).

## See also

[IMSVidGenericSink2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidgenericsink2)