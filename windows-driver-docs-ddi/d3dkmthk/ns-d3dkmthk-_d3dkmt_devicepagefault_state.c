typedef struct _D3DKMT_DEVICEPAGEFAULT_STATE {
  D3DKMT_ALIGN64 UINT64                 FaultedPrimitiveAPISequenceNumber;
  DXGK_RENDER_PIPELINE_STAGE            FaultedPipelineStage;
  UINT                                  FaultedBindTableEntry;
  DXGK_PAGE_FAULT_FLAGS                 PageFaultFlags;
  DXGK_FAULT_ERROR_CODE                 FaultErrorCode;
  D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS FaultedVirtualAddress;
} D3DKMT_DEVICEPAGEFAULT_STATE;