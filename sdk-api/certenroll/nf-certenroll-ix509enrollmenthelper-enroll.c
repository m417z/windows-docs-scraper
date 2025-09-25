HRESULT Enroll(
  [in]          BSTR               strEnrollmentPolicyServerURI,
  [in]          BSTR               strTemplateName,
  [in]          EncodingType       Encoding,
  [in]          WebEnrollmentFlags enrollFlags,
  [out, retval] BSTR               *pstrCertificate
);