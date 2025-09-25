PFNSCO_INDICATION_CALLBACK PfnscoIndicationCallback;

void PfnscoIndicationCallback(
  [in] PVOID Context,
  [in] SCO_INDICATION_CODE Indication,
  [in] PSCO_INDICATION_PARAMETERS Parameters
)
{...}