typedef struct _D3DDDI_ALLOCATIONLIST {
  D3DKMT_HANDLE hAllocation;
  union {
    struct {
      UINT WriteOperation : 1;
      UINT DoNotRetireInstance : 1;
      UINT OfferPriority : 3;
#if ...
      UINT Reserved : 27;
#else
      UINT Reserved : 30;
#endif
    };
    UINT Value;
  };
} D3DDDI_ALLOCATIONLIST;