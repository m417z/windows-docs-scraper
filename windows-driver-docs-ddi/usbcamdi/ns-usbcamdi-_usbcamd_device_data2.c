typedef struct _USBCAMD_DEVICE_DATA2 {
  ULONG                             Sig;
  PCAM_INITIALIZE_ROUTINE           CamInitialize;
  PCAM_INITIALIZE_ROUTINE           CamUnInitialize;
  PCAM_PROCESS_PACKET_ROUTINE_EX    CamProcessUSBPacketEx;
  PCAM_NEW_FRAME_ROUTINE_EX         CamNewVideoFrameEx;
  PCAM_PROCESS_RAW_FRAME_ROUTINE_EX CamProcessRawVideoFrameEx;
  PCAM_START_CAPTURE_ROUTINE_EX     CamStartCaptureEx;
  PCAM_STOP_CAPTURE_ROUTINE_EX      CamStopCaptureEx;
  PCAM_CONFIGURE_ROUTINE_EX         CamConfigureEx;
  PCAM_STATE_ROUTINE                CamSaveState;
  PCAM_STATE_ROUTINE                CamRestoreState;
  PCAM_ALLOCATE_BW_ROUTINE_EX       CamAllocateBandwidthEx;
  PCAM_FREE_BW_ROUTINE_EX           CamFreeBandwidthEx;
} USBCAMD_DEVICE_DATA2, *PUSBCAMD_DEVICE_DATA2;