typedef struct _DRM_LICENSE_ACQ_DATA {
  UINT  uVersion;
  PWSTR wszURL;
  PWSTR wszLocalFilename;
  BYTE  *pbPostData;
  DWORD dwPostDataSize;
  PWSTR wszFriendlyName;
  void  _DRM_LICENSE_ACQ_DATA();
} DRM_LICENSE_ACQ_DATA;