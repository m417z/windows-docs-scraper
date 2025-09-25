typedef struct _ACX_RT_STREAM_CALLBACKS {
  ULONG                                    Size;
  PFN_ACX_STREAM_GET_HW_LATENCY            EvtAcxStreamGetHwLatency;
  PFN_ACX_STREAM_ALLOCATE_RTPACKETS        EvtAcxStreamAllocateRtPackets;
  PFN_ACX_STREAM_FREE_RTPACKETS            EvtAcxStreamFreeRtPackets;
  PFN_ACX_STREAM_SET_RENDER_PACKET         EvtAcxStreamSetRenderPacket;
  PFN_ACX_STREAM_GET_CURRENT_PACKET        EvtAcxStreamGetCurrentPacket;
  PFN_ACX_STREAM_GET_CAPTURE_PACKET        EvtAcxStreamGetCapturePacket;
  PFN_ACX_STREAM_GET_PRESENTATION_POSITION EvtAcxStreamGetPresentationPosition;
} ACX_RT_STREAM_CALLBACKS, *PACX_RT_STREAM_CALLBACKS;