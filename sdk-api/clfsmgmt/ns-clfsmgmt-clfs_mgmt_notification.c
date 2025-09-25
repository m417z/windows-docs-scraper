typedef struct _CLFS_MGMT_NOTIFICATION {
  CLFS_MGMT_NOTIFICATION_TYPE Notification;
  CLFS_LSN                    Lsn;
  USHORT                      LogIsPinned;
} CLFS_MGMT_NOTIFICATION, *PCLFS_MGMT_NOTIFICATION;