HRESULT Unmarshal(
  [in]  ULONG                    iMethod,
  [in]  PVOID                    pBuffer,
  [in]  ULONG                    cbBuffer,
  [in]  BOOL                     fForceBufferCopy,
  [in]  RPCOLEDATAREP            dataRep,
  [in]  CALLFRAME_MARSHALCONTEXT *pcontext,
  [out] ULONG                    *pcbUnmarshalled,
  [out] ICallFrame               **ppFrame
);