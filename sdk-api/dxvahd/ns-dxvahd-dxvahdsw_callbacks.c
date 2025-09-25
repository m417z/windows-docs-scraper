typedef struct _DXVAHDSW_CALLBACKS {
  PDXVAHDSW_CreateDevice                      CreateDevice;
  PDXVAHDSW_ProposeVideoPrivateFormat         ProposeVideoPrivateFormat;
  PDXVAHDSW_GetVideoProcessorDeviceCaps       GetVideoProcessorDeviceCaps;
  PDXVAHDSW_GetVideoProcessorOutputFormats    GetVideoProcessorOutputFormats;
  PDXVAHDSW_GetVideoProcessorInputFormats     GetVideoProcessorInputFormats;
  PDXVAHDSW_GetVideoProcessorCaps             GetVideoProcessorCaps;
  PDXVAHDSW_GetVideoProcessorCustomRates      GetVideoProcessorCustomRates;
  PDXVAHDSW_GetVideoProcessorFilterRange      GetVideoProcessorFilterRange;
  PDXVAHDSW_DestroyDevice                     DestroyDevice;
  PDXVAHDSW_CreateVideoProcessor              CreateVideoProcessor;
  PDXVAHDSW_SetVideoProcessBltState           SetVideoProcessBltState;
  PDXVAHDSW_GetVideoProcessBltStatePrivate    GetVideoProcessBltStatePrivate;
  PDXVAHDSW_SetVideoProcessStreamState        SetVideoProcessStreamState;
  PDXVAHDSW_GetVideoProcessStreamStatePrivate GetVideoProcessStreamStatePrivate;
  PDXVAHDSW_VideoProcessBltHD                 VideoProcessBltHD;
  PDXVAHDSW_DestroyVideoProcessor             DestroyVideoProcessor;
} DXVAHDSW_CALLBACKS;