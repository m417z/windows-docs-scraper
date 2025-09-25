PFND3D11DDI_SETRENDERTARGETS Pfnd3d11ddiSetrendertargets;

VOID Pfnd3d11ddiSetrendertargets(
  [in] D3D10DDI_HDEVICE unnamedParam1,
  [in] const D3D10DDI_HRENDERTARGETVIEW *unnamedParam2,
  [in] UINT NumRTVs,
  [in] UINT ClearSlots,
  [in] D3D10DDI_HDEPTHSTENCILVIEW unnamedParam5,
  [in] const D3D11DDI_HUNORDEREDACCESSVIEW *unnamedParam6,
  [in] const UINT *unnamedParam7,
       UINT UAVStartSlot,
  [in] UINT NumUAVs,
  [in] UINT UAVRangeStart,
  [in] UINT UAVRangeSize
)
{...}