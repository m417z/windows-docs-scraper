FWPS_CALLOUT_CLASSIFY_FN2 FwpsCalloutClassifyFn2;

void FwpsCalloutClassifyFn2(
  [in]                const FWPS_INCOMING_VALUES0 *inFixedValues,
  [in]                const FWPS_INCOMING_METADATA_VALUES0 *inMetaValues,
  [in, out, optional] void *layerData,
  [in, optional]      const void *classifyContext,
  [in]                const FWPS_FILTER2 *filter,
  [in]                UINT64 flowContext,
  [in, out]           FWPS_CLASSIFY_OUT0 *classifyOut
)
{...}