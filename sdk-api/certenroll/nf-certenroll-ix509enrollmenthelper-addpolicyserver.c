HRESULT AddPolicyServer(
  [in] BSTR                    strEnrollmentPolicyServerURI,
  [in] BSTR                    strEnrollmentPolicyID,
  [in] PolicyServerUrlFlags    EnrollmentPolicyServerFlags,
  [in] X509EnrollmentAuthFlags authFlags,
  [in] BSTR                    strCredential,
  [in] BSTR                    strPassword
);