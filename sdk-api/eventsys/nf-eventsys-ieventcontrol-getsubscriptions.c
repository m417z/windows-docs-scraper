HRESULT GetSubscriptions(
  [in]          BSTR                   methodName,
  [in]          BSTR                   optionalCriteria,
  [in]          int                    *optionalErrorIndex,
  [out, retval] IEventObjectCollection **ppCollection
);