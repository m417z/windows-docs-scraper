HRESULT CreateRemoteDictionaryResourceFromStream(
  [in]          IStream                        *dictionaryMarkupStream,
  [in]          IOpcPartUri                    *dictionaryPartUri,
  [in]          IXpsOMPartResources            *resources,
  [out, retval] IXpsOMRemoteDictionaryResource **dictionaryResource
);