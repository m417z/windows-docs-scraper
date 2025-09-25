HRESULT AddEntry(
  [in]           BSTR         bstrSource,
  [in]           GPMEntryType gpmEntryType,
  [in, optional] VARIANT      *pvarDestination,
  [out]          IGPMMapEntry **ppEntry
);