typedef struct _WUDF_WORKITEM_CONFIG {
  ULONG             Size;
  PFN_WUDF_WORKITEM OnWorkItemFunc;
  BOOLEAN           AutomaticSerialization;
} WUDF_WORKITEM_CONFIG, *PWUDF_WORKITEM_CONFIG;