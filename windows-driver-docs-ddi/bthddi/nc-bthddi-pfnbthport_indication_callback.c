PFNBTHPORT_INDICATION_CALLBACK PfnbthportIndicationCallback;

void PfnbthportIndicationCallback(
  [in] PVOID Context,
  [in] INDICATION_CODE Indication,
  [in] PINDICATION_PARAMETERS Parameters
)
{...}