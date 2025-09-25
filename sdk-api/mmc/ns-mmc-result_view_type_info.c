typedef struct _RESULT_VIEW_TYPE_INFO {
  LPOLESTR      pstrPersistableViewDescription;
  MMC_VIEW_TYPE eViewType;
  DWORD         dwMiscOptions;
  union {
    DWORD dwListOptions;
    struct {
      DWORD    dwHTMLOptions;
      LPOLESTR pstrURL;
    };
    struct {
      DWORD     dwOCXOptions;
      LPUNKNOWN pUnkControl;
    };
  };
} RESULT_VIEW_TYPE_INFO, *PRESULT_VIEW_TYPE_INFO;