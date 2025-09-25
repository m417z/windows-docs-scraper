typedef struct _D3DKMT_CREATEKEYEDMUTEX2_FLAGS {
  union {
    struct {
      UINT NtSecuritySharing : 1;
      UINT Reserved : 31;
    };
    [in] UINT Value;
  };
} D3DKMT_CREATEKEYEDMUTEX2_FLAGS;