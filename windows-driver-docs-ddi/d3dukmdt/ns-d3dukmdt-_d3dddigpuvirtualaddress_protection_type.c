typedef struct _D3DDDIGPUVIRTUALADDRESS_PROTECTION_TYPE {
  union {
    struct {
      UINT64 Write : 1;
      UINT64 Execute : 1;
      UINT64 Zero : 1;
      UINT64 NoAccess : 1;
      UINT64 SystemUseOnly : 1;
      UINT64 Reserved : 59;
    };
    D3DKMT_ALIGN64 UINT64 Value;
  };
} D3DDDIGPUVIRTUALADDRESS_PROTECTION_TYPE;