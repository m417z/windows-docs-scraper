HRESULT WinBioIdentify(
  [in]            WINBIO_SESSION_HANDLE    SessionHandle,
  [out, optional] WINBIO_UNIT_ID           *UnitId,
  [out, optional] WINBIO_IDENTITY          *Identity,
  [out, optional] WINBIO_BIOMETRIC_SUBTYPE *SubFactor,
  [out, optional] WINBIO_REJECT_DETAIL     *RejectDetail
);