typedef struct _LSA_TRANSLATED_SID {
  SID_NAME_USE Use;
  ULONG        RelativeId;
  LONG         DomainIndex;
} LSA_TRANSLATED_SID, *PLSA_TRANSLATED_SID;