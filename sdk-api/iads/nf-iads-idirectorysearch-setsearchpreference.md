# IDirectorySearch::SetSearchPreference

## Description

The **IDirectorySearch::SetSearchPreference** method specifies a search preference for obtaining data in a subsequent search.

## Parameters

### `pSearchPrefs` [in]

Provides a caller-allocated array of [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structures that contain the search preferences to be set.

### `dwNumPrefs` [in]

Provides the size of the *pSearchPrefs* array.

## Return value

This method supports the standard return values, as well as the following:

For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)