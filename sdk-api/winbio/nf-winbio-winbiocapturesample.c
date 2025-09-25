HRESULT WinBioCaptureSample(
  [in]            WINBIO_SESSION_HANDLE SessionHandle,
  [in]            WINBIO_BIR_PURPOSE    Purpose,
  [in]            WINBIO_BIR_DATA_FLAGS Flags,
  [out, optional] WINBIO_UNIT_ID        *UnitId,
                  PWINBIO_BIR           *Sample,
  [out, optional] SIZE_T                *SampleSize,
  [out, optional] WINBIO_REJECT_DETAIL  *RejectDetail
);