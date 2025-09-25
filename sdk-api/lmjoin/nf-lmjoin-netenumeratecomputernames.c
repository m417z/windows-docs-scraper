NET_API_STATUS NET_API_FUNCTION NetEnumerateComputerNames(
  [in, optional] LPCWSTR                Server,
  [in]           NET_COMPUTER_NAME_TYPE NameType,
  [in]           ULONG                  Reserved,
  [out]          PDWORD                 EntryCount,
  [out]          LPWSTR                 **ComputerNames
);