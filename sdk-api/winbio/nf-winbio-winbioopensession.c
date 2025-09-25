HRESULT WinBioOpenSession(
  [in]  WINBIO_BIOMETRIC_TYPE Factor,
  [in]  WINBIO_POOL_TYPE      PoolType,
  [in]  WINBIO_SESSION_FLAGS  Flags,
  [in]  WINBIO_UNIT_ID        *UnitArray,
  [in]  SIZE_T                UnitCount,
  [in]  GUID                  *DatabaseId,
  [out] WINBIO_SESSION_HANDLE *SessionHandle
);