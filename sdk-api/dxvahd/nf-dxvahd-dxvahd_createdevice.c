HRESULT DXVAHD_CreateDevice(
  [in]  IDirect3DDevice9Ex        *pD3DDevice,
  [in]  const DXVAHD_CONTENT_DESC *pContentDesc,
  [in]  DXVAHD_DEVICE_USAGE       Usage,
  [in]  PDXVAHDSW_Plugin          pPlugin,
  [out] IDXVAHD_Device            **ppDevice
);