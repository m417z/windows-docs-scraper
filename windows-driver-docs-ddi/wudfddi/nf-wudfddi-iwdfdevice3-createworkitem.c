HRESULT CreateWorkItem(
  [in]           PWUDF_WORKITEM_CONFIG pConfig,
  [in, optional] IWDFObject            *pParentObject,
  [out]          IWDFWorkItem          **ppWorkItem
);