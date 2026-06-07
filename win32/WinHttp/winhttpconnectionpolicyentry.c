typedef struct _WINHTTP_CONNECTION_POLICY_ENTRY {
    PCWSTR  pwszHost;
    PCWSTR  pwszAppId;
    DWORD   cbAppSid;
    PBYTE   pbAppSid;
    DWORD   nConnections;
    PCWSTR *ppwszConnections;
    DWORD   dwPolicyEntryFlags;
} WINHTTP_CONNECTION_POLICY_ENTRY;