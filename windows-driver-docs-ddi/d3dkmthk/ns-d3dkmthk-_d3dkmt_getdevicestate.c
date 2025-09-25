typedef struct _D3DKMT_GETDEVICESTATE {
  [in]     D3DKMT_HANDLE           hDevice;
  [in]     D3DKMT_DEVICESTATE_TYPE StateType;
  union {
    [out]    D3DKMT_DEVICEEXECUTION_STATE     ExecutionState;
    [in/out] D3DKMT_DEVICEPRESENT_STATE       PresentState;
    [out]    D3DKMT_DEVICERESET_STATE         ResetState;
             D3DKMT_DEVICEPRESENT_STATE_DWM   PresentStateDWM;
             D3DKMT_DEVICEPAGEFAULT_STATE     PageFaultState;
             D3DKMT_DEVICEPRESENT_QUEUE_STATE PresentQueueState;
  };
} D3DKMT_GETDEVICESTATE;