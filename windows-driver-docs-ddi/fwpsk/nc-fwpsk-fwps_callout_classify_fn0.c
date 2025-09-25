FWPS_CALLOUT_CLASSIFY_FN0 FwpsCalloutClassifyFn0;

void FwpsCalloutClassifyFn0(
  [in]      const FWPS_INCOMING_VALUES0 *inFixedValues,
  [in]      const FWPS_INCOMING_METADATA_VALUES0 *inMetaValues,
  [in, out] void *layerData,
  [in]      const FWPS_FILTER0 *filter,
  [in]      UINT64 flowContext,
  [in, out] FWPS_CLASSIFY_OUT0 *classifyOut
)
{...}