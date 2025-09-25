# ADS_SCOPEENUM enumeration

## Description

The **ADS_SCOPEENUM** enumeration specifies the scope of a directory search.

## Constants

### `ADS_SCOPE_BASE:0`

Limits the search to the base object. The result contains, at most, one object.

### `ADS_SCOPE_ONELEVEL:1`

Searches one level of the immediate children, excluding the base object.

### `ADS_SCOPE_SUBTREE:2`

Searches the whole subtree, including all the children and the base object itself.

## Remarks

If you do not explicitly set the search scope, the default is **ADS_SCOPE_SUBTREE**.

Because VBScript cannot read data from a type library, VBScript applications do not recognize the symbolic constants as defined above. Use the numerical constants, instead, to set the appropriate flags in your VBScript applications. To use the symbolic constants as a good programming practice, create explicit declarations of such constants, as done here, in your VBScript applications.

#### Examples

Search scope is one of the search preferences clients can specify. The following code example shows how to accomplish this using the [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure, together with the elements defined in the [ADS_SEARCHPREF_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_searchpref_enum) and this enumeration.

```cpp
ADS_SEARCHPREF_INFO prefInfo;
prefInfo.dwSearchPref = ADS_SEARCHPREF_SEARCH_SCOPE;
prefInfo.vValue.dwType = ADSTYPE_INTEGER;
prefInfo.vValue.Integer = ADS_SCOPE_SUBTREE;
```

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[ADS_SEARCHPREF_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_searchpref_enum)

[ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info)