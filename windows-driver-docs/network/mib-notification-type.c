typedef enum _MIB_NOTIFICATION_TYPE { 
  MibParameterNotification  = 0,
  MibAddInstance            = 1,
  MibDeleteInstance         = 2,
  MibInitialNotification    = 3
} MIB_NOTIFICATION_TYPE, *PMIB_NOTIFICATION_TYPE;