typedef enum _WDF_SPECIAL_FILE_TYPE {
  WdfSpecialFileUndefined,
  WdfSpecialFilePaging,
  WdfSpecialFileHibernation,
  WdfSpecialFileDump,
  WdfSpecialFileBoot,
  WdfSpecialFilePostDisplay,
  WdfSpecialFileGuestAssigned,
  WdfSpecialFileInlineCryptoEngine,
  WdfSpecialFileMax
} WDF_SPECIAL_FILE_TYPE, *PWDF_SPECIAL_FILE_TYPE;