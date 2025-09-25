HRESULT ImportTemplates(
  [in]  BSTR                       serializedQuotaTemplates,
  [in]  VARIANT                    *quotaTemplateNamesArray,
  [out] IFsrmCommittableCollection **quotaTemplates
);