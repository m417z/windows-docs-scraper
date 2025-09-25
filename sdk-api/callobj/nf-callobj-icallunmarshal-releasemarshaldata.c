HRESULT ReleaseMarshalData(
  [in] ULONG                    iMethod,
  [in] PVOID                    pBuffer,
  [in] ULONG                    cbBuffer,
  [in] ULONG                    ibFirstRelease,
  [in] RPCOLEDATAREP            dataRep,
  [in] CALLFRAME_MARSHALCONTEXT *pcontext
);