typedef struct _LSA_DISPATCH_TABLE {
  PLSA_CREATE_LOGON_SESSION    CreateLogonSession;
  PLSA_DELETE_LOGON_SESSION    DeleteLogonSession;
  PLSA_ADD_CREDENTIAL          AddCredential;
  PLSA_GET_CREDENTIALS         GetCredentials;
  PLSA_DELETE_CREDENTIAL       DeleteCredential;
  PLSA_ALLOCATE_LSA_HEAP       AllocateLsaHeap;
  PLSA_FREE_LSA_HEAP           FreeLsaHeap;
  PLSA_ALLOCATE_CLIENT_BUFFER  AllocateClientBuffer;
  PLSA_FREE_CLIENT_BUFFER      FreeClientBuffer;
  PLSA_COPY_TO_CLIENT_BUFFER   CopyToClientBuffer;
  PLSA_COPY_FROM_CLIENT_BUFFER CopyFromClientBuffer;
} LSA_DISPATCH_TABLE, *PLSA_DISPATCH_TABLE;