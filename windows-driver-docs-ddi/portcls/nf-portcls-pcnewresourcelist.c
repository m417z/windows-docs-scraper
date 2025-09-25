PORTCLASSAPI NTSTATUS PcNewResourceList(
  [out]          PRESOURCELIST     *OutResourceList,
  [in, optional] PUNKNOWN          OuterUnknown,
  [in]           POOL_TYPE         PoolType,
  [in]           PCM_RESOURCE_LIST TranslatedResources,
  [in]           PCM_RESOURCE_LIST UntranslatedResources
);