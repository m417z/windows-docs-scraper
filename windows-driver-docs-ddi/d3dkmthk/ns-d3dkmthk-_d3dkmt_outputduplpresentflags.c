typedef struct _D3DKMT_OUTPUTDUPLPRESENTFLAGS {
  union {
    struct {
      UINT ProtectedContentBlankedOut : 1;
      UINT RemoteSession : 1;
      UINT FullScreenPresent : 1;
      UINT PresentIndirect : 1;
      UINT Reserved : 28;
    };
    UINT Value;
  };
} D3DKMT_OUTPUTDUPLPRESENTFLAGS;