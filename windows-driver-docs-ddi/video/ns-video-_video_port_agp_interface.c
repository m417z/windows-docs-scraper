typedef struct _VIDEO_PORT_AGP_INTERFACE {
  IN USHORT                  Size;
  IN USHORT                  Version;
  OUT PVOID                  Context;
  OUT PINTERFACE_REFERENCE   InterfaceReference;
  OUT PINTERFACE_DEREFERENCE InterfaceDereference;
  OUT PAGP_RESERVE_PHYSICAL  AgpReservePhysical;
  OUT PAGP_RELEASE_PHYSICAL  AgpReleasePhysical;
  OUT PAGP_COMMIT_PHYSICAL   AgpCommitPhysical;
  OUT PAGP_FREE_PHYSICAL     AgpFreePhysical;
  OUT PAGP_RESERVE_VIRTUAL   AgpReserveVirtual;
  OUT PAGP_RELEASE_VIRTUAL   AgpReleaseVirtual;
  OUT PAGP_COMMIT_VIRTUAL    AgpCommitVirtual;
  OUT PAGP_FREE_VIRTUAL      AgpFreeVirtual;
  OUT ULONGLONG              AgpAllocationLimit;
} VIDEO_PORT_AGP_INTERFACE, *PVIDEO_PORT_AGP_INTERFACE;