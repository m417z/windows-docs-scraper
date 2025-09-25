HRESULT Marshal(
  [in]  CALLFRAME_MARSHALCONTEXT *pmshlContext,
  [in]  MSHLFLAGS                mshlflags,
  [in]  PVOID                    pBuffer,
  [in]  ULONG                    cbBuffer,
  [out] ULONG                    *pcbBufferUsed,
  [out] RPCOLEDATAREP            *pdataRep,
  [out] ULONG                    *prpcFlags
);