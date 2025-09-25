typedef struct tagNapComponentRegistrationInfo {
  NapComponentId id;
  CountedString  friendlyName;
  CountedString  description;
  CountedString  version;
  CountedString  vendorName;
  CLSID          infoClsid;
  CLSID          configClsid;
  FILETIME       registrationDate;
  UINT32         componentType;
} NapComponentRegistrationInfo;