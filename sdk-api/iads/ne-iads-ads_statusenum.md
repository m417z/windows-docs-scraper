# ADS_STATUSENUM enumeration

## Description

The **ADS_STATUSENUM** enumeration specifies the status of a search preference set with the [IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference) method.

## Constants

### `ADS_STATUS_S_OK:0`

The search preference was set successfully.

### `ADS_STATUS_INVALID_SEARCHPREF`

The search preference specified in the **dwSearchPref** member of the [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure is invalid. Search preferences must be taken from the [ADS_SEARCHPREF_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_searchpref_enum) enumeration.

### `ADS_STATUS_INVALID_SEARCHPREFVALUE`

The value specified in the **vValue** member of the [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure is invalid for the corresponding search preference.

## Remarks

The [IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference) method sets the **dwStatus** member [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure to one of the **ADS_STATUSENUM** values to indicate the status of the corresponding search preference. Callers can use this status value to decide whether to execute a search.

The **ADS_STATUS_INVALID_SEARCHPREF** status value may be set if you set a valid search preference, but that preference is not supported. For example, if you set **ADS_SEARCHPREF_SORT_ON**, but the server you communicate with does not support the LDAP server-side sort control, the **dwStatus** member of the [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure is set to **ADS_STATUS_INVALID_SEARCHPREF** by the [IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference) call.

**Note** Because VBScript cannot read data from a type library, VBScript applications do not recognize the symbolic constants as defined above. You should use the numeric constants instead to set the appropriate flags in your VBScript applications. To use the symbolic constants as a good programming practice, write explicit declarations of such constants, as done in the following code example.

#### Examples

The following code example shows how to use the **ADS_STATUSENUM** enumeration with the [IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference) method to determine the status of a search preference.

```cpp
/***************************************************************************

    SetAndCheckSearchTimeout()

***************************************************************************/

HRESULT SetAndCheckSearchTimeout(IDirectorySearch *pSearch,
                                 DWORD dwTimeout,
                                 ADS_STATUSENUM *pStatus)
{
    if(!pSearch || !pStatus)
    {
        return E_INVALIDARG;
    }

    HRESULT hr;
    ADS_SEARCHPREF_INFO SearchPref;

    SearchPref.dwSearchPref = ADS_SEARCHPREF_TIMEOUT;
    SearchPref.vValue.dwType = ADSTYPE_INTEGER;
    SearchPref.vValue.Integer = dwTimeout;
    SearchPref.dwStatus = ADS_STATUS_S_OK;

    hr = pSearch->SetSearchPreference(&SearchPref, 1);
    if(S_OK != hr)
    {
        return hr;
    }

    *pStatus = SearchPref.dwStatus;
    return S_OK;
}

```

## See also

[ADSI
Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[ADS_SEARCHPREF_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_searchpref_enum)

[ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info)

[IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference)