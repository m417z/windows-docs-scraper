DWORD WINAPI FWOpenPolicyStore(
  WORD                          wBinaryVersion,
  __in_opt PCWSTR               wszMachineOrGPO,
  FW_STORE_TYPE                 StoreType,
  FW_POLICY_ACCESS_RIGHT        AccessRight,
  DWORD                         dwFlags,
  __out FW_POLICY_STORE_HANDLE* phPolicyStore
);