DWORD WINAPI FWEnumFirewallRules(
  FW_POLICY_STORE_HANDLE                         hPolicyStore,
  DWORD                                          dwFilteredByStatus,
  DWORD                                          dwProfileFilter,
  WORD                                           wFlags,
  __out  DWORD*                                  pdwNumRules,
  __deref_out_ecount_opt(*pdwNumRules) FW_RULE** ppRules
);