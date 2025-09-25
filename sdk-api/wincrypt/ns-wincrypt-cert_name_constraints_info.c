typedef struct _CERT_NAME_CONSTRAINTS_INFO {
  DWORD                 cPermittedSubtree;
  PCERT_GENERAL_SUBTREE rgPermittedSubtree;
  DWORD                 cExcludedSubtree;
  PCERT_GENERAL_SUBTREE rgExcludedSubtree;
} CERT_NAME_CONSTRAINTS_INFO, *PCERT_NAME_CONSTRAINTS_INFO;