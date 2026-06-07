typedef struct _WINHTTP_CONNECTION_PROXY_INFO {
    DWORD                                  Version;
    WCHAR                                 *pwszFriendlyName;
    DWORD                                  Flags;
    WINHTTP_CONNECTION_PROXY_INFO_SWITCH   Switch;
    union {
        struct {
            WCHAR *pwszServer;
            WCHAR *pwszUsername;
            WCHAR *pwszPassword;
            WCHAR *pwszException;
            WCHAR *pwszExtraInfo;
            WORD   Port;
        } Config;
        struct {
            WCHAR *pwszScript;
            WCHAR *pwszUsername;
            WCHAR *pwszPassword;
        } Script;
    };
} WINHTTP_CONNECTION_PROXY_INFO;