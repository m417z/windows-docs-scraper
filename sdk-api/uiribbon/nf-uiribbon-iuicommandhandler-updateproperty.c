HRESULT UpdateProperty(
  [in]           UINT32            commandId,
  [in]           REFPROPERTYKEY    key,
  [in, optional] const PROPVARIANT *currentValue,
  [out]          PROPVARIANT       *newValue
);