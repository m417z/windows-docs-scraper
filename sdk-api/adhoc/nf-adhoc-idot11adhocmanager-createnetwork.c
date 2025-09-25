HRESULT CreateNetwork(
  [in]  LPCWSTR                     Name,
  [in]  LPCWSTR                     Password,
  [in]  LONG                        GeographicalId,
  [in]  IDot11AdHocInterface        *pInterface,
  [in]  IDot11AdHocSecuritySettings *pSecurity,
  [in]  GUID                        *pContextGuid,
  [out] IDot11AdHocNetwork          **pIAdHoc
);