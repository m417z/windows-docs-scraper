HRESULT AddPortMapping(
  [in]  BSTR                   bstrName,
  [in]  UCHAR                  ucIPProtocol,
  [in]  USHORT                 usExternalPort,
  [in]  USHORT                 usInternalPort,
  [in]  DWORD                  dwOptions,
  [in]  BSTR                   bstrTargetNameOrIPAddress,
  [in]  ICS_TARGETTYPE         eTargetType,
  [out] INetSharingPortMapping **ppMapping
);