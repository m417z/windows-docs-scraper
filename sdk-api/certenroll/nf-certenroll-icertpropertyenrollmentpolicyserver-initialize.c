HRESULT Initialize(
  [in] EnrollmentPolicyServerPropertyFlags PropertyFlags,
  [in] X509EnrollmentAuthFlags             AuthFlags,
  [in] X509EnrollmentAuthFlags             EnrollmentServerAuthFlags,
  [in] PolicyServerUrlFlags                UrlFlags,
  [in] BSTR                                strRequestId,
  [in] BSTR                                strUrl,
  [in] BSTR                                strId,
  [in] BSTR                                strEnrollmentServerUrl
);