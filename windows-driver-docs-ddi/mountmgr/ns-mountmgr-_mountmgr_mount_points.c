typedef struct _MOUNTMGR_MOUNT_POINTS {
  ULONG                Size;
  ULONG                NumberOfMountPoints;
  MOUNTMGR_MOUNT_POINT MountPoints[1];
} MOUNTMGR_MOUNT_POINTS, *PMOUNTMGR_MOUNT_POINTS;