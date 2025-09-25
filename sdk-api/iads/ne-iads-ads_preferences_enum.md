# ADS_PREFERENCES_ENUM enumeration

## Description

The **ADS_PREFERENCES_ENUM** enumeration specifies the query preferences of the OLE DB provider for ADSI.

## Constants

### `ADSIPROP_ASYNCHRONOUS:0`

Requests an asynchronous search.

### `ADSIPROP_DEREF_ALIASES:0x1`

Specifies that aliases of found objects are to be resolved. Use [ADS_DEREFENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_derefenum) to specify how to perform this operation.

### `ADSIPROP_SIZE_LIMIT:0x2`

Specifies the size limit that the server should observe in a search. The size limit is the maximum number of returned objects. A zero value indicates that no size limit is imposed. The server stops searching once the size limit is reached and returns the results accumulated up to that point.

### `ADSIPROP_TIME_LIMIT:0x3`

Specifies the time limit, in seconds, that the server should observe in a search. A zero value indicates that no time limit restriction is imposed. When the time limit is reached, the server stops searching and returns results accumulated to that point.

### `ADSIPROP_ATTRIBTYPES_ONLY:0x4`

Indicates that the search should obtain only the name of attributes to which values have been assigned.

### `ADSIPROP_SEARCH_SCOPE:0x5`

Specifies the search scope that should be observed by the server. For more information about the appropriate settings, see the [ADS_SCOPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_scopeenum) enumeration.

### `ADSIPROP_TIMEOUT:0x6`

Specifies the time limit, in seconds, that a client will wait for the server to return the result.

### `ADSIPROP_PAGESIZE:0x7`

Specifies the page size in a paged search. For each request by the client, the server returns, at most, the number of objects as set by the page size.

### `ADSIPROP_PAGED_TIME_LIMIT:0x8`

Specifies the time limit, in seconds, that the server should observe to search a page of results; this is opposed to the time limit for the entire search.

### `ADSIPROP_CHASE_REFERRALS:0x9`

Specifies that referrals may be chased. If the root search is not specified in the naming context of the server or when the search results cross a naming context (for example, when you have child domains and search in the parent domain), the server sends a referral message to the client which the client can choose to ignore or chase. By default, this option is set to ADS_CHASE_REFERRALS_EXTERNAL. For more information about referrals chasing, see [ADS_CHASE_REFERRALS_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_chase_referrals_enum).

### `ADSIPROP_SORT_ON:0xa`

Specifies that the server sorts the result set. Use the [ADS_SORTKEY](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_sortkey) structure to specify the sort keys.

### `ADSIPROP_CACHE_RESULTS:0xb`

Specifies if the result should be cached on the client side. By default, ADSI caches the result set. Turning off this option may be more desirable for large result sets.

### `ADSIPROP_ADSIFLAG:0xc`

Allows the OLEDB client to specify bind flags to use when binding to the server. Valid values are those allowed by [ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject). It is accessed from ADO scripts using the property name "ADSI Flag."

## Remarks

Because VBScript cannot read data from a type library, VBScript applications do not recognize the symbolic constants as defined above. Instead, use the numerical constants to set the appropriate flags in your VBScript application. To use the symbolic constants, as a good programming practice, write explicit declarations of such constants, as done here, in your VBScript application.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[ADS_CHASE_REFERRALS_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_chase_referrals_enum)

[ADS_DEREFENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_derefenum)

[ADS_SCOPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_scopeenum)

[ADS_SORTKEY](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_sortkey)