HRESULT Unmarshal(
  [in]  PVOID                    pBuffer,
  [in]  ULONG                    cbBuffer,
  [in]  RPCOLEDATAREP            dataRep,
  [in]  CALLFRAME_MARSHALCONTEXT *pcontext,
  [out] ULONG                    *pcbUnmarshalled
);