# IMFAttributes::Compare

## Description

Compares the attributes on this object with the attributes on another object.

## Parameters

### `pTheirs` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the object to compare with this object.

### `MatchType` [in]

Member of the [MF_ATTRIBUTES_MATCH_TYPE](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attributes_match_type) enumeration, specifying the type of comparison to make.

### `pbResult` [out]

Receives a Boolean value. The value is **TRUE** if the two sets of attributes match in the way specified by the *MatchType* parameter. Otherwise, the value is **FALSE**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If *pThis* is the object whose **Compare** method is called, and *pTheirs* is the object passed in as the *pTheirs* parameter, the following comparisons are defined by *MatchType*.

| Match type | Returns **TRUE** if and only if |
| --- | --- |
| **MF_ATTRIBUTES_MATCH_OUR_ITEMS** | For every attribute in *pThis*, an attribute with the same key and value exists in *pTheirs*. |
| **MF_ATTRIBUTES_MATCH_THEIR_ITEMS** | For every attribute in *pTheirs*, an attribute with the same key and value exists in *pThis*. |
| **MF_ATTRIBUTES_MATCH_ALL_ITEMS** | The key/value pairs are identical in both objects. |
| **MF_ATTRIBUTES_MATCH_INTERSECTION** | Take the intersection of the keys in *pThis* and the keys in *pTheirs*. The values associated with those keys are identical in both *pThis* and *pTheirs*. |
| **MF_ATTRIBUTES_MATCH_SMALLER** | Take the object with the smallest number of attributes. For every attribute in that object, an attribute with the same key and value exists in the other object. |

The *pTheirs* and *pbResult* parameters must not be **NULL**. If either parameter is **NULL**, an access violation occurs.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)