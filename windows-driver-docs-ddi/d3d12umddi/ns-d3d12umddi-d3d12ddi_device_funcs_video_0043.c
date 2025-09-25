typedef struct D3D12DDI_DEVICE_FUNCS_VIDEO_0043
{
    PFND3D12DDI_VIDEO_GETCAPS                                           pfnGetCaps;
    PFND3D12DDI_CALCPRIVATEVIDEODECODERSIZE_0032                        pfnCalcPrivateVideoDecoderSize;
    PFND3D12DDI_CREATEVIDEODECODER_0032                                 pfnCreateVideoDecoder;
    PFND3D12DDI_DESTROYVIDEODECODER_0021                                pfnDestroyVideoDecoder;
    PFND3D12DDI_CALCPRIVATEVIDEODECODERHEAPSIZE_0033                    pfnCalcPrivateVideoDecoderHeapSize;
    PFND3D12DDI_CREATEVIDEODECODERHEAP_0033                             pfnCreateVideoDecoderHeap;
    PFND3D12DDI_DESTROYVIDEODECODERHEAP_0032                            pfnDestroyVideoDecoderHeap;
    PFND3D12DDI_CALCPRIVATEVIDEOPROCESSORSIZE_0043                      pfnCalcPrivateVideoProcessorSize;
    PFND3D12DDI_CREATEVIDEOPROCESSOR_0043                               pfnCreateVideoProcessor;
    PFND3D12DDI_DESTROYVIDEOPROCESSOR_0021                              pfnDestroyVideoProcessor;
} D3D12DDI_DEVICE_FUNCS_VIDEO_0043;