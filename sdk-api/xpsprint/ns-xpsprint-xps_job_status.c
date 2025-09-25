typedef struct __MIDL___MIDL_itf_xpsprint_0000_0000_0002 {
  UINT32             jobId;
  INT32              currentDocument;
  INT32              currentPage;
  INT32              currentPageTotal;
  XPS_JOB_COMPLETION completion;
  HRESULT            jobStatus;
} XPS_JOB_STATUS;