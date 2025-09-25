HRESULT WinBioEnumEnrollments(
  [in]            WINBIO_SESSION_HANDLE    SessionHandle,
  [in]            WINBIO_UNIT_ID           UnitId,
  [in]            WINBIO_IDENTITY          *Identity,
                  WINBIO_BIOMETRIC_SUBTYPE **SubFactorArray,
  [out, optional] SIZE_T                   *SubFactorCount
);