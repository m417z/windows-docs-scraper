HRESULT GetEnterpriseIdForNetworkPath(
    _In_ PCWSTR networkPath,
    _Outptr_result_maybenull_ PWSTR* identity,
    _Out_ bool* isNetworkFile
    );