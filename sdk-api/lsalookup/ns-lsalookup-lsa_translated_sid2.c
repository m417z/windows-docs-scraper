typedef struct _LSA_TRANSLATED_SID2 {
  SID_NAME_USE Use;
  PSID         Sid;
  LONG         DomainIndex;
  ULONG        Flags;
} LSA_TRANSLATED_SID2, *PLSA_TRANSLATED_SID2;