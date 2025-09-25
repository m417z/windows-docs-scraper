PFNBTHPORT_INDICATION_CALLBACK_ENHANCED PfnbthportIndicationCallbackEnhanced;

void PfnbthportIndicationCallbackEnhanced(
  [in] PVOID Context,
  [in] INDICATION_CODE Indication,
  [in] PINDICATION_PARAMETERS_ENHANCED Parameters
)
{...}