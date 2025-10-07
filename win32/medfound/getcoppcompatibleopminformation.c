NTSTATUS WINAPI GetCOPPCompatibleOPMInformation(
  _In_  OPM_PROTECTED_OUTPUT_HANDLE                     opoOPMProtectedOutput,
  _In_  DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS *pParameters,
  _Out_ DXGKMDT_OPM_REQUESTED_INFORMATION               *pRequestedInformation
);