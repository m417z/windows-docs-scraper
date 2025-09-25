typedef struct _IRB_REQ_BUS_RESET_NOTIFICATION {
  ULONG                       fulFlags;
  PBUS_BUS_RESET_NOTIFICATION ResetRoutine;
  PVOID                       ResetContext;
} IRB_REQ_BUS_RESET_NOTIFICATION;