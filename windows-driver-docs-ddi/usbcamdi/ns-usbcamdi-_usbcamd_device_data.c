typedef struct _USBCAMD_DEVICE_DATA {
  ULONG                          Sig;
  PCAM_INITIALIZE_ROUTINE        CamInitialize;
  PCAM_INITIALIZE_ROUTINE        CamUnInitialize;
  PCAM_PROCESS_PACKET_ROUTINE    CamProcessUSBPacket;
  PCAM_NEW_FRAME_ROUTINE         CamNewVideoFrame;
  PCAM_PROCESS_RAW_FRAME_ROUTINE CamProcessRawVideoFrame;
  PCAM_START_CAPTURE_ROUTINE     CamStartCapture;
  PCAM_STOP_CAPTURE_ROUTINE      CamStopCapture;
  PCAM_CONFIGURE_ROUTINE         CamConfigure;
  PCAM_STATE_ROUTINE             CamSaveState;
  PCAM_STATE_ROUTINE             CamRestoreState;
  PCAM_ALLOCATE_BW_ROUTINE       CamAllocateBandwidth;
  PCAM_FREE_BW_ROUTINE           CamFreeBandwidth;
} USBCAMD_DEVICE_DATA, *PUSBCAMD_DEVICE_DATA;