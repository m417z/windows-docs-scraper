HRESULT WinBioVerify(
  [in]            WINBIO_SESSION_HANDLE    SessionHandle,
  [in]            WINBIO_IDENTITY          *Identity,
  [in]            WINBIO_BIOMETRIC_SUBTYPE SubFactor,
  [out, optional] WINBIO_UNIT_ID           *UnitId,
  [out, optional] BOOLEAN                  *Match,
  [out, optional] WINBIO_REJECT_DETAIL     *RejectDetail
);