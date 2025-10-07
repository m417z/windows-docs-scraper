HRESULT WINAPI SignerTimeStamp(
  _In_     SIGNER_SUBJECT_INFO *pSubjectInfo,
  _In_     LPCWSTR             pwszHttpTimeStamp,
  _In_opt_ PCRYPT_ATTRIBUTES   psRequest,
  _In_opt_ LPVOID              pSipData
);