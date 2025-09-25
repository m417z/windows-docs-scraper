typedef struct DXGI_DDI_ARG_BLT {
  [in] DXGI_DDI_HDEVICE       hDevice;
  [in] DXGI_DDI_HRESOURCE     hDstResource;
  [in] UINT                   DstSubresource;
  [in] UINT                   DstLeft;
  [in] UINT                   DstTop;
  [in] UINT                   DstRight;
  [in] UINT                   DstBottom;
  [in] DXGI_DDI_HRESOURCE     hSrcResource;
  [in] UINT                   SrcSubresource;
  [in] DXGI_DDI_ARG_BLT_FLAGS Flags;
  [in] DXGI_DDI_MODE_ROTATION Rotate;
} DXGI_DDI_ARG_BLT;