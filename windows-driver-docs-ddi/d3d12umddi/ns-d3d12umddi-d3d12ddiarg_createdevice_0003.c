typedef struct D3D12DDIARG_CREATEDEVICE_0003 {
  [in] D3D12DDI_HRTDEVICE           hRTDevice;
  [in] UINT                         Interface;
  [in] UINT                         Version;
       const D3DDDI_DEVICECALLBACKS *pKTCallbacks;
       D3D12DDI_HDEVICE             hDrvDevice;
  union {
         const D3D12DDI_CORELAYER_DEVICECALLBACKS_0003 *p12UMCallbacks;
         const D3D12DDI_CORELAYER_DEVICECALLBACKS_0022 *p12UMCallbacks_0022;
         const D3D12DDI_CORELAYER_DEVICECALLBACKS_0050 *p12UMCallbacks_0050;
         const D3D12DDI_CORELAYER_DEVICECALLBACKS_0062 *p12UMCallbacks_0062;
  };
       D3D12DDI_CREATE_DEVICE_FLAGS Flags;
} D3D12DDIARG_CREATEDEVICE_0003;