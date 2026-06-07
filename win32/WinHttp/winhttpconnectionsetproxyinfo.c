DWORD WINAPI WinHttpConnectionSetProxyInfo(
    _In_z_ PCWSTR                          pwszConnectionName,
    _In_   WINHTTP_CONNECTION_PROXY_TYPE    Type,
    _In_   const WINHTTP_CONNECTION_PROXY_INFO *pProxyInfo
);