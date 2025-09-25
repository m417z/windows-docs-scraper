DWORD WSManGetSessionOptionAsString(
  [in]            WSMAN_SESSION_HANDLE session,
                  WSManSessionOption   option,
                  DWORD                stringLength,
  [out, optional] PWSTR                string,
  [out]           DWORD                *stringLengthUsed
);