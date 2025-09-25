typedef struct DD_MOTIONCOMPCALLBACKS {
  DWORD                        dwSize;
  DWORD                        dwFlags;
  PDD_MOCOMPCB_GETGUIDS        GetMoCompGuids;
  PDD_MOCOMPCB_GETFORMATS      GetMoCompFormats;
  PDD_MOCOMPCB_CREATE          CreateMoComp;
  PDD_MOCOMPCB_GETCOMPBUFFINFO GetMoCompBuffInfo;
  PDD_MOCOMPCB_GETINTERNALINFO GetInternalMoCompInfo;
  PDD_MOCOMPCB_BEGINFRAME      BeginMoCompFrame;
  PDD_MOCOMPCB_ENDFRAME        EndMoCompFrame;
  PDD_MOCOMPCB_RENDER          RenderMoComp;
  PDD_MOCOMPCB_QUERYSTATUS     QueryMoCompStatus;
  PDD_MOCOMPCB_DESTROY         DestroyMoComp;
} DD_MOTIONCOMPCALLBACKS;