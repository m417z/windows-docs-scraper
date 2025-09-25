typedef struct D3D12_VIDEO_ENCODER_RATE_CONTROL_CONFIGURATION_PARAMS {
  UINT  DataSize;
  union {
    const D3D12_VIDEO_ENCODER_RATE_CONTROL_CQP             *pConfiguration_CQP;
    const D3D12_VIDEO_ENCODER_RATE_CONTROL_CBR             *pConfiguration_CBR;
    const D3D12_VIDEO_ENCODER_RATE_CONTROL_VBR             *pConfiguration_VBR;
    const D3D12_VIDEO_ENCODER_RATE_CONTROL_QVBR            *pConfiguration_QVBR;
    const D3D12_VIDEO_ENCODER_RATE_CONTROL_CQP1            *pConfiguration_CQP1;
    const D3D12_VIDEO_ENCODER_RATE_CONTROL_CBR1            *pConfiguration_CBR1;
    const D3D12_VIDEO_ENCODER_RATE_CONTROL_VBR1            *pConfiguration_VBR1;
    const D3D12_VIDEO_ENCODER_RATE_CONTROL_QVBR1           *pConfiguration_QVBR1;
    const D3D12_VIDEO_ENCODER_RATE_CONTROL_ABSOLUTE_QP_MAP *pConfiguration_AbsoluteQPMap;
  };
} D3D12_VIDEO_ENCODER_RATE_CONTROL_CONFIGURATION_PARAMS;