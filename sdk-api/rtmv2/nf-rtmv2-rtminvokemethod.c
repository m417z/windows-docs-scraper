DWORD RtmInvokeMethod(
  [in]      RTM_ENTITY_HANDLE         RtmRegHandle,
  [in]      RTM_ENTITY_HANDLE         EntityHandle,
  [in]      PRTM_ENTITY_METHOD_INPUT  Input,
  [in, out] PUINT                     OutputSize,
  [out]     PRTM_ENTITY_METHOD_OUTPUT Output
);