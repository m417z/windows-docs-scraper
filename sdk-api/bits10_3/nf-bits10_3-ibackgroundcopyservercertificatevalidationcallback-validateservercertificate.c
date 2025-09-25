HRESULT ValidateServerCertificate(
  IBackgroundCopyJob  *job,
  IBackgroundCopyFile *file,
  DWORD               certLength,
  const BYTE []       certData,
  DWORD               certEncodingType,
  DWORD               certStoreLength,
  const BYTE []       certStoreData
);