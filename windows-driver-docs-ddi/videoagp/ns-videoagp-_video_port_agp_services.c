typedef struct _VIDEO_PORT_AGP_SERVICES {
  PAGP_RESERVE_PHYSICAL AgpReservePhysical;
  PAGP_RELEASE_PHYSICAL AgpReleasePhysical;
  PAGP_COMMIT_PHYSICAL  AgpCommitPhysical;
  PAGP_FREE_PHYSICAL    AgpFreePhysical;
  PAGP_RESERVE_VIRTUAL  AgpReserveVirtual;
  PAGP_RELEASE_VIRTUAL  AgpReleaseVirtual;
  PAGP_COMMIT_VIRTUAL   AgpCommitVirtual;
  PAGP_FREE_VIRTUAL     AgpFreeVirtual;
  ULONGLONG             AllocationLimit;
} VIDEO_PORT_AGP_SERVICES, *PVIDEO_PORT_AGP_SERVICES;