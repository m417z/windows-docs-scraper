HRESULT FindAttribute(
  [in]          TEXTATTRIBUTEID    attributeId,
  [in]          VARIANT            val,
  [in]          BOOL               backward,
  [out, retval] ITextRangeProvider **pRetVal
);