PIBIO_ENGINE_SET_ACCOUNT_POLICY_FN PibioEngineSetAccountPolicyFn;

HRESULT PibioEngineSetAccountPolicyFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      PWINBIO_ACCOUNT_POLICY PolicyItemArray,
  [in]      SIZE_T PolicyItemCount
)
{...}