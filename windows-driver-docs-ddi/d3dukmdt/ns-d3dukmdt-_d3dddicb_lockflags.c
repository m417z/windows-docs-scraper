typedef struct _D3DDDICB_LOCKFLAGS {
  union {
    struct {
      UINT ReadOnly : 1;
      UINT WriteOnly : 1;
      UINT DonotWait : 1;
      UINT IgnoreSync : 1;
      UINT LockEntire : 1;
      UINT DonotEvict : 1;
      UINT AcquireAperture : 1;
      UINT Discard : 1;
      UINT NoExistingReference : 1;
      UINT UseAlternateVA : 1;
      UINT IgnoreReadSync : 1;
      UINT Reserved : 21;
    };
    UINT Value;
  };
} D3DDDICB_LOCKFLAGS;