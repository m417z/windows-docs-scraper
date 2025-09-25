TDHSTATUS TdhAggregatePayloadFilters(
                 ULONG                    PayloadFilterCount,
                 PVOID                    *PayloadFilterPtrs,
  [in, optional] PBOOLEAN                 EventMatchALLFlags,
  [out]          PEVENT_FILTER_DESCRIPTOR EventFilterDescriptor
);