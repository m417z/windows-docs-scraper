typedef enum _MIB_NOTIFICATION_TYPE {
  MibParameterNotification,
  MibAddInstance,
  MibDeleteInstance,
  MibInitialNotification
} MIB_NOTIFICATION_TYPE, *PMIB_NOTIFICATION_TYPE;