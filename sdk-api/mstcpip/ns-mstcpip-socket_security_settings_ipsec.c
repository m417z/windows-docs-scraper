typedef struct _SOCKET_SECURITY_SETTINGS_IPSEC {
  SOCKET_SECURITY_PROTOCOL SecurityProtocol;
  ULONG                    SecurityFlags;
  ULONG                    IpsecFlags;
  GUID                     AuthipMMPolicyKey;
  GUID                     AuthipQMPolicyKey;
  GUID                     Reserved;
  UINT64                   Reserved2;
  ULONG                    UserNameStringLen;
  ULONG                    DomainNameStringLen;
  ULONG                    PasswordStringLen;
  wchar_t                  AllStrings[0];
} SOCKET_SECURITY_SETTINGS_IPSEC;