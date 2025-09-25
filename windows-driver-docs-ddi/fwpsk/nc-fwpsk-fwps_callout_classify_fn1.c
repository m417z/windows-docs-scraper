FWPS_CALLOUT_CLASSIFY_FN1 FwpsCalloutClassifyFn1;

void FwpsCalloutClassifyFn1(
  [in]           const FWPS_INCOMING_VALUES0 *inFixedValues,
  [in]           const FWPS_INCOMING_METADATA_VALUES0 *inMetaValues,
  [in, out]      void *layerData,
  [in, optional] const void *classifyContext,
  [in]           const FWPS_FILTER1 *filter,
  [in]           UINT64 flowContext,
  [in, out]      FWPS_CLASSIFY_OUT0 *classifyOut
)
{...}