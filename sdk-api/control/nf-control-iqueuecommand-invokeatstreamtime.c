HRESULT InvokeAtStreamTime(
  [out]     IDeferredCommand **pCmd,
  [in]      REFTIME          time,
  [in]      GUID             *iid,
  [in]      long             dispidMethod,
  [in]      short            wFlags,
  [in]      long             cArgs,
  [in]      VARIANT          *pDispParams,
  [in, out] VARIANT          *pvarResult,
  [out]     short            *puArgErr
);