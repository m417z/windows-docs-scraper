HRESULT GetCAProperty(
  [in]          const BSTR strConfig,
  [in]          LONG       PropId,
  [in]          LONG       PropIndex,
  [in]          LONG       PropType,
  [in]          LONG       Flags,
  [out, retval] VARIANT    *pvarPropertyValue
);