HRESULT HRESULT MrmCreateResourceIndexerFromPreviousPriFile(
  _In_     PCWSTR                   projectRoot,
  _In_     MrmPlatformVersion       platformVersion,
  _In_opt_ PCWSTR                   defaultQualifiers,
  _In_     PCWSTR                   priFile,
  _Inout_  MrmResourceIndexerHandle *indexer
);