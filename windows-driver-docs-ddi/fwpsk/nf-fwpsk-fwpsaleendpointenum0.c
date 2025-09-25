NTSTATUS FwpsAleEndpointEnum0(
  [in]  HANDLE                        engineHandle,
  [in]  HANDLE                        enumHandle,
  [in]  UINT32                        numEntriesRequested,
  [out] FWPS_ALE_ENDPOINT_PROPERTIES0 ***entries,
  [out] UINT32                        *numEntriesReturned
);