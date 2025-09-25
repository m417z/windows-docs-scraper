const DEVPROPERTY* WINAPI DevFindProperty(
    [in] const DEVPROPKEY *pKey,
    [in] DEVPROPSTORE Store,
    [in] PCWSTR pszLocaleName,
    [in] ULONG cProperties,
    [in] const DEVPROPERTY *pProperties);