HRESULT GetSubscriptions(
  [in]          REFIID                 eventIID,
  [in]          BSTR                   bstrMethodName,
  [in]          BSTR                   optionalCriteria,
  [in]          int                    *optionalErrorIndex,
  [out, retval] IEventObjectCollection **ppCollection
);