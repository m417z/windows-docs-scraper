DWORD WINAPI WinHttpConnectionSetPolicyEntries(
    _In_ HINTERNET                              hSession,
    _In_ WINHTTP_CONNECTION_POLICY_TAG          PolicyEntryTag,
    _In_ WINHTTP_CONNECTION_POLICY_ENTRY_LIST  *pPolicyEntryList
);