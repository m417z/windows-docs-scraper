HRESULT InstallResponse2(
  [in]           InstallResponseRestrictionFlags Restrictions,
  [in]           BSTR                            strResponse,
  [in]           EncodingType                    Encoding,
  [in, optional] BSTR                            strPassword,
  [in]           BSTR                            strEnrollmentPolicyServerUrl,
  [in]           BSTR                            strEnrollmentPolicyServerID,
  [in]           PolicyServerUrlFlags            EnrollmentPolicyServerFlags,
  [in]           X509EnrollmentAuthFlags         authFlags
);