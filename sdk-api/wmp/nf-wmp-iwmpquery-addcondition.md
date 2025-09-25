# IWMPQuery::addCondition

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **addCondition** method adds a condition to the compound query using AND logic.

## Parameters

### `bstrAttribute` [in]

String containing the attribute name.

### `bstrOperator` [in]

String containing the operator. See Remarks for supported values.

### `bstrValue` [in]

String containing the attribute value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Conditions contained in a compound query are organized into condition groups. Multiple conditions within a condition group are always concatenated by using AND logic. Condition groups are always concatenated to each other by using OR logic. To start a new condition group, call [IWMPQuery::beginNextGroup](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpquery-beginnextgroup).

Compound queries using **IWMPQuery** are not case sensitive.

A list of values for the *bstrAttribute* parameter can be found in the [Alphabetical Attribute Reference](https://learn.microsoft.com/windows/desktop/WMP/alphabetical-attribute-reference) section.

The following table lists the supported values for *bstrOperator*.

| String | Applies To |
| --- | --- |
| BeginsWith | Strings |
| Contains | Strings |
| Equals | All types |
| GreaterThan | Numbers, Dates |
| GreaterThanOrEquals | Numbers, Dates |
| LessThan | Numbers, Dates |
| LessThanOrEquals | Numbers, Dates |
| NotBeginsWith | Strings |
| NotContains | Strings |
| NotEquals | All types |

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[Alphabetical Attribute Reference](https://learn.microsoft.com/windows/desktop/WMP/alphabetical-attribute-reference)

[IWMPMediaCollection2::createQuery](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmediacollection2-createquery)

[IWMPMediaCollection2::getPlaylistByQuery](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmediacollection2-getplaylistbyquery)

[IWMPMediaCollection2::getStringCollectionByQuery](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmediacollection2-getstringcollectionbyquery)

[IWMPQuery Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpquery)