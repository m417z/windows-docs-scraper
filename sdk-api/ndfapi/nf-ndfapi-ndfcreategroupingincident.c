HRESULT NdfCreateGroupingIncident(
  [in, optional] LPCWSTR             CloudName,
  [in, optional] LPCWSTR             GroupName,
  [in, optional] LPCWSTR             Identity,
  [in, optional] LPCWSTR             Invitation,
  [in, optional] SOCKET_ADDRESS_LIST *Addresses,
  [in, optional] LPCWSTR             appId,
  [out]          NDFHANDLE           *handle
);