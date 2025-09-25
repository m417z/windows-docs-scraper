typedef struct _KSPIN_DISPATCH {
  PFNKSPINIRP                Create;
  PFNKSPINIRP                Close;
  PFNKSPIN                   Process;
  PFNKSPINVOID               Reset;
  PFNKSPINSETDATAFORMAT      SetDataFormat;
  PFNKSPINSETDEVICESTATE     SetDeviceState;
  PFNKSPIN                   Connect;
  PFNKSPINVOID               Disconnect;
  const KSCLOCK_DISPATCH     *Clock;
  const KSALLOCATOR_DISPATCH *Allocator;
} KSPIN_DISPATCH, *PKSPIN_DISPATCH;