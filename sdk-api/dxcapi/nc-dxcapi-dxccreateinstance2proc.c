DxcCreateInstance2Proc Dxccreateinstance2proc;

HRESULT Dxccreateinstance2proc(
  IMalloc *pMalloc,
  REFCLSID rclsid,
  REFIID riid,
  LPVOID *ppv
)
{...}