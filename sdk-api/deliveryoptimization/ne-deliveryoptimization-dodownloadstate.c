typedef enum _DODownloadState {
  DODownloadState_Created,
  DODownloadState_Transferring,
  DODownloadState_Transferred,
  DODownloadState_Finalized,
  DODownloadState_Aborted,
  DODownloadState_Paused
} DODownloadState;