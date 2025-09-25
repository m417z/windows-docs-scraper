typedef struct _KSDEVICE_DISPATCH {
  PFNKSDEVICECREATE            Add;
  PFNKSDEVICEPNPSTART          Start;
  PFNKSDEVICE                  PostStart;
  PFNKSDEVICEIRP               QueryStop;
  PFNKSDEVICEIRPVOID           CancelStop;
  PFNKSDEVICEIRPVOID           Stop;
  PFNKSDEVICEIRP               QueryRemove;
  PFNKSDEVICEIRPVOID           CancelRemove;
  PFNKSDEVICEIRPVOID           Remove;
  PFNKSDEVICEQUERYCAPABILITIES QueryCapabilities;
  PFNKSDEVICEIRPVOID           SurpriseRemoval;
  PFNKSDEVICEQUERYPOWER        QueryPower;
  PFNKSDEVICESETPOWER          SetPower;
  PFNKSDEVICEIRP               QueryInterface;
} KSDEVICE_DISPATCH, *PKSDEVICE_DISPATCH;