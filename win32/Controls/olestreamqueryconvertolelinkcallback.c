typedef HRESULT(STDAPICALLTYPE* OLESTREAMQUERYCONVERTOLELINKCALLBACK)
    (_In_ LPCLSID       pClsid,
    _In_ LPOLESTR       szClass,
    _In_opt_ LPOLESTR   szTopicName,
    _In_opt_ LPOLESTR   szItemName,
    _In_opt_ LPOLESTR   szUNCName,
    _In_opt_ ULONG      linkUpdatingOption,
    _In_opt_ PVOID      pvContext);