PIBIO_ENGINE_QUERY_EXTENDED_ENROLLMENT_STATUS_FN PibioEngineQueryExtendedEnrollmentStatusFn;

HRESULT PibioEngineQueryExtendedEnrollmentStatusFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PWINBIO_EXTENDED_ENROLLMENT_STATUS EnrollmentStatus,
  [in]      SIZE_T EnrollmentStatusSize
)
{...}