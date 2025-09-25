# ADS_VLV structure

## Description

The **ADS_VLV** structure contains metadata used to conduct virtual list view (VLV) searches. This structure serves two roles. First, it specifies the search preferences sent to the server. Second, it returns the VLV metadata from the server.

## Members

### `dwBeforeCount`

Indicates the number of entries, before the target entry, that the client requests from the server.

### `dwAfterCount`

Indicates the number of entries, after the target entry, that the client requests from the server.

### `dwOffset`

On input, indicates the target entry's requested offset within the list. If the client specifies an offset which equals the client's assumed content count, then the target is the last entry in the list. On output, indicates the server's best estimate as to the actual offset of the returned target entry's position in the list.

### `dwContentCount`

The input value represents the client's estimated value for the content count. The output value is the server's estimate of the content count. If the client sends a content count of zero, this means that the server must use its estimate of the content count in place of the client's.

### `pszTarget`

Optional. Null-terminated Unicode string that indicates the desired target entry requested by the client. If this parameter contains a non-**NULL** value, the server ignores the value specified in **dwOffset** and search for the first target entry whose value for the primary sort key is greater than or equal to the specified string, based on the sort order of the list.

### `dwContextIDLength`

Optional. Parameter that indicates the length of the context identifier. On input, if passing a context identifier in **lpContextID**, this must be set to the size of the identifier in bytes. Otherwise, it must be set equal to zero. On output, if **lpContextID** contains a non-**NULL** value, this indicates the length, in bytes, of the context ID returned by the server.

### `lpContextID`

Optional. Indicates the server-generated context identifier. This parameter may be sent to clients. If a client receives this parameter, it should return it unchanged in a subsequent request which relates to the same list. This interaction may enhance the performance and effectiveness of the servers. If not passing a context identifier to the server, this member must be set to **NULL** value. On output, if this member contains a non-**NULL** value, this points to the context ID returned by the server.

## Remarks

To set the VLV by **dwContentCount** and **dwOffset**, you must also set the **pszTarget** to a **NULL** value. If **pszTarget** contains a non-**NULL** value, then it is used as the offset, otherwise, **lOffset** is used as the offset. It is recommended that you initialize the structure to zero.

#### Examples

The following code example shows how to retrieve the first 30 entries in a result set.

```cpp
ADS_SEARCHPREF_INFO prefInfo[2];
ADS_VLV vlv;

vlv.dwBeforeCount=0;
vlv.dwAfterCount=30;
vlv.dwOffset=1;
vlv.dwContentCount=0;
vlv.pszTarget = NULL;
vlv.dwContextIDLength = 0;
vlv.lpContextID = NULL;

// VLV set preferences.
prefInfo[0].dwSearchPref = ADS_SEARCHPREF_VLV;
prefInfo[0].vValue.dwType = ADSTYPE_PROV_SPECIFIC;
prefInfo[0].vValue.ProviderSpecific.dwLength = sizeof(ADS_VLV);
prefInfo[0].vValue.ProviderSpecific.lpValue = (LPBYTE) &vlv;

// Sort key set preferences.
prefInfo[1].dwSearchPref = ADS_SEARCHPREF_SORT_ON;
prefInfo[1].vValue.dwType = ADSTYPE_PROV_SPECIFIC;
prefInfo[1].vValue.ProviderSpecific.dwLength = sizeof(ADS_SORTKEY);
prefInfo[1].vValue.ProviderSpecific.lpValue = (LPBYTE) pSortKey;

hr = m_pSearch->SetSearchPreference(prefInfo, 2);
```

The following code example shows how to retrieve the first 50 entries in a result set that start with the letters "Ha".

```cpp
ADS_VLV vlv;

vlv.dwBeforeCount=0;
vlv.dwAfterCount=50;
vlv.pszTarget= L"Ha";
vlv.lpContextID = NULL;
vlv.dwContextIDLength = 0;

// For more information about how to set the preference, see the previous code example.
```

The following code example shows how to retrieve the first 100 entries at the 60% approximate target, assuming that the server previously returned **dwContentCount** as 4294.

**Note** vlvResp represents an **ADS_VLV** structure previously returned by the server.

```cpp
ADS_VLV vlv;

vlv.dwBeforeCount=50;
vlv.dwAfterCount=50;
vlv.dwOffset=2577;
vlv.dwContentCount=4294;
vlv.pszTarget = NULL;
vlv.dwContextIDLength = vlvResp.dwContextIDLength;
vlv.lpContextID = vlvResp.lpContextID;
```

## See also

[ADS_SEARCHPREF_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_searchpref_enum)

[How to Search
Using VLV](https://learn.microsoft.com/windows/desktop/ADSI/how-to-search-using-vlv)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)