# WofEnumEntryProc callback function

## Description

Callback function that gets called for each data source in response to a call to [WofEnumEntries](https://learn.microsoft.com/windows/desktop/api/wofapi/nf-wofapi-wofenumentries).

## Parameters

### `EntryInfo` [in]

The structure that contains specific provider info. The Type of *EntryInfo* is provider-specific. For WOF_PROVIDER_WIM,
it will be PWIM_ENTRY_INFO.

### `UserData` [in, optional]

Optional user defined data specified in the call to [WofEnumEntries](https://learn.microsoft.com/windows/desktop/api/wofapi/nf-wofapi-wofenumentries).

## Return value

A boolean value that indicates whether the enumeration was successful. The enumeration will stop if this callback function returns FALSE.