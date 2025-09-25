typedef struct __MIDL___MIDL_itf_documenttarget_0000_0002_0001 {
  UINT32                         JobId;
  INT32                          CurrentDocument;
  INT32                          CurrentPage;
  INT32                          CurrentPageTotal;
  PrintDocumentPackageCompletion Completion;
  HRESULT                        PackageStatus;
} PrintDocumentPackageStatus;