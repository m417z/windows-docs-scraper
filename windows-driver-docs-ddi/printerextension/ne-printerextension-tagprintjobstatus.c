typedef enum tagPrintJobStatus {
  PrintJobStatus_Paused,
  PrintJobStatus_Error,
  PrintJobStatus_Deleting,
  PrintJobStatus_Spooling,
  PrintJobStatus_Printing,
  PrintJobStatus_Offline,
  PrintJobStatus_PaperOut,
  PrintJobStatus_Printed,
  PrintJobStatus_Deleted,
  PrintJobStatus_BlockedDeviceQueue,
  PrintJobStatus_UserIntervention,
  PrintJobStatus_Restarted,
  PrintJobStatus_Complete,
  PrintJobStatus_Retained
} PrintJobStatus;