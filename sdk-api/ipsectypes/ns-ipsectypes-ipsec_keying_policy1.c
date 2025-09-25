typedef struct IPSEC_KEYING_POLICY1_ {
  UINT32 numKeyMods;
  GUID   *keyModKeys;
  UINT32 flags;
} IPSEC_KEYING_POLICY1;